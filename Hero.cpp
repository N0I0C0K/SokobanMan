#include "Hero.h"

Hero* Hero::create(Node* parent, Vec2 pos,short int hero_tag, short int hero_index, Node* scene)
{
    short int hero_index_ = hero_index;
    if (hero_index_ == -1) {
        hero_index_ = Setting::getInstance()->hero_index;
    }
    auto stand_left_png = String::createWithFormat("character/hero_%d_stand_left.png", hero_index_)->_string;
    auto stand_right_png = String::createWithFormat("character/hero_%d_stand_right.png", hero_index_)->_string;
    auto walk_left_png = String::createWithFormat("character/hero_%d_walk_left.png", hero_index_)->_string;
    auto walk_right_png = String::createWithFormat("character/hero_%d_walk_right.png", hero_index_)->_string;

    auto cache = Director::getInstance()->getTextureCache()->addImage(stand_right_png);
    Hero* hero = new Hero();
    auto cache_size = cache->getContentSize();
    int width = cache_size.width / 4;
    int hight = cache_size.height;
    if (!hero->initWithTexture(cache, Rect(0, 0, width, hight))) {
        return nullptr;
    }
    //auto hero = Sprite::createWithTexture(cache, Rect(0, 0, 192, 192));
    hero->setAnchorPoint(Vec2(1, 0));
    hero->setPosition(pos);
    hero->init_pos = pos;
    hero->setAnchorPoint(Vec2(0, 0));
    parent->addChild(hero, 2, hero_tag);
    //objects_tag.push_back(hero_tag);

    /*auto visualSize = Director::getInstance()->getVisibleSize();
    hero->head_frame = Sprite::create("UI/head_frame.png");
    hero->head_frame->setAnchorPoint(Vec2(0, 1));
    hero->setPosition(0, visualSize.height);*/

    auto hero_stand = Animation::create();
    for (int i = 0; i < 4; i++) {
        hero_stand->addSpriteFrameWithTexture(cache, Rect(i * width, 0, width, hight));
    }
    hero_stand->setDelayPerUnit(0.2f);
    hero_stand->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(hero_stand, hero->hero_stand_right_str);
    auto action_hero_stand = Animate::create(hero_stand);
    hero->runAction(RepeatForever::create(action_hero_stand));

    cache = Director::getInstance()->getTextureCache()->addImage(stand_left_png);
    auto hero_stand_left = Animation::create();
    for (int i = 0; i < 4; i++) {
        hero_stand_left->addSpriteFrameWithTexture(cache, Rect(i * width, 0, width, hight));
    }
    hero_stand_left->setDelayPerUnit(0.2f);
    hero_stand_left->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(hero_stand_left, hero->hero_stand_left_str);

    cache = Director::getInstance()->getTextureCache()->addImage(walk_right_png);
    auto hero_walk_right = Animation::create();
    for (int i = 1; i < 8; i++) {
        hero_walk_right->addSpriteFrameWithTexture(cache, Rect(i * width, 0, width, hight));
    }
    hero_walk_right->setDelayPerUnit(0.2f);
    hero_walk_right->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(hero_walk_right, hero->hero_walk_right_str);
    //hero->runAction(RepeatForever::create(action_hero_walk));


    cache = Director::getInstance()->getTextureCache()->addImage(walk_left_png);
    auto hero_walk_left = Animation::create();
    for (int i = 1; i < 8; i++) {
        hero_walk_left->addSpriteFrameWithTexture(cache, Rect(i * width, 0, width, hight));
    }
    hero_walk_left->setDelayPerUnit(0.2f);
    hero_walk_left->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(hero_walk_left, hero->hero_walk_left_str);
	return hero;
}

void Hero::runAction_hero(const char* name, float speed)
{
    this->stopAllActions();
    auto animation = AnimationCache::getInstance()->getAnimation(name);
    animation->setDelayPerUnit((3.7 / abs(speed)) * 0.15f);
    auto action = Animate::create(animation);
    this->runAction(RepeatForever::create(action));
}
