#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;
class Bullet;

class AllThings : public GraphObject
{
public:
    AllThings(int imageID, int startX, int startY, Direction dir, int sub_level)
    : GraphObject(imageID, startX, startY, dir, sub_level),m_isDead(false)
    {}
    virtual void doSomething(){}                 // Do nothing, e.g. the wall and fake walls;
    virtual void beingAttacked(Bullet* bl){}
    virtual void goDie(){}
    virtual bool isObstacle(){return false;}
    virtual bool isObstruction(){return true;}
    bool         isDead(){return m_isDead;}
    void         setDead(bool amIDead){m_isDead=amIDead;}
private:
    bool m_isDead;
};

class Actor : public AllThings
{
public:
    Actor(int imageID, int startX, int startY, Direction dir, int sub_level, StudentWorld* stdWorld)
    : AllThings(imageID, startX, startY, dir, sub_level), m_studentWorld(stdWorld)
    {}
    StudentWorld* getWorld(){return m_studentWorld;}
    virtual void goDie();
    virtual void iAmAlive()=0;
    virtual void doSomething()
    {
        if (!isDead())
        {
            iAmAlive();
            return;
        }
    }
private:
    StudentWorld* m_studentWorld;
    
};

class MovingThings : public Actor
{
public:
    MovingThings(int imageID, int startX, int startY, Direction dir, int sub_level, StudentWorld* stdWorld)
    : Actor(imageID, startX, startY, dir, sub_level, stdWorld)
    {}
    virtual void fire();
    void         moveTick();
    virtual void notPassableThenWhat(){}
private:
    
};

class Bullet : public MovingThings
{
public:
    Bullet(int startX, int startY, int sub_level, Direction dir, StudentWorld* stdWorld)
    : MovingThings(IID_BULLET, startX, startY, dir, sub_level, stdWorld)
    {setVisible(true);}
    void         doSomeDamage();
    virtual bool isObstruction(){return false;}
    virtual void iAmAlive()
    {
        doSomeDamage();
        moveTick();
        if(!isDead())
            doSomeDamage();
    }
};

