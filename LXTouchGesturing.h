// *********************
//
// Cocos2d-x タッチジェスチャハンドリングクラス
// Cocos2d-x TouchGestruring Handle Class
//      LXTouchGesturing
//
// *********************
//
//  Apache License
//    Version 2.0, January 2004
//  http://www.apache.org/licenses/
//
// Copyright(c) 2013 liet.
// 使用する場合はGithubからAddStarしてくださいね^^
// If you use try this library, then please give "AddStar" from github.
// https://github.com/liet/LXTouchGesturing
//


#ifndef __LXTouchGesturing__
#define __LXTouchGesturing__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class LXTouchGesturing : public CCLayer {
    typedef CCLayer inherited;
    
private:
    // LongTouchをハンドリングする際のミリ秒閾値
    static const long LONG_TOUCH_EVENT_HANDLE_MILLISECOND = 1800.0;
    
    // Swipeイベントをハンドリングする際の距離閾値
    static const long SWIPE_FLICK_EVENT_HANDLE_DISTANCE = 100.0;
    
    // **************
    // 判定用変数群
    bool isTouching;
    bool isTouchLongHandled;
    bool isTouchSwipeFlickHandled;
    long touchStartedTime;
    CCTouch *latest_pTouch;
    CCEvent *latest_pEvent;
    CCPoint touchStartPoint;
    
    // 現在のミリ秒を取得する関数
    // @return long <現在の時刻ミリ秒>
    long millisecondNow();
    
    
public:
    // Constructor
    LXTouchGesturing();
    
    // ***************
    // CCLayer Override Methods
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    virtual void update(float delta);
    
    // ***************
    // Callback EventHandlers
    // 試用する場合はOverrideをお願いします。
    // Please use for override.
    
    // 長押しのイベントハンドラ
    virtual void lxTouchLongTapped(CCTouch *pTouch, CCEvent *pEvent){};
    
    // スワイプ・フリックのイベントハンドラ
    virtual void lxTouchSwipeFlicked(float degree, CCTouch *pTouch, CCEvent *pEvent){};
    
    // ピンチインのイベントハンドラ
    virtual void lxPinchIn(CCTouch *pTouch, CCEvent *pEvent){};
    
    // ピンチアウトのイベントハンドラ
    virtual void lxPinchOut(CCTouch *pTouch, CCEvent *pEvent){};
    
};

#endif /* defined(__inthetetris__LXTouchGesturing__) */
