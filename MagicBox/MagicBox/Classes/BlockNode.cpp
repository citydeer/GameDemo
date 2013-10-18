//
//  BlockNode.cpp
//  MagicBox
//
//  Created by Pang Zhenyu on 13-10-18.
//
//

#include "BlockNode.h"


bool BlockNode::init()
{
	if (!CCNodeRGBA::init())
		return false;
	
	setContentSize(CCSizeMake(30, 30));
	setColor(ccc3(226, 206, 117));
	m_sBorderColor = ccc4(250, 250, 250, 255);
	
	return true;
}

void BlockNode::draw()
{
	CHECK_GL_ERROR_DEBUG();
	
	CCSize sz = getContentSize();
	ccDrawColor4B(m_sBorderColor.r, m_sBorderColor.g, m_sBorderColor.b, m_sBorderColor.a);
	ccDrawRect(ccp(1, 1), ccp(sz.width-1, sz.height-1));
	ccDrawSolidRect(ccp(3, 3), ccp(sz.width-3, sz.height-3), ccc4FFromccc4B(m_sBorderColor));
}

void BlockNode::setBorderColer(ccColor4B color)
{
	m_sBorderColor = color;
}
