//
//  GameScene.h
//  MagicBox
//
//  Created by Pang Zhenyu on 13-10-12.
//
//

#ifndef __MagicBox__GameScene__
#define __MagicBox__GameScene__

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public CCLayer
{
public:
	static CCScene* scene();
	
	virtual ~GameScene();
	
	CREATE_FUNC(GameScene);
	
	virtual void onEnter();
	
	void startGame();
	void gameOver();
	
	virtual void draw();
	
protected:
	void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	
private:
	int m_iStatus;
	
	CCRect m_sMoveRect;
};



class GameOverScene : public CCLayer
{
public:
	virtual bool init();
	
	CREATE_FUNC(GameOverScene);
	
	void onRestart(CCObject* pSender);
	void onBack(CCObject* pSender);
};


#endif /* defined(__MagicBox__GameScene__) */


