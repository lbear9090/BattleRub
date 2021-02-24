//
//  GameConfig.h
//  BattleRub
//
//  Created by Lucky
//
//

#ifndef __GameConfig__
#define __GameConfig__

#include "cocos2d.h"
#include "AudioEngine.h"

using namespace cocos2d;
using namespace std;
using namespace StringUtils;

extern bool g_bSoundOn;
extern int g_nScore;
extern int g_nHighScore;
extern bool g_bShownAD;
extern Layer *g_layerGame;

void loadGameInfo();
void saveGameInfo();

int getCurrentTime();

#endif
