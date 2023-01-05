#include"GameScene3.h"
#include"Winer3.h"
#include"PauseScene.h"
#include"GameOverScene.h"
#include"MainMenuScene.h"
#include<iostream>
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace ui;
using namespace cocos2d;
USING_NS_CC;
Scene* GameScreen3::createScene()
{
	auto scene = Scene::createWithPhysics();
	PhysicsWorld* world = scene->getPhysicsWorld();
	auto gravity = Vec2(0, -10.0f);
	world->setGravity(gravity);


	auto layer = GameScreen3::create();
	scene->addChild(layer);

	return scene;
}

bool GameScreen3::init()
{

	if (!Layer::init())
	{
		return false;

	}


	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	ui::Button* btnresume = ui::Button::create("pausebut.png");
	btnresume->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height * 1));
	btnresume->addTouchEventListener(CC_CALLBACK_1(GameScreen3::GoToPauseScene, this));
	btnresume->setScale(0.6);
	this->addChild(btnresume, 1);


	auto backgroundSprite = Sprite::create("BG_02.png"); /*background for the main menu*/
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);
	float rx = visibleSize.width / backgroundSprite->getContentSize().width;
	float ry = visibleSize.height / backgroundSprite->getContentSize().height;

	backgroundSprite->setScaleX(rx);
	backgroundSprite->setScaleY(ry);

	

	 player = Sprite::create("pilot.png");
	player->setPosition((Vec2(visibleSize.width * 0.1, visibleSize.height * 0.5)));
	player->setScale(0.5); //scale dyal player
	player->setName("player");
	auto physicsBody1 = PhysicsBody::createBox(player->getContentSize() / 1.5, PhysicsMaterial(1.0f, 1.0f, 1.0f));
	physicsBody1->setGravityEnable(true);
	physicsBody1->setDynamic(true);
	player->setPhysicsBody(physicsBody1);

	this->addChild(player, 1);


	//  creating physique for player

	floor = Sprite::create("floor.png");

	floor->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.1));
	this->addChild(floor, 1);
	floor->setScaleX(3);

	//creating physique for THE FLOOR

	auto physicsBody_floor = PhysicsBody::createBox(floor->getContentSize(), PhysicsMaterial(1.0f, 0.0f, 1.0f));

	physicsBody_floor->setDynamic(false);



	floor->setPhysicsBody(physicsBody_floor);





	knz = Sprite::create("golf.png");
	knz->setPosition((Vec2(visibleSize.width * 5, visibleSize.height * 0.8)));
	knz->setScale(0.400);
	auto physicsBody11 = PhysicsBody::createBox(knz->getContentSize() / 1.5, PhysicsMaterial(1.0f, 1.0f, 1.0f));
	physicsBody11->setGravityEnable(true);
	physicsBody11->setDynamic(false);

	knz->setRotation(0.0f);
	knz->setPhysicsBody(physicsBody11);

	this->addChild(knz, 1);

	//
	obstacle1 = Sprite::create("rock1.png");
	obstacle1->setPosition((Vec2(visibleSize.width * 1.2, visibleSize.height * 0.2)));
	obstacle1->setScale(0.200);
	this->addChild(obstacle1, 1);
	auto physicsBody_obstacle1 = PhysicsBody::createBox(obstacle1->getContentSize(), PhysicsMaterial(1.0f, 1.0f, 1.0f));

	physicsBody_obstacle1->setDynamic(true);

	obstacle1->setPhysicsBody(physicsBody_obstacle1);


	ghost = Sprite::create("ghost.png");
	ghost->setPosition((Vec2(visibleSize.width * 1.5, visibleSize.height * 0.25)));
	ghost->setScale(0.650);
	this->addChild(ghost, 1);
	auto physicsBody_obstacle12 = PhysicsBody::createBox(ghost->getContentSize(), PhysicsMaterial(1.0f, 1.0f, 1.0f));

	physicsBody_obstacle12->setDynamic(false);

	ghost->setPhysicsBody(physicsBody_obstacle12);



	ghost1= Sprite::create("ghost.png");
	ghost1->setPosition((Vec2(visibleSize.width * 1, visibleSize.height * 1)));
	ghost1->setScale(0.650);
	this->addChild(ghost1, 1);
	auto physicsBody_obstacle121 = PhysicsBody::createBox(ghost1->getContentSize(), PhysicsMaterial(1.0f, 1.0f, 1.0f));

	physicsBody_obstacle121->setDynamic(false);

	ghost1->setPhysicsBody(physicsBody_obstacle121);
	//



	


	auto eventListener = EventListenerKeyboard::create();

	eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

		Vec2 loc = event->getCurrentTarget()->getPosition();
		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			event->getCurrentTarget()->runAction(MoveBy::create(0.1, Vec2(-10, 0)));
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			event->getCurrentTarget()->runAction(MoveBy::create(0.1, Vec2(10, 0)));
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
			event->getCurrentTarget()->runAction(JumpBy::create(1.4, Vec2(0, 100), 50, 1));
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		case EventKeyboard::KeyCode::KEY_O:
			event->getCurrentTarget()->runAction(MoveBy::create(2.0, Vec2(0, -100)));
			break;
		
	
		}
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, player);






	this->scheduleUpdate();




	return true;

}


