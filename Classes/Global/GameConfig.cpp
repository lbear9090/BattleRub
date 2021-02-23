//
//  GameConfig.cpp
//  Rock It Robins
//
//  Created by Lucky
//
//

#include "GameConfig.h"

bool g_bSoundOn = true;

int g_nScore = 0;
int g_nHighScore = 0;
int g_nAccuracy = 0;

Animation *g_aniExplode;
Animation *g_aniMeteor;
Animation *g_aniTongue;
Animation *g_aniUFO;
Animation *g_aniStun;
Animation *g_aniSpark;
Animation *g_aniMice[MICE_CNT];
bool g_bTrophy[TROPHY_CNT];
Layer *g_layerGame = NULL;

void loadGameInfo(){
//    SimpleAudioEngine::getInstance()->preloadEffect("res/Musics/shining_time.mp3");
    
//    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0);
//    SimpleAudioEngine::getInstance()->setEffectsVolume(1.0);
    g_nHighScore = UserDefault::getInstance()->getIntegerForKey("HIGHSCORE", 0);
    
    for(int i = 0; i < TROPHY_CNT; i++){
        string sKey = "TROPHY" + toString(i);
        g_bTrophy[i] = UserDefault::getInstance()->getBoolForKey(sKey.c_str(), false);
    }
}

void saveGameInfo(){
    UserDefault::getInstance()->setIntegerForKey("HIGHSCORE", g_nHighScore);
    for(int i = 0; i < TROPHY_CNT; i++){
        string sKey = "TROPHY" + toString(i);
        UserDefault::getInstance()->setBoolForKey(sKey.c_str(), g_bTrophy[i]);
    }
}

int getCurrentTime(){
    time_t t = time(0);
    struct tm * now = localtime(&t);
    int crtTime = now->tm_mon*(30*24*3600)+now->tm_mday*(24*3600)+now->tm_hour*3600+now->tm_min*60+now->tm_sec;

    return crtTime;

    //    return now->tm_gmtoff;// crtTime;
}
