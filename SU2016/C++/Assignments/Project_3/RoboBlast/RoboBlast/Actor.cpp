 #include "Actor.h"
#include "StudentWorld.h"
#include <algorithm>

using namespace std;

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

Bully::Bully(int startX, int startY, int sub_level, StudentWorld* stdWorld)
: BadGuys(IID_BULLY,startX,startY,right,sub_level,stdWorld,5)
{
    m_goodies[IID_RESTORE_HEALTH]=0;
    m_goodies[IID_AMMO]=0;
    m_goodies[IID_EXTRA_LIFE]=0;
    setVisible(true);
    m_distanceBeforeTurning=rand()%BULLY_MAX_TURN_TICK+1;
    m_curDistance=0;
}
// Some general functions to drive things

void Actor::goDie()
{
    this->setVisible(false);
    setDead(true);
}

void MovingThings::moveTick()
{
    int dx=0,dy=0;
    switch (getDirection()) {
        case up:    dy=1;  break;
        case down:  dy=-1; break;
        case left:  dx=-1; break;
        case right: dx=1;  break;
        default:break;
    }
    if (getID()==IID_BULLET || getWorld()->isPassable(getX()+dx, getY()+dy))
        moveTo(getX()+dx, getY()+dy);
    else
        notPassableThenWhat();
}

void EventTrigger::iAmAlive()
{
    if (getX()==getWorld()->getPlayer()->getX()&&
        getY()==getWorld()->getPlayer()->getY())
        triggerPlayer();
}

// How things specifically work
void MovingThings::fire()
{
    int dx=0,dy=0;
    switch (getDirection()) {
        case up:    dy=1;  break;
        case down:  dy=-1; break;
        case left:  dx=-1; break;
        case right: dx=1;  break;
        default:break;
    }
    AllThings* newBl=new Bullet(getX(),getY(),getWorld()->getCurrentSubLevel(),getDirection(),getWorld());
    getWorld()->getAllThings()->push_back(newBl);
    newBl->moveTo(getX()+dx, getY()+dy);
}

void BadGuys::fire()
{
    MovingThings::fire();
    getWorld()->playSound(SOUND_ENEMY_FIRE);
}

void BadGuys::beingAttacked(Bullet* bl)
{
    if (!isDead())
    {
        bl->goDie();
        if (m_hitPoints>BULLET_DAMAGE)
        {
            m_hitPoints-=BULLET_DAMAGE;
            getWorld()->playSound(SOUND_ENEMY_IMPACT);
        }
        else
            goDie();
    }
}

bool BadGuys::canFire()
{
    vector<AllThings*>::iterator it;
    if (getDirection()==up || getDirection()==down)
    {
        if (getX()==getWorld()->getPlayer()->getX())
        {
            for (it=getWorld()->getAllThings()->begin();it!=getWorld()->getAllThings()->end();it++)
            {
                if ((*it)->getX()==getX() && (*it)!=this &&
                    (*it)->getY()>fmin(getY(), getWorld()->getPlayer()->getY()) &&
                    (*it)->getY()<fmax(getY(), getWorld()->getPlayer()->getY())
                    )
                {
                    if ((*it)->isObstacle())
                        return false;
                }
            }
            if (getY()<getWorld()->getPlayer()->getY())
            {
                if (getDirection()!=up) return false;
            }
            else
            {
                if (getDirection()!=down) return false;
            }
        }
        else return false;
    }
    else if (getDirection()==left || getDirection()==right)
    {
        if (getY()==getWorld()->getPlayer()->getY())
        {
            for (it=getWorld()->getAllThings()->begin();it!=getWorld()->getAllThings()->end();it++)
            {
                if ((*it)->getY()==getY() && (*it)!=this &&
                    (*it)->getX()>fmin(getX(), getWorld()->getPlayer()->getX()) &&
                    (*it)->getX()<fmax(getX(), getWorld()->getPlayer()->getX())
                    )
                {
                    if ((*it)->isObstacle())
                        return false;
                }
            }
            if (getX()<getWorld()->getPlayer()->getX())
            {
                if (getDirection()!=right) return false;
            }
            else
            {
                if (getDirection()!=left) return false;
            }
        }
        else return false;
    }
    return true;
}

bool BadGuys::canMove()     //////////////////!!!!!!!BUG!!!!!!!/////////////////////////FrequencySomehowTooLow
{
    int f=(28-getWorld()->getLevel())/4;
    bool r;
    if (f<3) f=3;
    r=(m_restTick%f==0);
    m_restTick++;
    return(r);
}

void BadGuys::goDie()
{
    MovingThings::goDie();
    getWorld()->playSound(SOUND_ENEMY_DIE);
    getWorld()->increaseScore
        (getID()==IID_ROBOT_BOSS ? SCORE_ROBOT_BOSS:(getID()==IID_GANGSTER ? SCORE_GANSTER:SCORE_BULLY));
}

