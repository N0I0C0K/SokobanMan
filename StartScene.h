#pragma once
#include "cocos2d.h"
#include "HelloWorldScene.h"

USING_NS_CC;

enum model
{
	SETTING,
	SIMPLE,
	HARD,
	VERYHARD,
	CHARACTER
};

class StartScene : public Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void update(float delta) override;

	void back_run();
	void onKeyAClick();
	void onKeyDClick();
	void onKeyEnterClick();

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	Vector<Label*> label_box;
	short int index = 2;
	Vec2 min_pos;



	CREATE_FUNC(StartScene);
};

