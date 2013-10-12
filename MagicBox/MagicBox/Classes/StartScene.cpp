//
//  StartScene.cpp
//  MagicBox
//
//  Created by Pang Zhenyu on 13-10-12.
//
//

#include "StartScene.h"
#include "GameScene.h"

using namespace cocos2d;


CCScene* StartScene::scene()
{
	CCScene* scene = CCScene::create();
	
	StartScene* layer = StartScene::create();
	
	scene->addChild(layer);
	
	return scene;
}


bool StartScene::init()
{
	if (!CCLayer::init())
		return false;
	
	CCMenuItemFont::setFontName("Arial");
	CCMenuItemFont::setFontSize(25);
	
	CCMenuItemFont* startMi = CCMenuItemFont::create("Start", this, menu_selector(StartScene::menuHandler));
	startMi->setTag(0);
	CCMenuItemFont* optionMi = CCMenuItemFont::create("Option", this, menu_selector(StartScene::menuHandler));
	optionMi->setTag(1);
	CCMenuItemFont* helpMi = CCMenuItemFont::create("Help", this, menu_selector(StartScene::menuHandler));
	helpMi->setTag(2);
	
	CCMenu* pMenu = CCMenu::create(startMi, optionMi, helpMi, NULL);
	pMenu->alignItemsVertically();
	this->addChild(pMenu);
	
	return true;
}


void StartScene::menuHandler(CCObject* pSender)
{
	int tag = ((CCNode*)pSender)->getTag();
	switch (tag)
	{
		case 0:
			CCDirector::sharedDirector()->replaceScene(GameScene::scene());
			break;
			
		default:
			printf("Tap on %d\n", tag);
			break;
	}
}


