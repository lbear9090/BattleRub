//
//  GameConfig.cpp
//  BattleRub
//
//  Created by Lucky
//
//

#include "GameConfig.h"

bool g_bSoundOn = true;

int g_nScore = 0;
int g_nHighScore = 0;

Layer *g_layerGame = NULL;

void loadGameInfo(){
//    SimpleAudioEngine::getInstance()->preloadEffect("res/Musics/shining_time.mp3");
    
//    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0);
//    SimpleAudioEngine::getInstance()->setEffectsVolume(1.0);
    
}

void saveGameInfo(){
   
}

int getCurrentTime(){
    time_t t = time(0);
    struct tm * now = localtime(&t);
    int crtTime = now->tm_mon*(30*24*3600)+now->tm_mday*(24*3600)+now->tm_hour*3600+now->tm_min*60+now->tm_sec;

    return crtTime;

    //    return now->tm_gmtoff;// crtTime;
}
