#include"Winer3.h"
#include"GameScene3.h"
#include"GameScene.h"
#include"MainMenuScene.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace ui;
USING_NS_CC_EXT;

USING_NS_CC;
Scene* Win3::createScene()
{
	auto scene = Scene::create();
	auto layer = Win3::create();
	scene->addChild(layer);
	return scene;
}
bool Win3::init()
{

	if (!Layer::init())
	{
		return false;

	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();










	ui::Button* btnrestart = ui::Button::create("restart.png");
	btnrestart->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.6));
	btnrestart->addTouchEventListener(CC_CALLBACK_1(Win3::Retry, this));
	btnrestart->setScale(0.6);
	this->addChild(btnrestart, 1);


	ui::Button* btnmain = ui::Button::create("mainmenu.png");
	btnmain->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.4));
	btnmain->addTouchEventListener(CC_CALLBACK_1(Win3::GoToMainMenuScene, this));
	btnmain->setScale(0.6);
	this->addChild(btnmain, 1);




	auto backgroundSprite = Sprite::create("win.png"); /*background for the main menu*/
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);

	float rx = visibleSize.width / backgroundSprite->getContentSize().width;
	float ry = visibleSize.height / backgroundSprite->getContentSize().height;

	backgroundSprite->setScaleX(rx);
	backgroundSprite->setScaleY(ry);



	return true;


}
void Win3::buttonPressed() {
	Scene* scene = GameScreen::createScene();
	TransitionFade* transition = TransitionFade::create(1, scene);
	Director::getInstance()->replaceScene(transition);

}


void Win3::GoToMainMenuScene(cocos2d::Ref* pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Win3::Retry(cocos2d::Ref* pSender)
{
	auto scene = GameScreen3::createScene();
	Director::getInstance()->replaceScene(scene);
}