//
//  StartScene.h
//  MagicBox
//
//  Created by Pang Zhenyu on 13-10-12.
//
//

#ifndef __MagicBox__StartScene__
#define __MagicBox__StartScene__


#include "cocos2d.h"


class StartScene : public cocos2d::CCLayer
{
public:
	static cocos2d::CCScene* scene();
	
	virtual bool init();
	
	void menuHandler(CCObject* pSender);
	
	CREATE_FUNC(StartScene);
};

#endif /* defined(__MagicBox__StartScene__) */

