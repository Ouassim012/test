#include"PauseScene.h"
#include"GameScene.h"
#include"MainMenuScene.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace ui;
USING_NS_CC_EXT;

USING_NS_CC;
Scene* PauseMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = PauseMenu::create();
	scene->addChild(layer);
	return scene;
}
bool PauseMenu::init()
{

	if (!Layer::init())
	{
		return false;

	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	

	

	ui::Button* btnresume =  ui::Button::create("resume.png");
	btnresume->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.8));
	btnresume->addTouchEventListener(CC_CALLBACK_1(PauseMenu::Resume, this));
	btnresume->setScale(0.6);
	this->addChild(btnresume, 1);
	
	ui::Button* btnrestart = ui::Button::create("restart.png");
	btnrestart->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.6));
	btnrestart->addTouchEventListener(CC_CALLBACK_1(PauseMenu::Retry, this));
	btnrestart->setScale(0.6);
	this->addChild(btnrestart, 1);


	ui::Button* btnmain = ui::Button::create("mainmenu.png");
	btnmain->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.4));
	btnmain->addTouchEventListener(CC_CALLBACK_1(PauseMenu::GoToMainMenuScene, this));
	btnmain->setScale(0.6);
	this->addChild(btnmain, 1);

	
	


	auto backgroundSprite = Sprite::create("pause.jpg"); /*background for the main menu*/
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));

	float rx = visibleSize.width / backgroundSprite->getContentSize().width;
	float ry = visibleSize.height / backgroundSprite->getContentSize().height;

	backgroundSprite->setScaleX(rx);
	backgroundSprite->setScaleY(ry);
	this->addChild(backgroundSprite, -1);

	
	return true;


}
void PauseMenu::buttonPressed() {
	Scene* scene = GameScreen::createScene();
	TransitionFade* transition = TransitionFade::create(1, scene);
	Director::getInstance()->replaceScene(transition);

}

void PauseMenu::Resume(cocos2d::Ref* pSender)
{
	Director::getInstance()->popScene();
}
void PauseMenu::GoToMainMenuScene(cocos2d::Ref* pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

void PauseMenu::Retry(cocos2d::Ref* pSender)
{
	auto scene = GameScreen::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}