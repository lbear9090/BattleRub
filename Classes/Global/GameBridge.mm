//
//  GameBridge.mm
//  MatchEmUp
//
//  Created by Mary Rowe on 2015-12-10.
//
//

#include "GameBridge.h"
#import "AppController.h"
//#import "MKStoreManager.h"

bool GameBridge::showInterstitial(){
    AppController* delegate=(AppController*)[[UIApplication sharedApplication] delegate];
    return [delegate showInterstitial];
}

void GameBridge::showLeaderboard(){
    AppController* delegate=(AppController*)[[UIApplication sharedApplication] delegate];
    [delegate showLeaderboard];
}
void GameBridge::submitScore(int score){
    AppController* delegate=(AppController*)[[UIApplication sharedApplication] delegate];
    [delegate submitScore:score];
//
}

/*void GameBridge::showMoreGame(){
    AppController* app=(AppController*)[UIApplication sharedApplication].delegate;
    [app showMoreGame];
}
void GameBridge::showRateUs(){
    AppController* app=(AppController*)[UIApplication sharedApplication].delegate;
    [app showRate];
    
}
void GameBridge::showShareApp(const char* cash){
    AppController* app=(AppController*)[UIApplication sharedApplication].delegate;
    [app showAirDrop:cash];
    
}
void GameBridge::iapDoubleCashBalance(){
    [[MKStoreManager sharedManager] purchaseDoubleCashBalance];
}
void GameBridge::iapDoubleEarningRate(){
    [[MKStoreManager sharedManager] purchaseDoubleErningRate];
    
}
void GameBridge::iapCashBlast(){
    [[MKStoreManager sharedManager] purchaseCashBlast];
    
}
void GameBridge::iapInsaneBlast(){
    [[MKStoreManager sharedManager] purchaseInsaneBlast];
    
}
*/
