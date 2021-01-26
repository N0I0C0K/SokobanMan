#pragma once

#include"cocos2d.h"

USING_NS_CC;

enum direction {
	UP,
	LEFT,
	DOWN,
	RIGHT
};

class Obstacle
{
public:
	virtual ~Obstacle();
	virtual void update(Node* node) = 0;

};

class laser //:public Obstacle
{
public:
	laser(Vec2 startpos,Vec2 endpos, float speed, const char *filename, direction dir, Vec2 start_pos, float zoom = 1.0);
	laser(Rect laser_rect, float speed, const char* filename, direction dir, Vec2 start_pos, float zoom = 1.0);
	void update();
	bool isCollided(Rect rect);
	void addtoNode(Node* node, int tag = 0);
	Sprite* sprite;
	float speed;
	int tag;
	Vec2 startpos;
	Vec2 endpos;
	direction dir;
};

