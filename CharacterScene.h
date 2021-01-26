#pragma once

#include "cocos2d.h"
#include "Hero.h"

USING_NS_CC;

class CharacterScene : public Scene
{
public:
	static Scene* createScene();
	virtual bool init();
	virtual void onEnterTransitionDidFinish() override;
	short int hero_index = 0;
	void onKeyAClick();
	void onKeyDClick();

	TMXTiledMap* game_map = nullptr;
	std::vector<Hero*> heros;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	CREATE_FUNC(CharacterScene);
};

