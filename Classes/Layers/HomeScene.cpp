//
//  HomeScene.cpp
//  BattleRub
//
//  Created by Lucky
//
//

#include "HomeScene.h"
#include "GameSettings.h"
#include "MainScene.h"
//#include "GameScene.h"
//#include "SettingScene.h"

Scene* HomeScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HomeScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

HomeScene::~HomeScene(){
    removeAllChildren();
    stopAllActions();
    unscheduleAllCallbacks();
}

bool HomeScene::init(){
    if ( !Layer::init() )
    {
        return false;
    }
    
    createBg();
    createLabel();
    createBtn();
    createPopup();
    
    return true;
}

void HomeScene::createBg()
{
    
}

void HomeScene::createPopup(){
   
}

void HomeScene::createLabel()
{
    newLabel("BATTLE RUB", "arial.ttf", DISO(150), G_SWIDTH / 2, getY(700), this, 0, RATIO_1);
}

void HomeScene::createBtn()
{
    MenuItemLabel* iStart = newLabelButton("NEW GAME", "arial.ttf", DISO(80), G_SWIDTH / 2, getY(1600), CC_CALLBACK_1(HomeScene::onMenu, this), RATIO_O);
    iStart->setTag(100);
    MenuItemLabel* iLeaderboard = newLabelButton("LEADERBOARD", "arial.ttf", DISO(80), G_SWIDTH / 2, getY(1800), CC_CALLBACK_1(HomeScene::onMenu, this), RATIO_O);
    iLeaderboard->setTag(101);
    
    m_mMain = Menu::create(iStart, iLeaderboard, NULL);
    m_mMain->setPosition(0, 0);
    addChild(m_mMain, 1);
}

void HomeScene::onMenu(Ref *sender)
{
    if(((MenuItemLabel *)sender)->getTag() == 100){
        Director::getInstance()->replaceScene(TransitionCrossFade::create(0.5f, MainScene::createScene()));
    }
}
