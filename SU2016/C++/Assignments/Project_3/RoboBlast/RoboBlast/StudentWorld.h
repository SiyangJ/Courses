#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Level.h"
#include "GraphObject.h"
#include "Actor.h"
#include <string>
#include <vector>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

// Initializing stat
const unsigned int TICK_PER_LEVEL      = 3000;
const unsigned int INITIAL_HITPOINTS   = 20;
const unsigned int INITIAL_AMMO        = 0;

// Score setting
const unsigned int SCORE_GANSTER       = 100;
const unsigned int SCORE_BULLY         = 10;
const unsigned int SCORE_ROBOT_BOSS    = 3000;
const unsigned int SCORE_GOLD          = 100;
const unsigned int SCORE_EXTRA_LIFE    = 150;
const unsigned int SCORE_RESTORE       = 250;
const unsigned int SCORE_AMMO          = 150;
const unsigned int SCORE_EXIT          = 1500;

// Other stat
const unsigned int FARPLANE_GUN_HARM   = 10;
const unsigned int AMMUNITION_AMMO     = 25;
const unsigned int BULLYNEST_CHANCE    = 50;
const unsigned int BULLY_MAX_TURN_TICK = 6;
const unsigned int BULLET_DAMAGE       = 2;

class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir) :
        GameWorld(assetDir),m_levelPtr(nullptr),m_tick(TICK_PER_LEVEL),
        m_status(GWSTATUS_CONTINUE_GAME),m_playerHitpoints(INITIAL_HITPOINTS),m_playerAmmo(INITIAL_AMMO)
	{}
    
    ~StudentWorld()
    {
        cleanUp();
    }

    virtual int init();

    virtual int move();

    virtual void cleanUp();
    
    virtual int getCurrentSubLevel()
    {
        return m_curSublevel;
    }
    
    void          setStatus(int x){m_status=x;}
    
    void          decHitpoints(int a){m_playerHitpoints-=a;}
    void          setHitpoints(unsigned int a){m_playerHitpoints=a;}
    unsigned int  getHitpoints(){return m_playerHitpoints;}
    
    void          gainAmmo(int a){m_playerAmmo+=a;}
    unsigned int  getAmmo(){return m_playerAmmo;}
    void          useAmmo(){m_playerAmmo--;}
    
    unsigned int  getSublevel(){return m_sublevel;}
    unsigned int  getTick(){return m_tick;}
    AllThings*    getPlayer(){return m_playerPtr;}
    
    //A more general yet less safe approach;
    std::vector<AllThings*>* getAllThings(unsigned int lev){return m_allThings[lev];}
    std::vector<AllThings*>* getAllThings(){return m_allThings[m_curSublevel];}
    
    //Try to cancel the getAllThings function.
    //void          addNewThings(int iid, int x, int y, bool isVisible, GraphObject::Direction dir=GraphObject::none);
    //std::vector<AllThings*>  positionLocator(int x, int y);
    
    void          toSublevel(unsigned int lev);
    bool          isPassable(unsigned int x, unsigned int y);
    
private:
    std::string num2str(int num, unsigned int width, char fill=' ');
    void setAllButExitVisible();       // Set all things except exit on current sublevel visible;
    void setAllInvisible();

    AllThings*   m_playerPtr;
    unsigned int m_playerHitpoints;
    unsigned int m_playerAmmo;
    int          m_status;
    unsigned int m_sublevel;
    unsigned int m_curSublevel;
    Level*       m_levelPtr;
    unsigned int m_tick;
    std::vector<std::vector<AllThings*>*> m_allThings;
};

#endif // STUDENTWORLD_H_
