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


class GameScene : public cocos2d::CCLayer
{
public:
	static cocos2d::CCScene* scene();
	
	virtual ~GameScene();
	
	virtual bool init();
	
	CREATE_FUNC(GameScene);
	
	void startGame();
	void gameOver();
	
protected:
	void shakerMoveEnded(CCNode* pNode);
	void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	
private:
	cocos2d::CCSprite* m_pShaker;
	
	cocos2d::CCSprite* m_pShadow;
	
	int m_iScore;
	int m_iStatus;
	int m_iHits;
	bool m_bHitInPreviousCircle;
	
	float m_fOffset;
};



class GameOverScene : public cocos2d::CCLayer
{
public:
	virtual bool init();
	
	CREATE_FUNC(GameOverScene);
	
	void onRestart(CCObject* pSender);
	void onBack(CCObject* pSender);
};


#endif /* defined(__MagicBox__GameScene__) */