void GameScreen3::update(float dt) {


	Size visibleSize = Director::getInstance()->
		getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	if (player != NULL) {
		player->setRotation(0.0f);
	}


	Rect joueur = player->getBoundingBox();
	Rect fontome = ghost->getBoundingBox();

	if (joueur.intersectsRect(fontome))
	{
		auto scene = GameOver::createScene();
		Director::getInstance()->replaceScene(scene);
	}


	Rect joueur1 = player->getBoundingBox();
	Rect floor1 = floor->getBoundingBox();

	if (joueur1.intersectsRect(floor1))
	{
		auto scene = GameOver::createScene();
		Director::getInstance()->replaceScene(scene);
	}

	Rect joueur2 = player->getBoundingBox();
	Rect fontome1 = ghost1->getBoundingBox();

	if (joueur2.intersectsRect(fontome1))
	{
		auto scene = GameOver::createScene();
		Director::getInstance()->replaceScene(scene);
	}

	Rect joueur3 = player->getBoundingBox();
	Rect signe = knz->getBoundingBox();

	if (joueur3.intersectsRect(signe))
	{
		auto scene = Win3::createScene();
		Director::getInstance()->replaceScene(scene);
	}

	auto position = floor->getPosition();
	position.x -= 250 * dt;
	if (position.x < 0 - (floor->getBoundingBox().size.width / 2))
		position.x = this->getBoundingBox().getMaxX() + floor->getBoundingBox().size.width / 2;
	floor->setPosition(position);




	auto position3 = knz->getPosition();
	position3.x -= 250 * dt;
	if (position3.x < 0 - (knz->getBoundingBox().size.width / 2))
		position3.x = this->getBoundingBox().getMaxX() + knz->getBoundingBox().size.width / 2;
	knz->setPosition(position3);

	if (obstacle1 != NULL) {
		auto position4 = obstacle1->getPosition();
		position4.x -= 250 * dt;
		if (position4.x < 0 - (obstacle1->getBoundingBox().size.width / 2))
			position4.x = this->getBoundingBox().getMaxX() + obstacle1->getBoundingBox().size.width / 2;
		obstacle1->setPosition(position4);
	}

	if (floor->getPosition().x < -2300.0f) {
		auto scene = GameOver::createScene();
		Director::getInstance()->replaceScene(scene); 
	}

	auto position6 = ghost->getPosition();
	position6.x -= 250 * dt;
	if (position6.x < 0 - (ghost->getBoundingBox().size.width / 2))
		position6.x = this->getBoundingBox().getMaxX() + ghost->getBoundingBox().size.width / 2;
	ghost->setPosition(position6);

	auto position7 = ghost1->getPosition();
	position7.x -= 250 * dt;
	if (position7.x < 0 - (ghost1->getBoundingBox().size.width / 2))
		position7.x = this->getBoundingBox().getMaxX() + ghost1->getBoundingBox().size.width / 2;
	ghost1->setPosition(position7);

}

void GameScreen3::GoToPauseScene(cocos2d::Ref* pSender)
{
	auto scene = PauseMenu::createScene();
	Director::getInstance()->pushScene(scene);

}
void GameScreen3::GoToGameOverScene(cocos2d::Ref* pSender)
{
	auto scene = GameOver::createScene();
	Director::getInstance()->pushScene(scene);
}
void GameScreen3::buttonPressed() {
	Scene* scene = GameScreen3::createScene();
	TransitionFade* transition = TransitionFade::create(1, scene);
	Director::getInstance()->replaceScene(transition);

}