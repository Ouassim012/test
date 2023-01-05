#pragma once
#ifndef __WINER2_H__
#define __WINER2_H__
#include "cocos2d.h"
#include "physics/CCPhysicsWorld.h"
#include "physics-nodes/CCPhysicsSprite.h"
#include "physics/CCPhysicsContact.h"
#include "Box2D/Box2D.h"
#include "Box2D/Dynamics/b2WorldCallbacks.h"
#include <iostream>

using namespace cocos2d;

USING_NS_CC;

class Win2 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init() override;
	CREATE_FUNC(Win2);

	cocos2d::Sprite* backgroundSpriteArray;
private:
	void next2(Ref* pSender);
	void GoToMainMenuScene(Ref* pSender);
	void Retry(Ref* pSender);

	void buttonPressed();












};
#endif