void Wall::beingAttacked(Bullet* bl)
{bl->goDie();}

void Player::fire()
{
    MovingThings::fire();
    getWorld()->playSound(SOUND_PLAYER_FIRE);
    getWorld()->useAmmo();
}

void Player::goDie()
{
    MovingThings::goDie();
    getWorld()->setStatus(GWSTATUS_PLAYER_DIED);
    getWorld()->playSound(SOUND_PLAYER_DIE);
}

void Player::iAmAlive()
{
    int action=0;
    getWorld()->getKey(action);
    switch (action) {
        case KEY_PRESS_ESCAPE: getWorld()->setStatus(GWSTATUS_PLAYER_DIED); break;
        case KEY_PRESS_SPACE:  if (getWorld()->getAmmo()>0) fire();         break;
        case KEY_PRESS_UP:     setDirection(up); moveTick();                break;
        case KEY_PRESS_DOWN:   setDirection(down); moveTick();              break;
        case KEY_PRESS_LEFT:   setDirection(left); moveTick();              break;
        case KEY_PRESS_RIGHT:  setDirection(right); moveTick();             break;
        default: break;
    }
}

void Player::beingAttacked(Bullet* bl)
{
    bl->goDie();
    if (getWorld()->getHitpoints()>BULLET_DAMAGE)
    {
        getWorld()->decHitpoints(BULLET_DAMAGE);
        getWorld()->playSound(SOUND_PLAYER_IMPACT);
    }
    else goDie();
}

void Bullet::doSomeDamage()
{
    // Traverse
    vector<AllThings*>::iterator it;
    for (it=getWorld()->getAllThings()->begin();it!=getWorld()->getAllThings()->end();it++)
    {
        if ((*it)->getX()==getX()&&(*it)->getY()==getY()&&(*it)!=this)
        {
            moveTo(getX(), getY());
            (*it)->beingAttacked(this);
            if (isDead())
                break;
        }
    }
}

bool Bully::canDoOther()
{
    bool itCanDoOther=false;
    vector<AllThings*>::iterator it;
    for (it=getWorld()->getAllThings()->begin();it!=getWorld()->getAllThings()->end();it++)
    {
        if ((*it)->getX()==getX() && (*it)->getY()==getY())
        {
            if ((*it)->getID()==IID_AMMO || (*it)->getID()==IID_RESTORE_HEALTH || (*it)->getID()==IID_EXTRA_LIFE)
            {
                m_goodies[(*it)->getID()]++;
                getWorld()->playSound(SOUND_BULLY_MUNCH);
                (*it)->goDie();
                itCanDoOther=true;
            }
        }
    }
    if (!itCanDoOther)
    {
        if (m_curDistance<m_distanceBeforeTurning)
        {
            m_curDistance++;
            return false;
        }
        else
        {
            notPassableThenWhat();
            return true;
        }
    }
    return itCanDoOther;
}

void Bully::notPassableThenWhat()
{
    m_curDistance=0;
    m_distanceBeforeTurning=rand()%BULLY_MAX_TURN_TICK+1;
    Direction arrDir[4]={up,down,left,right};
    int newDir=rand()%4;
    int i;
    for (i=0;i<4;i++)
    {
        int j=(i+newDir)%4;
        int dx=0,dy=0;
        if (j/2==0)
            dy=(j%2==0?1:-1);
        else
            dx=(j%2==0?-1:1);
        if (getWorld()->isPassable(getX()+dx, getY()+dy))
        {
            setDirection(arrDir[j]);
            moveTo(getX()+dx, getY()+dy);
        }
    }
    if (i==4)
    {
        setDirection(arrDir[newDir]);
    }
}

void Bully::goDie()
{
    BadGuys::goDie();
    for (int j=0;j<m_goodies[IID_AMMO];j++)
    {
        AllThings* newAmmo=new Ammo(getX(),getY(),getWorld()->getCurrentSubLevel(),getWorld());
        getWorld()->getAllThings()->push_back(newAmmo);
        newAmmo->setVisible(true);
    }
    for (int j=0;j<m_goodies[IID_RESTORE_HEALTH];j++)
    {
        AllThings* newResH=new RestoreHealth(getX(),getY(),getWorld()->getCurrentSubLevel(),getWorld());
        getWorld()->getAllThings()->push_back(newResH);
        newResH->setVisible(true);
    }
    for (int j=0;j<m_goodies[IID_EXTRA_LIFE];j++)
    {
        AllThings* newExL=new ExtraLife(getX(),getY(),getWorld()->getCurrentSubLevel(),getWorld());
        getWorld()->getAllThings()->push_back(newExL);
        newExL->setVisible(true);
    }
}

