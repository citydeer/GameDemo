//
//  BlockNode.h
//  MagicBox
//
//  Created by Pang Zhenyu on 13-10-18.
//
//

#ifndef __MagicBox__BlockNode__
#define __MagicBox__BlockNode__

#include "cocos2d.h"
USING_NS_CC;

class BlockNode : public CCNodeRGBA
{
public:
	CREATE_FUNC(BlockNode);
	
	virtual bool init();
	
	virtual void draw();
	
	void setBorderColer(ccColor4B color);
	
private:
	ccColor4B m_sBorderColor;
};

#endif /* defined(__MagicBox__BlockNode__) */
