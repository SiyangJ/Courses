#include "StudentWorld.h"
#include <string>
#include <vector>
#include "Level.h"
#include "Actor.h"
#include <sstream>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}
// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
// AdvanceToNextLevel called when already in the next level;

int StudentWorld::init()
{
    setHitpoints(INITIAL_HITPOINTS);
    m_playerAmmo=INITIAL_AMMO;
    m_status=GWSTATUS_CONTINUE_GAME;
    
    unsigned int curLev=getLevel();
    if (curLev>99)
        return GWSTATUS_PLAYER_WON;
    string curLevDir="level";
    curLevDir.push_back('0'+curLev/10);
    curLevDir.push_back('0'+curLev%10);
    m_levelPtr = new Level(assetDirectory());
    Level::LoadResult result = m_levelPtr->loadLevel(curLevDir+".dat");
    if (result==Level::load_fail_file_not_found)
        return GWSTATUS_PLAYER_WON;
    else if (result==Level::load_fail_bad_format)
        return GWSTATUS_LEVEL_ERROR;
    // Loading main level finished
    
    for (unsigned int i=1;i<=MAX_SUB_LEVEL;i++)
    {
        string curSubLevDir=curLevDir;
        curSubLevDir+="_";
        curSubLevDir.push_back('0'+i);
        curSubLevDir+=".dat";
        result=m_levelPtr->loadLevel(curSubLevDir,i);
        if (result==Level::load_sublevel_fail_file_not_found)
        {
            m_sublevel=--i;
            break;
        }
        else if (result==Level::load_sublevel_fail_bad_format)
            return GWSTATUS_LEVEL_ERROR;
    }
    // Loading sublevels finished, begin constructing;
    
    for (unsigned int lev=0;lev<=m_sublevel;lev++)
    {
        m_allThings.push_back(new vector<AllThings*>);
        for (unsigned int r=0;r<VIEW_HEIGHT;r++)
        {
            for (unsigned int c=0;c<VIEW_WIDTH;c++)
            {
                Level::MazeEntry obj = m_levelPtr->getContentsOf(c, r, lev);
                switch (obj) {
                    case Level::exit:            m_allThings[lev]->push_back(new Exit(c,r,lev,this));             break;
                    case Level::player:          m_allThings[lev]->push_back(new Player(c,r,lev,this));           break;
                    case Level::horiz_gangster:  m_allThings[lev]->push_back(new Horiz_Gangster(c,r,lev,this));   break;
                    case Level::vert_gangster:   m_allThings[lev]->push_back(new Vertic_Gangster(c,r,lev,this));  break;
                    case Level::bully_nest:      m_allThings[lev]->push_back(new BullyNest(c,r,lev,this));        break;
                    case Level::wall:            m_allThings[lev]->push_back(new Wall(c,r,lev));                  break;
                    case Level::fake_wall:       m_allThings[lev]->push_back(new FakeWall(c,r,lev));              break;
                    case Level::gold:            m_allThings[lev]->push_back(new Gold(c,r,lev,this));             break;
                    case Level::restore_health:  m_allThings[lev]->push_back(new RestoreHealth(c,r,lev,this));    break;
                    case Level::extra_life:      m_allThings[lev]->push_back(new ExtraLife(c,r,lev,this));        break;
                    case Level::ammo:            m_allThings[lev]->push_back(new Ammo(c,r,lev,this));             break;
                    case Level::hostage:         m_allThings[lev]->push_back(new Hostage(c,r,lev,this));          break;
                    case Level::farplane_gun:    m_allThings[lev]->push_back(new FarplaneGun(c,r,lev,this));      break;
                    case Level::robot_boss:      m_allThings[lev]->push_back(new RobotBoss(c,r,lev,this));        break;
                    case Level::gate0:
                    case Level::gate1:
                    case Level::gate2:
                    case Level::gate3:
                    case Level::gate4:
                    case Level::gate5:           m_allThings[lev]->push_back(new Gate(c,r,lev,this,obj));         break;
                    default:break;
                }
            }
        }
    }
    // Constructing GraphObjects finished;
    
    m_curSublevel = 0;
    m_tick        = TICK_PER_LEVEL;
    m_status      = GWSTATUS_CONTINUE_GAME;
    
    setAllButExitVisible();
    // Setting things to visible
    
    
    return GWSTATUS_CONTINUE_GAME;
}


