#pragma once
#include "cocos2d.h"
#include "Setting.h"
USING_NS_CC;
class Hero :public Sprite
{
public:
	static Hero* create(Node* parent, Vec2 pos, short int hero_tag, short int hero_index = -1, Node* scene = nullptr);
    void runAction_hero(const char* name, float speed = 3.7);

    const char* hero_walk_right_str = "hero_walk_right";
    const char* hero_stand_right_str = "hero_stand_right";
    const char* hero_stand_left_str = "hero_stand_left";
    const char* hero_walk_left_str = "hero_walk_left";
    //Sprite* blood = nullptr;
    //Sprite* head_frame = nullptr;
    status_hero hero_status = STAND;
    bool isinjured = false;
    float injured_interval = 0;
    int blood = 100;
    Vec2 init_pos;
};

