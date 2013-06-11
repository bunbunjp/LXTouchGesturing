//
//  Apache License
//    Version 2.0, January 2004
//  http://www.apache.org/licenses/
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
    static const long LONG_TOUCH_EVENT_HANDLE_MILLISECOND = 1800.0;
    static const long SWIPE_FLICK_EVENT_HANDLE_DISTANCE = 100.0;
    
    long millisecondNow();
    bool isTouching;
    bool isTouchLongHandled;
    bool isTouchSwipeFlickHandled;
    
    long touchStartedTime;
    
    CCTouch *latest_pTouch;
    CCEvent *latest_pEvent;
    
    CCPoint touchStartPoint;
    
public:
    // Constructor
    LXTouchGesturing();
    
    /***
     * CCLayer Override Methods
     */
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    virtual void update(float delta);
    
    /***
     * Callback EventHandlers
     */
    virtual void lxTouchLongTapped(CCTouch *pTouch, CCEvent *pEvent){};
    virtual void lxTouchSwipeFlicked(float degree, CCTouch *pTouch, CCEvent *pEvent){};
    virtual void lxPinchIn(CCTouch *pTouch, CCEvent *pEvent){};
    virtual void lxPinchOut(CCTouch *pTouch, CCEvent *pEvent){};
    
};

#endif /* defined(__inthetetris__LXTouchGesturing__) */
