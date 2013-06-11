//
//  Apache License
//    Version 2.0, January 2004
//  http://www.apache.org/licenses/
//

#include "LXTouchGesturing.h"


LXTouchGesturing::LXTouchGesturing()
{
    this->isTouching = false;
    this->isTouchSwipeFlickHandled = false;
    this->touchStartedTime = -1;
}


/***************
 * Private Methods
 */
long LXTouchGesturing::millisecondNow()
{
    struct cc_timeval now;
    CCTime::gettimeofdayCocos2d(&now, NULL);
    return (now.tv_sec * 1000 + now.tv_usec / 1000);
}


void LXTouchGesturing::update(float delta)
{
    long now = this->millisecondNow();
    if( this->isTouching ) {
        // LongTapped Handling Detect
        if( !this->isTouchLongHandled && LONG_TOUCH_EVENT_HANDLE_MILLISECOND <= (now - this->touchStartedTime) ) {
            this->lxTouchLongTapped(this->latest_pTouch, this->latest_pEvent);
            this->isTouchLongHandled = true;
            
        }
    }
}

/***************
 * Override TouchEventHandlers
 */
bool LXTouchGesturing::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    this->latest_pEvent = pEvent;
    this->latest_pTouch = pTouch;
    this->isTouching = true;
    this->touchStartedTime = this->millisecondNow();
    this->touchStartPoint = pTouch->getLocation();
    
    return true;
}

void LXTouchGesturing::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    this->latest_pEvent = pEvent;
    this->latest_pTouch = pTouch;
    
    // SwipeFlicked Handling Detect
    float migration = ccpDistance(this->touchStartPoint, pTouch->getLocation());
    if( !this->isTouchSwipeFlickHandled && migration >= SWIPE_FLICK_EVENT_HANDLE_DISTANCE ) {
        float angle = CC_RADIANS_TO_DEGREES(
                                atan2(
                                      (this->touchStartPoint.x - pTouch->getLocation().x),
                                      (this->touchStartPoint.y - pTouch->getLocation().y)
                                )
                        );
        this->isTouchSwipeFlickHandled = true;
        this->lxTouchSwipeFlicked(angle, this->latest_pTouch, this->latest_pEvent);
    }
}

void LXTouchGesturing::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    this->latest_pEvent = pEvent;
    this->latest_pTouch = pTouch;
    this->isTouching = false;
    this->isTouchLongHandled = false;
    this->isTouchSwipeFlickHandled = false;
    
}

void LXTouchGesturing::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    this->isTouchLongHandled = false;
    this->isTouching = false;
    this->isTouchSwipeFlickHandled = false;
}
