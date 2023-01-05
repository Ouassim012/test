



#include"GameScene.h"

#include"GameOverScene.h"
#include"MainMenuScene.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace ui;
USING_NS_CC_EXT;

USING_NS_CC;
Scene* GameOver::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOver::create();
	scene->addChild(layer);
	return scene;
}
bool GameOver::init()
{

	if (!Layer::init())
	{
		return false;

	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	



	ui::Button* btnresume = ui::Button::create("mainmenuvolc.png");
	btnresume->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.6));
	btnresume->addTouchEventListener(CC_CALLBACK_1(GameOver::GoToMainMenuScene, this));
	btnresume->setScale(0.6);
	this->addChild(btnresume, 1);

	ui::Button* btnrestart = ui::Button::create("restartvolc.png");
	btnrestart->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.4));
	btnrestart->addTouchEventListener(CC_CALLBACK_1(GameOver::Retry, this));
	btnrestart->setScale(0.6);
	this->addChild(btnrestart, 1);







	auto backgroundSprite = Sprite::create("gameover.png"); /*background for the main menu*/
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);
	float rx = visibleSize.width / backgroundSprite->getContentSize().width;
	float ry = visibleSize.height / backgroundSprite->getContentSize().height;

	backgroundSprite->setScaleX(rx);
	backgroundSprite->setScaleY(ry);
	


	return true;


}



void GameOver::GoToMainMenuScene(cocos2d::Ref* pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameOver::Retry(cocos2d::Ref* pSender)
{
	auto scene = GameScreen::createScene();
	Director::getInstance()->replaceScene(scene);
}