int StudentWorld::move()
{
    if (m_tick==0)
    {
        decLives();
        return GWSTATUS_PLAYER_DIED;
    }
    
    vector<AllThings*>::iterator it;
    for (it=getAllThings()->begin();it!=getAllThings()->end();it++)
    {
        if ((*it)->getID()==IID_GATE)
        {
            vector<AllThings*>* curAllThings=getAllThings();
            (*it)->doSomething();
            if ((*it)->isDead())
            {
                delete (*it);
                curAllThings->erase(it);
                it=getAllThings()->begin();
            }
        }
        (*it)->doSomething();
        if ((*it)->isDead()&&(*it)->getID()!=IID_FARPLANE_GUN)                 ////// Need improvement
        {
            delete (*it);
            getAllThings()->erase(it);
            it--;
        }
    }
    // let bulletes and farplane gun delete things;
    m_tick--;
    setGameStatText("Score: "+num2str(getScore(), 7,'0')+
                    "  Level: "+num2str(getLevel(), 2,'0')+"-"+num2str(getCurrentSubLevel(), 2,'0')+
                    "  Lives: "+num2str(getLives(), 2)+
                    "  Health: "+num2str(m_playerHitpoints*5,3)+"%"+
                    "  Ammo: "+num2str(m_playerAmmo, 3)+
                    "  TimeLimit: "+num2str(m_tick, 4)
                    );
    if (m_status==GWSTATUS_PLAYER_DIED) decLives();
    return m_status;
}

void StudentWorld::cleanUp()
{
    for (vector<vector<AllThings*>*>::iterator it1=m_allThings.begin();it1!=m_allThings.end();it1++)
    {
        for (vector<AllThings*>::iterator it=(*it1)->begin();it!=(*it1)->end();it++)
        {
            delete (*it);
            (*it1)->erase(it);
            it--;
        }
        delete (*it1);
        m_allThings.erase(it1);
        it1--;
    }
    delete m_levelPtr;
}

string StudentWorld::num2str(int num, unsigned int width, char fill)
{
    ostringstream oss;
    oss.width(width);
    oss.fill(fill);
    oss << num;
    return oss.str();
}

void StudentWorld::toSublevel(unsigned int lev)
{
    setAllInvisible();
    m_curSublevel=lev;
    setAllButExitVisible();
}

void StudentWorld::setAllButExitVisible()
{
    vector<AllThings*>* curLevThings = getAllThings();
    for (vector<AllThings*>::iterator it=curLevThings->begin(); it!=curLevThings->end(); it++)
    {
        if ((*it)->getID()!=IID_EXIT)
            (*it)->setVisible(true);
        if ((*it)->getID()==IID_PLAYER)
            m_playerPtr=(*it);
    }
}

void StudentWorld::setAllInvisible()
{
    vector<AllThings*>* curLevThings = getAllThings();
    for (vector<AllThings*>::iterator it=curLevThings->begin(); it!=curLevThings->end(); it++)
    {
            (*it)->setVisible(false);
    }
}


bool StudentWorld::isPassable(unsigned int x, unsigned int y)
{
    vector<AllThings*>* curLevThings = getAllThings();
    for (vector<AllThings*>::iterator it=curLevThings->begin(); it!=curLevThings->end(); it++)
    {
        if (((*it)->getX()==x && (*it)->getY()==y)&&(*it)->isObstruction())
        {
            return false;
        }
    }
    return true;
}

/*void StudentWorld::addNewThings(int iid, int x, int y, bool isVisible, GraphObject::Direction dir)
{
    AllThings* newThing=nullptr;
    switch (iid) {
        case IID_AMMO           : newThing = new Ammo(x,y,m_curSublevel,this);          break;
        case IID_RESTORE_HEALTH : newThing = new RestoreHealth(x,y,m_curSublevel,this); break;
        case IID_EXTRA_LIFE     : newThing = new ExtraLife(x,y,m_curSublevel,this);     break;
        case IID_HOSTAGE        : newThing = new Hostage(x,y,m_curSublevel,this);       break;
        case IID_WATERPOOL      : newThing = new Waterpool(x,y,m_curSublevel,this);     break;
        case IID_BULLET         : newThing = new Bullet(x,y,m_curSublevel,dir,this);    break;
        default:break;
    }
    if (newThing!=nullptr)
    {
        getAllThings()->push_back(newThing);
        newThing->setVisible(isVisible);
    }
    
}
 */

/*vector<AllThings*> StudentWorld::positionLocator(int x, int y)
{
    vector<AllThings*> vec;
    for (vector<AllThings*>::iterator it=getAllThings()->begin();it!=getAllThings()->end();it++)
    {
        if ((*it)->getX()==x && (*it)->getY()==y)
            vec.push_back(*it);
    }
    return vec;
}
 */

/*void StudentWorld::deleteDeadThings()
{
    for (vector<AllThings*>::iterator it=m_allThings[m_curSublevel]->begin(); it!=m_allThings[m_curSublevel]->end(); it++)
    {
        if ((*it)->isDead())
        {
            delete (*it);
            m_allThings[m_curSublevel]->erase(it);
        }
    }
}*/




