#include"Winer2.h"
#include"GameScene3.h"
#include"GameScene.h"
#include"GameScene2.h"
#include"MainMenuScene.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace ui;
USING_NS_CC_EXT;

USING_NS_CC;
Scene* Win2::createScene()
{
	auto scene = Scene::create();
	auto layer = Win2::create();
	scene->addChild(layer);
	return scene;
}
bool Win2::init()
{

	if (!Layer::init())
	{
		return false;

	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();








	ui::Button* btnresume = ui::Button::create("next.png");
	btnresume->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.8));
	btnresume->addTouchEventListener(CC_CALLBACK_1(Win2::next2, this));
	btnresume->setScale(0.6);
	this->addChild(btnresume, 1);

	ui::Button* btnrestart = ui::Button::create("restart.png");
	btnrestart->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.6));
	btnrestart->addTouchEventListener(CC_CALLBACK_1(Win2::Retry, this));
	btnrestart->setScale(0.6);
	this->addChild(btnrestart, 1);


	ui::Button* btnmain = ui::Button::create("mainmenu.png");
	btnmain->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.4));
	btnmain->addTouchEventListener(CC_CALLBACK_1(Win2::GoToMainMenuScene, this));
	btnmain->setScale(0.6);
	this->addChild(btnmain, 1);




	auto backgroundSprite = Sprite::create("pausescene.png"); /*background for the main menu*/
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);

	float rx = visibleSize.width / backgroundSprite->getContentSize().width;
	float ry = visibleSize.height / backgroundSprite->getContentSize().height;

	backgroundSprite->setScaleX(rx);
	backgroundSprite->setScaleY(ry);



	return true;


}
void Win2::buttonPressed() {
	Scene* scene = GameScreen::createScene();
	TransitionFade* transition = TransitionFade::create(1, scene);
	Director::getInstance()->replaceScene(transition);

}

void Win2::next2(cocos2d::Ref* pSender)
{
	auto scene = GameScreen3::createScene();
	Director::getInstance()->replaceScene(scene);
}
void Win2::GoToMainMenuScene(cocos2d::Ref* pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Win2::Retry(cocos2d::Ref* pSender)
{
	auto scene = GameScreen2::createScene();
	Director::getInstance()->replaceScene(scene);
}