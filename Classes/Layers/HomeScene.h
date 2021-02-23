//
//  HomeScene.h
//  BattleRub
//
//  Created by Lucky
//
//

#ifndef HomeScene_h
#define HomeScene_h

#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace spine;
using namespace cocos2d::ui;

class HomeScene : public Layer{
    
public:
    virtual bool init();
    CREATE_FUNC(HomeScene);
    static Scene* createScene();
    ~HomeScene();

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
    
    bool m_bTouchCircle;
};

#endif /* HomeScene_h */