void Gangster::goDie()
{
    BadGuys::goDie();
    AllThings* newWP=new Waterpool(getX(),getY(),getWorld()->getCurrentSubLevel(),getWorld());
    getWorld()->getAllThings()->push_back(newWP);
}

void RobotBoss::goDie()
{
    BadGuys::goDie();
    AllThings* newHos=new Hostage(getX(),getY(),getWorld()->getCurrentSubLevel(),getWorld());
    getWorld()->getAllThings()->push_back(newHos);
    newHos->setVisible(true);
}

void BullyNest::iAmAlive()
{
    unsigned int count=0;
    vector<AllThings*>::iterator it;
    for (it=getWorld()->getAllThings()->begin();it!=getWorld()->getAllThings()->end();it++)
    {
        if ((*it)->getID()==IID_BULLY)
        {
            if (((*it)->getX()<=getX()+3 && (*it)->getX()>=getX()-3) && ((*it)->getY()<=getY()+3 && (*it)->getY()>=getY()-3))
            {
                if ((*it)->getX()==getX()&&(*it)->getY()==getY())
                {
                    count=3;
                    break;
                }
                count++;
            }
        }
    }
    if (count<3)
    {
        if ((rand()%BULLYNEST_CHANCE)==0)
        {
            getWorld()->getAllThings()->push_back(new Bully(getX(),getY(),getWorld()->getCurrentSubLevel(),getWorld()));
            getWorld()->playSound(SOUND_BULLY_BORN);
        }
    }
}

void Gate::triggerPlayer()
{
    getWorld()->toSublevel(m_toLevel);
    goDie();
}

void Gold::triggerPlayer()
{
    getWorld()->increaseScore(SCORE_GOLD);
    getWorld()->playSound(SOUND_GOT_GOLD);
    goDie();
}

void Ammo::triggerPlayer()
{
    getWorld()->gainAmmo(AMMUNITION_AMMO);
    getWorld()->increaseScore(SCORE_AMMO);
    getWorld()->playSound(SOUND_GOT_GOODIE);
    goDie();
}

void FarplaneGun::triggerPlayer()
{
    if (getWorld()->getHitpoints()>FARPLANE_GUN_HARM)
        getWorld()->decHitpoints(FARPLANE_GUN_HARM);
    else getWorld()->getPlayer()->goDie();
    vector<AllThings*>::iterator it;
    for (it=getWorld()->getAllThings()->begin();it!=getWorld()->getAllThings()->end();it++)
    {
        if (((*it)->getX()<=getX()+4 && (*it)->getX()>=getX()-4) && ((*it)->getY()<=getY()+4 && (*it)->getY()>=getY()-4))
        {
            if ((*it)->getID()==IID_BULLY || (*it)->getID()==IID_GANGSTER)
                (*it)->goDie();
        }
    }
    getWorld()->playSound(SOUND_GOT_FARPLANE_GUN);
    goDie();
}

void ExtraLife::triggerPlayer()
{
    getWorld()->increaseScore(SCORE_EXTRA_LIFE);
    getWorld()->incLives();
    getWorld()->playSound(SOUND_GOT_GOODIE);
    goDie();
}

void RestoreHealth::triggerPlayer()
{
    getWorld()->increaseScore(SCORE_RESTORE);
    getWorld()->setHitpoints(INITIAL_HITPOINTS);
    getWorld()->playSound(SOUND_GOT_GOODIE);
    goDie();
}

void Exit::iAmAlive()
{
    if (!isComplete)
    {
        vector<AllThings*>::iterator it;
        for (int j=0;j<=getWorld()->getSublevel();j++)
        {
            for (it=getWorld()->getAllThings(j)->begin();it!=getWorld()->getAllThings(j)->end();it++)
            {
                if ((*it)->getID()==IID_GOLD || (*it)->getID()==IID_ROBOT_BOSS || (*it)->getID()==IID_HOSTAGE)
                    return;
            }
        }
        isComplete=true;
        if (getWorld()->getCurrentSubLevel()==0)
        {
            setVisible(true);
            getWorld()->playSound(SOUND_REVEAL_EXIT);
        }
    }
    else
    {
        if (getWorld()->getCurrentSubLevel()==0)
        {
            setVisible(true);
        }
        EventTrigger::iAmAlive();
    }
}

void Exit::triggerPlayer()
{
    getWorld()->setStatus(GWSTATUS_FINISHED_LEVEL);
    getWorld()->playSound(SOUND_FINISHED_LEVEL);
    getWorld()->increaseScore(getWorld()->getTick()+SCORE_EXIT);
}

void Hostage::triggerPlayer()
{
    getWorld()->playSound(SOUND_GOT_GOODIE);
    goDie();
}
