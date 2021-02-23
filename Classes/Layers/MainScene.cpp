//
//  MainScene.cpp
//  Rock It Robins
//
//  Created by Lucky
//
//

#include "MainScene.h"
#include "GameSettings.h"

//#include "GameScene.h"
//#include "SettingScene.h"

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

MainScene::~MainScene(){
    removeAllChildren();
    stopAllActions();
    unscheduleAllCallbacks();
}

bool MainScene::init(){
    if ( !Layer::init() )
    {
        return false;
    }
    
    createBg();
    createLabel();
    createBtn();
    createPopup();
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(MainScene::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(MainScene::onTouchEnded, this);
    
    /*auto touchListener = EventListenerTouchAllAtOnce::create();
    touchListener->onTouchesBegan = CC_CALLBACK_2(MainScene::onTouchesBegan, this);
    touchListener->onTouchesMoved = CC_CALLBACK_2(MainScene::onTouchesMoved, this);
    touchListener->onTouchesEnded = CC_CALLBACK_2(MainScene::onTouchesEnded, this);
    touchListener->onTouchesCancelled = CC_CALLBACK_2(MainScene::onTouchesEnded, this);
    */
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    m_nTime = 10;
    m_nScore = 0;
    m_sCircle = newSprite("circle", G_SWIDTH / 2, G_SHEIGHT / 2, this, 1, RATIO_O);
    return true;
}

void MainScene::createBg()
{
    _streak = MotionStreak::create(1, 3, DISO(30), Color3B::YELLOW, "res/Image/circle.png");
    addChild(_streak, 2);
    _streak->setFastMode(true);
}

void MainScene::createPopup(){
   
}

void MainScene::createLabel()
{
    Label *lTimer = newLabel("TIMER:", "arial.ttf", DISO(60), getX(100), getY(200), this, 1, RATIO_1);
    lTimer->setAnchorPoint(Vec2(0, 0.5));
    Label *lScore = newLabel("SCORE:", "arial.ttf", DISO(60), G_SWIDTH / 2 + DISX(100), getY(200), this, 1, RATIO_1);
    lScore->setAnchorPoint(Vec2(0, 0.5));
    
    m_lTime = newLabel("0", "arial.ttf", DISO(60), lTimer->getBoundingBox().size.width + getX(110), getY(200), this, 1, RATIO_1);
    m_lTime->setAnchorPoint(Vec2(0, 0.5));
    
    m_lScore = newLabel("0", "arial.ttf", DISO(60), lScore->getBoundingBox().size.width + G_SWIDTH / 2 + getX(110), getY(200), this, 1, RATIO_1);
    m_lScore->setAnchorPoint(Vec2(0, 0.5));
}

void MainScene::createBtn()
{
    
}

void MainScene::onMenu(Ref *sender)
{
    
}

bool MainScene::onTouchBegan(Touch *touch, Event *unused_event){
    _streak->reset();
    _streak->setPosition( touch->getLocation() );
    
    if(touch->getLocation().distance(m_sCircle->getPosition()) < m_sCircle->getBoundingBox().size.width / 2){
        m_bTouchCircle = true;
    }else{
        m_bTouchCircle = false;
    }
//    log("touch begin");
    return true;
}
void MainScene::onTouchMoved(Touch *touch, Event *unused_event){
    _streak->setPosition( touch->getLocation() );
    if(touch->getLocation().distance(m_sCircle->getPosition()) < m_sCircle->getBoundingBox().size.width / 2){
        m_bTouchCircle = true;
    }else{
        if(m_bTouchCircle){
            m_nScore++;
            m_lScore->setString(to_string(m_nScore));
            m_sCircle->setScale(G_SCALEO * 1.2 );
            m_sCircle->stopAllActions();
            m_sCircle->runAction(ScaleTo::create(0.5, G_SCALEO));
        }
        m_bTouchCircle = false;
    }
//    log("touch move");
}
void MainScene::onTouchEnded(Touch *touch, Event *unused_event){
    m_bTouchCircle = false;
//    log("touch end");
}
/*
void MainScene::onTouchesBegan(const std::vector<Touch*>& touches, Event *pEvent){
    
}

void MainScene::onTouchesMoved(const std::vector<Touch*>& touches, Event *pEvent){
    
}
void MainScene::onTouchesEnded(const std::vector<Touch*>& touches, Event *pEvent){
    
}*/
