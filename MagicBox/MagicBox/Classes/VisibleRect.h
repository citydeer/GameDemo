#ifndef __VISIBLERECT_H__
#define __VISIBLERECT_H__

#include "cocos2d.h"
USING_NS_CC;



#define CDVLeft (VisibleRect::getVisibleRect().origin.x)
#define CDVRight (VisibleRect::rightBottom().x)
#define CDVTop (VisibleRect::top().y)
#define CDVBottom (VisibleRect::getVisibleRect().origin.y)
#define CDVWidth (VisibleRect::getVisibleRect().size.width)
#define CDVHeight (VisibleRect::getVisibleRect().size.height)


class VisibleRect
{
public:
	static CCRect getVisibleRect();
	
	static CCPoint left();
	static CCPoint right();
	static CCPoint top();
	static CCPoint bottom();
	static CCPoint center();
	static CCPoint leftTop();
	static CCPoint rightTop();
	static CCPoint leftBottom();
	static CCPoint rightBottom();
private:
	static void lazyInit();
	static CCRect s_visibleRect;
};

#endif /* __VISIBLERECT_H__ */
