//
//  MainScene.h
//  Rock It Robins
//
//  Created by Lucky
//
//

#ifndef MainScene_h
#define MainScene_h

#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace spine;
using namespace cocos2d::ui;

class MainScene : public Layer{
    
public:
    virtual bool init();
    CREATE_FUNC(MainScene);
    static Scene* createScene();
    ~MainScene();

private:    
    void createBg();
    void createLabel();
    void createBtn();
    void createPopup();
    void onMenu(Ref *sender);
    
private:
    int m_nTime;
    int m_nScore;
    Menu *m_mMain;
    Label *m_lTime;
    Label *m_lScore;
    
    MotionStreak *_streak;
    Sprite *m_sCircle;
    bool m_bTouchCircle;
    
    bool m_bPlaying[6];
    int m_nSoundId[6];
    MenuItemLabel *m_iInfo[6];
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    
    /*virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *pEvent);
    virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *pEvent);
    virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *pEvent);*/
};

#endif /* MainScene_h */
