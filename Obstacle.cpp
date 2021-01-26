#include "Obstacle.h"

laser::laser(Vec2 startpos, Vec2 endpos, float speed, const char* filename, direction dir, Vec2 start_pos, float zoom)
{
	this->startpos = startpos;
	this->endpos = endpos;
	this->speed = speed;
	this->dir = dir;
	this->sprite = Sprite::create(filename);
	this->sprite->setScaleY(zoom);
	switch (dir)
	{
	case UP:
		this->sprite->setRotation(90);
		break;
	case LEFT:
		break;
	case DOWN:
		this->sprite->setRotation(90);
		break;
	case RIGHT:
		
		break;
	}
	this->sprite->setAnchorPoint(Vec2(0, 0));
	this->sprite->setPosition(start_pos);
}

laser::laser(Rect laser_rect, float speed, const char* filename, direction dir, Vec2 start_pos_offset, float zoom)
{
	this->speed = speed;
	this->dir = dir;
	this->sprite = Sprite::create(filename);
	this->sprite->setScaleY(zoom);
	switch (dir)
	{
	case UP:
		this->startpos = Vec2(laser_rect.getMinX(), laser_rect.getMinY());
		this->endpos = Vec2(laser_rect.getMinX(), laser_rect.getMaxY());
		this->sprite->setRotation(90);
		break;
	case LEFT:
		this->startpos = Vec2(laser_rect.getMaxX(), laser_rect.getMinY());
		this->endpos = Vec2(laser_rect.getMinX(), laser_rect.getMinY());
		break;
	case DOWN:
		this->startpos = Vec2(laser_rect.getMinX(), laser_rect.getMaxY());
		this->endpos = Vec2(laser_rect.getMinX(), laser_rect.getMinY());
		this->sprite->setRotation(90);
		break;
	case RIGHT:
		this->startpos = Vec2(laser_rect.getMinX(), laser_rect.getMinY());
		this->endpos = Vec2(laser_rect.getMaxX(), laser_rect.getMinY());
		break;
	}
	this->sprite->setAnchorPoint(Vec2(0, 0));
	this->sprite->setPosition(this->startpos+start_pos_offset);
}

void laser::update()
{
	assert(this->sprite != nullptr);
	float y;
	float x;
	switch (dir)
	{
	case UP:
		y = startpos.y + int(sprite->getPosition().y + speed - startpos.y) % int(endpos.y - startpos.y);
		sprite->setPosition(Vec2(startpos.x, y));
		break;
	case LEFT:
		x = startpos.x - int(startpos.x - (sprite->getPosition().x - speed)) % int(startpos.x - endpos.x);
		sprite->setPosition(Vec2(x, startpos.y));
		break;
	case DOWN:
		y = startpos.y - int(startpos.y - (sprite->getPosition().y - speed)) % int(startpos.y - endpos.y);
		sprite->setPosition(Vec2(startpos.x, y));
		break;
	case RIGHT:
		x = startpos.x + int(sprite->getPosition().x + speed - startpos.x) % int(endpos.x - startpos.x);
		sprite->setPosition(Vec2(x, startpos.y));
		break;
	default:
		break;
	}
}

bool laser::isCollided(Rect rect)
{
	if (this->sprite->getBoundingBox().intersectsRect(rect)) {
		return true;
	}
	return false;
}

void laser::addtoNode(Node* node, int tag)
{
	if (tag != 0) {
		node->addChild(this->sprite);
		this->tag = tag;
		return;
	}
	node->addChild(this->sprite);
}
