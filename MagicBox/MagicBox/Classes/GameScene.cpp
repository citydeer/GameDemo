//
//  GameScene.cpp
//  MagicBox
//
//  Created by Pang Zhenyu on 13-10-12.
//
//

#include "GameScene.h"
#include "StartScene.h"
#include "SimpleAudioEngine.h"
#include "VisibleRect.h"


#define BlockWidth 30.0f
#define LeftMargin 10.0f
#define BottomMargin 30.0f

CCScene* GameScene::scene()
{
	CCScene* scene = CCScene::create();
	
	GameScene* layer = GameScene::create();
	
	scene->addChild(layer);
	
	return scene;
}

GameScene::~GameScene()
{
}

void GameScene::onEnter()
{
	CCLayer::onEnter();
	
	m_iStatus = 0;
	
	this->setTouchEnabled(true);
	m_sMoveRect = CCRectMake(CDVLeft+LeftMargin, CDVBottom+BottomMargin, CDVWidth-LeftMargin*2, CDVHeight-BottomMargin);
	
	this->startGame();
}

void GameScene::draw()
{
	CHECK_GL_ERROR_DEBUG();
	
	ccColor4F borderColor = {114/255.0, 108/255.0, 197/255.0, 200/255.0};
	ccDrawSolidRect(VisibleRect::leftTop(), ccp(m_sMoveRect.getMinX(), CDVBottom), borderColor);
	ccDrawSolidRect(ccp(m_sMoveRect.getMaxX(), CDVTop), VisibleRect::rightBottom(), borderColor);
	ccDrawSolidRect(m_sMoveRect.origin, ccp(m_sMoveRect.getMaxX(), CDVBottom), borderColor);
	
	CHECK_GL_ERROR_DEBUG();
}

void GameScene::startGame()
{
	m_iStatus = 1;
}

void GameScene::gameOver()
{
	m_iStatus = 0;
	this->addChild(GameOverScene::create(), 3);
}

void GameScene::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	// If not in game, return.
	if (m_iStatus == 0)
		return;
}




bool GameOverScene::init()
{
	if (!CCLayer::init())
		return false;
	
	CCLayerColor* bg = CCLayerColor::create(ccc4(0, 0, 0, 128), 200, 300);
	bg->ignoreAnchorPointForPosition(false);
	bg->setPosition(VisibleRect::center());
	this->addChild(bg, 0);
	
	CCMenuItemFont::setFontName("Marker Felt");
	CCMenuItemFont::setFontSize(30);
	
	CCMenuItem* restart = CCMenuItemFont::create("Restart", this, menu_selector(GameOverScene::onRestart));
	CCMenuItem* back = CCMenuItemFont::create("Back", this, menu_selector(GameOverScene::onBack));
	CCMenu* menu = CCMenu::create(restart, back, NULL);
	menu->alignItemsVertically();
	this->addChild(menu, 1);
	
	return true;
}

void GameOverScene::onRestart(cocos2d::CCObject *pSender)
{
	static_cast<GameScene*>(this->getParent())->startGame();
	this->removeFromParent();
}

void GameOverScene::onBack(cocos2d::CCObject *pSender)
{
	CCDirector::sharedDirector()->replaceScene(StartScene::scene());
}

