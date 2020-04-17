#include <GameOverScene.h>
//#include "MainMenu.h"
#include "GameScene.h"

USING_NS_CC;
Scene* GameOverScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOverScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameOverScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto spBackGround0 = Sprite::create("menubackground0.png");
	spBackGround0->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	spBackGround0->setScale(1.5);
	addChild(spBackGround0);


	auto menuItemTry = MenuItemFont::create("Try your luck again", CC_CALLBACK_1(GameOverScene::menuCallBack1, this));
	menuItemTry->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - visibleSize.height/2));
	menuItemTry->setTag(0x21);

//	auto menuItemReturn = MenuItemFont::create("Return to menu", CC_CALLBACK_1(GameOverScene::menuCallBack1, this));
//	menuItemTry->setPosition(Vec2(visibleSize.width / 2, visibleSize.height ));
//	menuItemTry->setTag(0x22);

//	auto menu = Menu::create(menuItemTry, menuItemReturn, nullptr);
	auto menu = Menu::create(menuItemTry, nullptr);
	menu->setPosition(Vec2::ZERO);
	menu->setColor(Color3B(222, 180, 34));
	addChild(menu);


	return true;
}

void GameOverScene::menuCallBack1(Ref *object)
{
	auto target = dynamic_cast<Node*>(object);
	Scene *scene = nullptr;
	switch (target->getTag())
	{
	case 0x21:
		scene = GameScene::createScene();
		break;
//	case 0x22:
//		scene = MainMenu::createScene();
//		break;

	default:
		return;
		break;
	}
	Director::getInstance()->replaceScene(scene);
}