class BadGuys : public MovingThings
{
public:
    BadGuys(int imageID, int startX, int startY, Direction dir,int sub_level, StudentWorld* stdWorld, unsigned int hitP)
    : MovingThings(imageID, startX, startY, dir, sub_level, stdWorld),m_restTick(0),m_hitPoints(hitP)
    {}
    virtual void fire();
    bool         canMove();
    bool         canFire();
    virtual void notPassableThenWhat()
    {
        switch (getDirection()) {
            case up:    setDirection(down);  break;
            case down:  setDirection(up);    break;
            case left:  setDirection(right); break;
            case right: setDirection(left);  break;
            default: break;
        }
    }
    virtual void beingAttacked(Bullet*);
    virtual void goDie();
    virtual bool isObstacle(){return true;}
    virtual bool canDoOther(){return false;}
    virtual void iAmAlive()
    {
        if (!canMove()) return;
        if (canFire())
            fire();
        else if (canDoOther());
        else moveTick();
    }
private:
    int          m_hitPoints;
    unsigned int m_restTick;
};
class EventTrigger : public Actor
{
public:
    EventTrigger(int imageID, int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : Actor(imageID, startX, startY, none, sub_level, stdWorld)
    {}
    virtual void triggerPlayer()=0;
    virtual void iAmAlive();
    virtual bool isObstruction(){return false;}
};

class Player : public MovingThings
{
public:
    Player(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : MovingThings(IID_PLAYER, startX, startY, right, sub_level, stdWorld)
    {}
    virtual void fire();
    virtual void goDie();
    virtual void beingAttacked(Bullet*);
    virtual void iAmAlive();
};
class Gangster : public BadGuys
{
public:
    Gangster(int startX, int startY, Direction dir, int sub_level, StudentWorld* stdWorld)
    : BadGuys(IID_GANGSTER,startX,startY,dir,sub_level,stdWorld,10)
    {}
    virtual void goDie();
};
class Horiz_Gangster : public Gangster
{
public:
    Horiz_Gangster(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : Gangster(startX, startY, right, sub_level, stdWorld)
    {}
};
class Vertic_Gangster : public Gangster
{
public:
    Vertic_Gangster(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : Gangster(startX, startY, down, sub_level, stdWorld)
    {}
};
class Bully : public BadGuys
{
public:
    Bully(int startX, int startY, int sub_level, StudentWorld* stdWorld);
    virtual void goDie();
    virtual bool canDoOther();
    virtual void notPassableThenWhat();
private:
    std::map<int,unsigned int> m_goodies;
    unsigned int m_distanceBeforeTurning;
    unsigned int m_curDistance;
    
};
class RobotBoss : public BadGuys
{
public:
    RobotBoss(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : BadGuys(IID_ROBOT_BOSS,startX,startY,right,sub_level,stdWorld,50)
    {}
    virtual void goDie();
};
class Exit : public EventTrigger
{
public:
    Exit(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : EventTrigger(IID_EXIT, startX, startY, sub_level, stdWorld),isComplete(false)
    {}
    virtual void iAmAlive();
    virtual void triggerPlayer();
private:
    bool isComplete;
};
class BullyNest : public Actor
{
public:
    BullyNest(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : Actor(IID_BULLY_NEST, startX, startY, none, sub_level, stdWorld)
    {}
    virtual bool isObstacle(){return true;}
    virtual void iAmAlive();
};
class Wall : public AllThings
{
public:
    Wall(int startX, int startY, int sub_level)
    : AllThings(IID_WALL, startX, startY, none, sub_level)
    {}
    virtual void beingAttacked(Bullet* bl);
    virtual bool isObstacle(){return true;}
};

class FakeWall : public AllThings
{
public:
    FakeWall(int startX, int startY, int sub_level)
    : AllThings(IID_FAKE_WALL, startX, startY, none, sub_level)
    {}
    virtual bool isObstacle(){return true;}
    virtual bool isObstruction(){return false;}
};
class Hostage : public EventTrigger
{
public:
    Hostage(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : EventTrigger(IID_HOSTAGE, startX, startY, sub_level, stdWorld)
    {}
    virtual void triggerPlayer();
};
class Gate : public EventTrigger
{
public:
    Gate(int startX, int startY, int sub_level, StudentWorld* stdWorld, unsigned int toLevel)
    : EventTrigger(IID_GATE, startX, startY, sub_level, stdWorld), m_toLevel(toLevel)
    {}
    virtual void triggerPlayer();
private:
    unsigned int m_toLevel;
};
class Gold : public EventTrigger
{
public:
    Gold(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : EventTrigger(IID_GOLD, startX, startY, sub_level, stdWorld)
    {}
    virtual void triggerPlayer();
};
class ExtraLife : public EventTrigger
{
public:
    ExtraLife(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : EventTrigger(IID_EXTRA_LIFE, startX, startY, sub_level, stdWorld)
    {}
    virtual void triggerPlayer();
};
class RestoreHealth : public EventTrigger
{
public:
    RestoreHealth(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : EventTrigger(IID_RESTORE_HEALTH, startX, startY, sub_level, stdWorld)
    {}
    virtual void triggerPlayer();
};
class Ammo : public EventTrigger
{
public:
    Ammo(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : EventTrigger(IID_AMMO, startX, startY, sub_level, stdWorld)
    {}
    virtual void triggerPlayer();
};
class Waterpool : public Actor
{
public:
    Waterpool(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : Actor(IID_WATERPOOL, startX, startY, none, sub_level, stdWorld),m_hitPoints(30)
    {setVisible(true);}
    virtual void beingAttacked(Bullet* bl){bl->goDie();}
    virtual void iAmAlive()
    {
        if (--m_hitPoints<=0)
            goDie();
    }
    virtual bool isObstacle(){return true;}
    virtual bool isObstruction(){return true;}
private:
    unsigned int m_hitPoints;
};
class FarplaneGun : public EventTrigger
{
public:
    FarplaneGun(int startX, int startY, int sub_level, StudentWorld* stdWorld)
    : EventTrigger(IID_FARPLANE_GUN, startX, startY, sub_level, stdWorld)
    {}
    virtual void goDie(){setDead(true);}
    virtual void triggerPlayer();
};
#endif // ACTOR_H_
