/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "Levelone.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

USING_NS_CC;

Scene* Levelone::createScene()
{
    return Levelone::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Levelone::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    /*auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(Levelone::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    */
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label


    game_map = TMXTiledMap::create("map/level_three.tmx");
    game_map->setAnchorPoint(Vec2(0, 0));
    //game_map->setPosition(Vec2(-(25*game_map->getTileSize().width)+visibleSize.width/2, -(15* game_map->getTileSize().height)+visibleSize.height/2));
    game_map->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2) - PositionForTileCoord(initialpos));
    if (game_map == nullptr) {

        problemLoading("map/level_three.tmx");
    }
    else {
        game_map->setVisible(false);
        this->addChild(game_map, 1);
    }
    initMap();
    initLaser();
    /*-------------------------------------º”‘ÿhero∫Õhero∂Øª≠---------------------------------------------------------------*/
    /*auto cache = Director::getInstance()->getTextureCache()->addImage("hero_one_stand_right.png");

    auto hero = Sprite::createWithTexture(cache, Rect(0, 0, 192, 192));
    hero->setAnchorPoint(Vec2(1, 0));
    hero->setPosition(PositionForTileCoord(initialpos) + Vec2(-70, 0));
    hero->setAnchorPoint(Vec2(0, 0));
    game_map->addChild(hero, 2, hero_tag);
    //objects_tag.push_back(hero_tag);

    auto hero_stand = Animation::create();
    for (int i = 0; i < 4; i++) {
        hero_stand->addSpriteFrameWithTexture(cache, Rect(i * 192, 0, 192, 192));
    }
    hero_stand->setDelayPerUnit(0.2f);
    hero_stand->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(hero_stand, hero_stand_right_str);
    auto action_hero_stand = Animate::create(hero_stand);
    hero->runAction(RepeatForever::create(action_hero_stand));

    cache = Director::getInstance()->getTextureCache()->addImage("hero_one_stand_left.png");
    auto hero_stand_left = Animation::create();
    for (int i = 0; i < 4; i++) {
        hero_stand_left->addSpriteFrameWithTexture(cache, Rect(i * 192, 0, 192, 192));
    }
    hero_stand_left->setDelayPerUnit(0.2f);
    hero_stand_left->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(hero_stand_left, hero_stand_left_str);

    cache = Director::getInstance()->getTextureCache()->addImage("hero_one_walk_right.png");
    auto hero_walk_right = Animation::create();
    for (int i = 1; i < 8; i++) {
        hero_walk_right->addSpriteFrameWithTexture(cache, Rect(i * 192, 0, 192, 192));
    }
    hero_walk_right->setDelayPerUnit(0.2f);
    hero_walk_right->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(hero_walk_right, hero_walk_right_str);
    //hero->runAction(RepeatForever::create(action_hero_walk));


    cache = Director::getInstance()->getTextureCache()->addImage("hero_one_walk_left.png");
    auto hero_walk_left = Animation::create();
    for (int i = 1; i < 8; i++) {
        hero_walk_left->addSpriteFrameWithTexture(cache, Rect(i * 192, 0, 192, 192));
    }
    hero_walk_left->setDelayPerUnit(0.2f);
    hero_walk_left->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(hero_walk_left, hero_walk_left_str);*/
    //this->hero = Hero::create(game_map, PositionForTileCoord(initialpos), hero_tag);

    /*-------------------------------------------------------º”‘ÿbox--------------------------------------------------------------------*/
    /*Vector<Box*> box_8;
    Vector<Box*> box_4;
    int box_tag = 100;
    auto box2 = Box::create("kuai2.png", PositionForTileCoord(Vec2(10, 12)), "8", ++box_tag, game_map);
    boxes.pushBack(box2);
    objects_tag.push_back(box_tag);
    box_8.pushBack(box2);

    auto box3 = Box::create("kuai2.png", PositionForTileCoord(Vec2(10, 14)), "8", ++box_tag, game_map);
    boxes.pushBack(box3);
    objects_tag.push_back(box_tag);
    box_8.pushBack(box3);

    auto box = Box::create("kuai2.png", PositionForTileCoord(Vec2(10, 16)), "4", ++box_tag, game_map);
    boxes.pushBack(box);
    objects_tag.push_back(box_tag);
    box_4.pushBack(box);

    box = Box::create("kuai2.png", PositionForTileCoord(Vec2(10, 18)), "8", ++box_tag, game_map);
    boxes.pushBack(box);
    objects_tag.push_back(box_tag);
    box_8.pushBack(box);

    box = Box::create("kuai2.png", PositionForTileCoord(Vec2(12, 18)), "9", ++box_tag, game_map);
    boxes.pushBack(box);
    objects_tag.push_back(box_tag);
    letter_box["9"].pushBack(box);

    letter_box["8"] = box_8;
    letter_box["4"] = box_4;*/

    /*------------------------------------------------------º”‘ÿquestion label----------------------------------------------------------------*/
    /*auto temp = Sprite::create("tar1.png");
    temp->setAnchorPoint(Vec2(0, 0));
    temp->setPosition(PositionForTileCoord(Vec2(55, 26)));
    game_map->addChild(temp);
    tar_place.pushBack(temp);*/
    //tar_rect = Rect(PositionForTileCoord(Vec2(9, 35)), Size(35 * 64, 7 * 64));
    auto font = Setting::getInstance()->font_xiaodan;
    this->initQuestion();
    //assert();
    auto question_1 = QuestionLabel::create(questions[0].question.c_str(), font, 100, Vec2(tar_rect.getMidX(), tar_rect.getMidY()), game_map);
    question_label = question_1;

    /* -----------------------------------------------------º”‘ÿ’œ∞≠ŒÔ------------------------------------------------------------------*/
    /*laser* oen = new laser(PositionForTileCoord(Vec2(10, 19)), PositionForTileCoord(Vec2(10, 28)), 1.0, "laser.png", DOWN, PositionForTileCoord(Vec2(10, 19)), 3.0);
    oen->addtoNode(game_map, laser_tag);
    lasers.push_back(oen);
    laser* two = new laser(PositionForTileCoord(Vec2(9, 28)), PositionForTileCoord(Vec2(23, 28)), 1.0, "laser.png", RIGHT, PositionForTileCoord(Vec2(9, 28)), 2.0);
    two->addtoNode(game_map, laser_tag);
    lasers.push_back(two);*/
    /*auto laser = Sprite::create("laser.png");
    laser->setAnchorPoint(Vec2(0, 0));
    laser->setPosition(PositionForTileCoord(Vec2(30, 27)) + Vec2(0, 4));
    game_map->addChild(laser, 10, laser_tag);*/

    /*----------------------------------------------------º”‘ÿUI------------------------------------------------------------------------*/

    /*time_label = Label::createWithTTF("0", "fonts/superphonic.ttf", 60);
    time_label->setAnchorPoint(Vec2(0, 0));
    time_label->setPosition(visibleSize.width / 2, 660);
    this->addChild(time_label, 100);*/

    initUI();
    /*----------------------------------------------------º”‘ÿº¸≈Ãøÿ÷∆------------------------------------------------------------------*/
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        keys[keyCode] = true;
    };

    listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        keys[keyCode] = false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    Setting::getInstance()->playSoundsBGM(Bgms::bgm_level_one);
    //SimpleAudioEngine::getInstance()->playBackgroundMusic();
    
    return true;
}

void Levelone::onEnterTransitionDidFinish()
{
    Scene::onEnterTransitionDidFinish();
    game_map->setVisible(true);
    this->scheduleUpdate();
    //time_data = 500;
}

void Levelone::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void Levelone::update(float delta)
{
    Scene::update(delta);
    if (game_status == GAME_NOMALE) {
        hero_nomal_update();
        box_nomal_update();
        int key = 0;
        if (keys[EventKeyboard::KeyCode::KEY_CAPITAL_W] || keys[EventKeyboard::KeyCode::KEY_W]) {
            key++;
            hero_update(game_key::KEY_W);
        }
        else if (keys[EventKeyboard::KeyCode::KEY_CAPITAL_S] || keys[EventKeyboard::KeyCode::KEY_S]) {
            key++;
            hero_update(game_key::KEY_S);
        }
        if (keys[EventKeyboard::KeyCode::KEY_CAPITAL_A] || keys[EventKeyboard::KeyCode::KEY_A]) {
            key++;
            hero_update(game_key::KEY_A);
        }
        else if (keys[EventKeyboard::KeyCode::KEY_CAPITAL_D] || keys[EventKeyboard::KeyCode::KEY_D]) {
            key++;
            hero_update(game_key::KEY_D);
        }
        if (key == 0) {
            hero_update(game_key::KEY_NONE);
        }
        if (hero->isinjured) {
            hero->injured_interval += delta;
            if (hero->injured_interval >= 2) {
                hero->isinjured = false;
                hero->injured_interval = 0;
            }
        }
        for (auto i = lasers.begin(); i < lasers.end(); i++) {
            auto laser = (*i);
            laser->update();
            if (laser->isCollided(getHeroRect())) {
                if (!hero->isinjured) {
                    hero->isinjured = true;
                    Size visibleSize = Director::getInstance()->getVisibleSize();
                    Setting::getInstance()->playSoundsEffect(Effects::effect_die);
                    hero->blood -= 20;
                    if (hero->blood <= 0) {
                        game_over();
                    }
                    else {
                        auto size_ = blood->getContentSize();
                        //this->blood->setTextureRect(Rect(0, 0, size_.width * (hero->blood / 100), size_.height));
                        this->blood->setScaleX(hero->blood / static_cast<float>(100));
                        hero->setPosition(hero->init_pos);
                        game_map->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2) - (hero->init_pos+leg_left));
                    }
                    break;
                }
            }
            /*for (int j = 0; j < boxes.size(); j++) {
                if (laser->isCollided(boxes.at(j)->getBoundingBox())) {
                    boxes.at(j)->setPosition(boxes.at(j)->initPos);
                }
            }*/
        }
    }
    //time_label->setPosition(640, 660);
    clock_pointer->setRotation((time_data/120)*360);
    checkSuccess(delta);
    checkSetting(delta);
}

bool Levelone::canPass(Vec2 position, int tag)
{
    //log("hero at %f, %f", position.x, position.y);
    TMXLayer* layer = game_map->getLayer("layer");
    Size size = layer->getLayerSize();
    if (position.x <= 0 || position.x >= size.width * 64 || position.y <= 0 || position.y >= size.height * 64) {
        return false;
    }
    Vec2 tiledcoord = tileCoordForPosition(position);
    //log("Position %f,%f", tiledcoord.x, tiledcoord.y);
    int tilegid = layer->tileGIDAt(tiledcoord);
    //log("tilegid is %d", tilegid);
    if (tilegid) {
        auto properties = game_map->getPropertiesForGID(tilegid).asValueMap();
        bool can_pass = properties["Can_pass"].asBool();
        if (can_pass) {
            //log("can pass at %d %d", position.x, position.y);
            auto mi = game_map->getChildByTag(tag);
            if (tag != hero_tag) {
                Rect rect = mi->getBoundingBox();
                for (int i = 0; i < objects_tag.size(); i++) {
                    if (tag != objects_tag[i]) {
                        auto node = game_map->getChildByTag(objects_tag[i]);
                        if (inTarRect(node->getBoundingBox(), position)) {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
    }
    return false;
}

Vec2 Levelone::tileCoordForPosition(Vec2 position)
{
    int x = position.x / game_map->getTileSize().width;
    int y = ((game_map->getMapSize().height * game_map->getTileSize().height) - position.y) / game_map->getTileSize().height;
    return Vec2(x, y);
}

Vec2 Levelone::PositionForTileCoord(Vec2 position)
{
    float x = position.x * game_map->getTileSize().width;
    float y = (game_map->getMapSize().height - position.y - 1) * game_map->getTileSize().height;
    return Vec2(x, y);
}

int Levelone::getSpeed(Vec2 position)
{
    TMXLayer* layer = game_map->getLayer("layer");
    Size size = layer->getLayerSize();
    if (position.x<0 || position.x>size.width * 64 || position.y<0 || position.y>size.height * 64) {
        return false;
    }
    Vec2 tiledcoord = tileCoordForPosition(position);
    //log("Position %f,%f", tiledcoord.x, tiledcoord.y);
    int tilegid = layer->tileGIDAt(tiledcoord);
    //log("tilegid is %d", tilegid);
    if (tilegid) {
        auto properties = game_map->getPropertiesForGID(tilegid).asValueMap();
        int speed = properties["speed"].asInt();
        return speed;
    }
    return 0;
}

int Levelone::getBlockFunction(Vec2 world_position)
{
    TMXLayer* layer = game_map->getLayer("layer");
    Size size = layer->getLayerSize();
    if (world_position.x<0 || world_position.x>size.width * 64 || world_position.y<0 || world_position.y>size.height * 64) {
        return false;
    }
    Vec2 tiledcoord = tileCoordForPosition(world_position);
    //log("Position %f,%f", tiledcoord.x, tiledcoord.y);
    int tilegid = layer->tileGIDAt(tiledcoord);
    //log("tilegid is %d", tilegid);
    if (tilegid) {
        auto properties = game_map->getPropertiesForGID(tilegid).asValueMap();
        int fun = properties["specialFun"].asInt();
        return fun;
    }
    return 0;
}

ValueMap Levelone::getProperties(Vec2 world_pos)
{
    TMXLayer* layer = game_map->getLayer("layer");
    Size size = layer->getLayerSize();
    assert(world_pos.x >= 0 || world_pos.x <= size.width * 64 || world_pos.y >= 0 || world_pos.y <= size.height * 64);
    Vec2 tiledcoord = tileCoordForPosition(world_pos);
    //log("Position %f,%f", tiledcoord.x, tiledcoord.y);
    int tilegid = layer->tileGIDAt(tiledcoord);
    //log("tilegid is %d", tilegid);
    if (tilegid) {
        auto properties = game_map->getPropertiesForGID(tilegid).asValueMap();
        return properties;
    }
    return ValueMap();
}

void Levelone::hero_update(game_key keyCode)
{
    auto hero = game_map->getChildByTag(3);
    //auto box = game_map->getChildByTag(4);
    int speed = getSpeed(hero->getPosition() + leg_left);
    if (speed == 0) {
        speed += 1;
    }
    Vec2 offset;
    Vec2 hand_pos;
    Vec2 foot_pos;
    switch (hero_status)
    {
    case WALK_UP:
        switch (keyCode)
        {
        case KEY_W:
            offset.setPoint(0, speed);
            break;
        case KEY_A:
            hero_status = WALK_LEFT;
            offset.setPoint(-speed, 0);
            if (face_right) {
                face_right = false;
                runAction(hero, hero_walk_left_str, speed);
            }
            break;
        case KEY_S:
            hero_status = WALK_DOWN;
            offset.setPoint(0, -speed);
            break;
        case KEY_D:
            hero_status = WALK_RIGHT;
            offset.setPoint(speed, 0);
            if (!face_right) {
                face_right = true;
                runAction(hero, hero_walk_right_str, speed);
            }
            break;
        case KEY_NONE:
            hero_status = STAND;
            if (face_right) {
                runAction(hero, hero_stand_right_str, speed);
            }
            else {
                runAction(hero, hero_stand_left_str, speed);
            }
            break;
        }
        break;
    case WALK_LEFT:
        switch (keyCode)
        {
        case KEY_W:
            offset.setPoint(0, speed);
            hero_status = WALK_UP;
            break;
        case KEY_A:
            offset.setPoint(-speed, 0);
            break;
        case KEY_S:
            hero_status = WALK_DOWN;
            offset.setPoint(0, -speed);
            break;
        case KEY_D:
            hero_status = WALK_RIGHT;
            offset.setPoint(speed, 0);
            face_right = true;
            break;
        case KEY_NONE:
            hero_status = STAND;
            runAction(hero, hero_stand_left_str, speed);
            break;
        }
        break;
    case WALK_DOWN:
        switch (keyCode)
        {
        case KEY_W:
            offset.setPoint(0, speed);
            hero_status = WALK_UP;
            break;
        case KEY_A:
            hero_status = WALK_LEFT;
            offset.setPoint(-speed, 0);
            if (face_right) {
                face_right = false;
                runAction(hero, hero_walk_left_str, speed);
            }
            break;
        case KEY_S:
            offset.setPoint(0, -speed);
            break;
        case KEY_D:
            hero_status = WALK_RIGHT;
            offset.setPoint(speed, 0);
            if (!face_right) {
                face_right = true;
                runAction(hero, hero_stand_right_str, speed);
            }
            break;
        case KEY_NONE:
            hero_status = STAND;
            if (face_right) {
                runAction(hero, hero_stand_right_str, speed);
            }
            else {
                runAction(hero, hero_stand_left_str, speed);
            }
            break;
        }
        break;
    case WALK_RIGHT:
        switch (keyCode)
        {
        case KEY_W:
            offset.setPoint(0, speed);
            hero_status = WALK_UP;
            break;
        case KEY_A:
            hero_status = WALK_LEFT;
            offset.setPoint(-speed, 0);
            face_right = false;
            runAction(hero, hero_walk_left_str, speed);
            break;
        case KEY_S:
            hero_status = WALK_DOWN;
            offset.setPoint(0, -speed);
            break;
        case KEY_D:
            offset.setPoint(speed, 0);
            break;
        case KEY_NONE:
            hero_status = STAND;
            if (face_right) {
                runAction(hero, hero_stand_right_str, speed);
            }
            else {
                runAction(hero, hero_stand_left_str, speed);
            }
            break;
        }
        break;
    case STAND:
        switch (keyCode)
        {
        case KEY_W:
            hero_status = WALK_UP;
            offset.setPoint(0, speed);
            if (face_right) {
                runAction(hero, hero_walk_right_str, speed);
            }
            else {
                runAction(hero, hero_walk_left_str, speed);
            }
            break;
        case KEY_A:
            hero_status = WALK_LEFT;
            offset.setPoint(-speed, 0);
            face_right = false;
            runAction(hero, hero_walk_left_str, speed);
            break;
        case KEY_S:
            hero_status = WALK_DOWN;
            offset.setPoint(0, -speed);
            if (face_right) {
                runAction(hero, hero_walk_right_str, speed);
            }
            else {
                runAction(hero, hero_walk_left_str, speed);
            }
            break;
        case KEY_D:
            hero_status = WALK_RIGHT;
            offset.setPoint(speed, 0);
            face_right = true;
            runAction(hero, hero_walk_right_str, speed);
            break;
        case KEY_NONE:
            break;
        }
        break;
    default:
        break;
    }
    if (face_right) {
        hand_pos = hero->getPosition() + hand_right + offset;
        foot_pos = hero->getPosition() + leg_right + offset;
    }
    else {
        hand_pos = hero->getPosition() + hand_left + offset;
        foot_pos = hero->getPosition() + leg_left + offset;
    }
    if (offset != Vec2(0, 0)) {
        for (int i = 0; i < boxes.size(); i++) {
            Box* box = boxes.at(i);
            Rect box_rect = Rect(box->getPosition(), box->getContentSize());
            Vec2 hero_pos = hero->getPosition();
            if (inTarRect(box_rect, hand_pos)) {
                log("pos:%f,%f", box_rect.getMinX(), box_rect.getMinY());
                if (canPass(getTarPosition(box, hero_status) + offset, box->tag)) {
                    //tarBox = box;
                    box->setPosition(box->getPosition() + offset);
                    game_map->setPosition(game_map->getPosition() - offset);
                    hero->setPosition(hero_pos + offset);
                }
                return;
            }
            if (keys[EventKeyboard::KeyCode::KEY_SPACE]) {
                //Rect box_rect = box->getBoundingBox();
                log("pos:%f,%f", box_rect.getMinX(), box_rect.getMinY());
                if (inTarRect(box_rect, hero_pos + hand_left + Vec2(-speed, 0))) {
                    if (canPass(foot_pos, hero_tag) && canPass(getTarPosition(box, hero_status) + offset, box->tag)) {
                        if (offset.y == 0) {
                            box->setPosition(box->getPosition() + offset);
                            game_map->setPosition(game_map->getPosition() - offset);
                            hero->setPosition(hero_pos + offset);
                            return;
                        }
                    }
                }
                else if (inTarRect(box_rect, hero_pos + hand_right + Vec2(speed, 0))) {
                    if (canPass(foot_pos, hero_tag) && canPass(getTarPosition(box, hero_status) + offset, box->tag)) {
                        if (offset.y == 0) {
                            box->setPosition(box->getPosition() + offset);
                            game_map->setPosition(game_map->getPosition() - offset);
                            hero->setPosition(hero_pos + offset);
                            return;
                        }
                    }
                }
                else if (inTarRect(box_rect, hero_pos + hand_right + Vec2(0, speed))
                    || inTarRect(box_rect, hero_pos + hand_right + Vec2(0, -speed))) {
                    if (canPass(foot_pos, hero_tag) && canPass(getTarPosition(box, hero_status) + offset, box->tag)) {
                        if (offset.x == 0) {
                            box->setPosition(box->getPosition() + offset);
                            game_map->setPosition(game_map->getPosition() - offset);
                            hero->setPosition(hero_pos + offset);
                            return;
                        }
                    }
                }
                continue;
            }
        }
        if (canPass(foot_pos, hero_tag)) {
            game_map->setPosition(game_map->getPosition() - offset);
            hero->setPosition(hero->getPosition() + offset);
        }
    }
    //hero->setPosition(hero->getPosition() + offset);
}

void Levelone::hero_nomal_update()
{
    auto hero = game_map->getChildByTag(hero_tag);
    Vec2 footpos = hero->getPosition() + leg_left;
    if (getBlockFunction(footpos) == conveyer_band) {
        log("fun one");
        auto attribute = getProperties(footpos);
        float offsetX = attribute["offsetX"].asFloat();
        float offsetY = attribute["offsetY"].asFloat();
        if (canPass(footpos + Vec2(offsetX, offsetY), hero_tag)) {
            hero->setPosition(hero->getPosition() + Vec2(offsetX, offsetY));
            game_map->setPosition(game_map->getPosition() - Vec2(offsetX, offsetY));
        }
    }
}

void Levelone::box_nomal_update()
{
    for (int i = 0; i < boxes.size(); i++) {
        auto box = boxes.at(i);
        for (int j = 0; j < 4; j++) {
            Vec2 pos = getTarPosition(box, j);
            if (getBlockFunction(pos) == conveyer_band) {
                auto attribute = getProperties(pos);
                float offsetX = attribute["offsetX"].asFloat();
                float offsetY = attribute["offsetY"].asFloat();
                bool canpass = true;
                for (int k = 0; k < 4; k++) {
                    Vec2 pos = getTarPosition(box, k);
                    if (!canPass(pos + Vec2(offsetX, offsetY), box->tag)) {
                        canpass = false;
                        //this->setPosition(this->getPosition() - Vec2(offsetX, offsetY));
                    }
                }
                if (canpass)
                    box->setPosition(box->getPosition() + Vec2(offsetX, offsetY));
                break;
            }
        }
    }
}

bool Levelone::inTarRect(Rect rect, Vec2 pos)
{
    if (pos.x >= rect.getMinX() && pos.x <= rect.getMaxX() && pos.y >= rect.getMinY() && pos.y <= rect.getMaxY()) {
        return true;
    }
    return false;
}

bool Levelone::isSpriteAinB(Node* sprite_A, Node* sprite_B)
{
    auto rectA = sprite_A->getBoundingBox();
    auto rectB = sprite_B->getBoundingBox();
    if (rectA.intersectsRect(rectB)) {
        return true;
    }
    if (rectB.intersectsRect(rectA)) {
        return true;
    }
    return false;
}

void Levelone::runAction(Node* hero, const char* name, float speed)
{
    assert(hero != nullptr);
    hero->stopAllActions();
    auto animation = AnimationCache::getInstance()->getAnimation(name);
    if (speed == 0) {
        log("aaa");
        speed += 1;
    }
    //speed += 0.001;
    animation->setDelayPerUnit((3.7 / abs(speed)) * 0.15f);
    auto action = Animate::create(animation);
    hero->runAction(RepeatForever::create(action));

}

Vec2 Levelone::getTarPosition(Node* tar, int modle)
{
    assert(tar != nullptr);
    Rect rect = tar->getBoundingBox();
    if (modle == 0) {
        return Vec2(rect.getMidX(), rect.getMaxY());
    }
    else if (modle == 1) {
        return Vec2(rect.getMinX(), rect.getMidY());
    }
    else if (modle == 2) {
        return Vec2(rect.getMidX(), rect.getMinY());
    }
    else if (modle == 3) {
        return Vec2(rect.getMaxX(), rect.getMidY());
    }
    else {
        return Vec2(-1, -1);
    }
}

Rect Levelone::getHeroRect()
{
    auto hero = game_map->getChildByTag(hero_tag);
    return Rect(hero->getPosition().x + hero_rect.getMinX(),
        hero->getPosition().y + hero_rect.getMinY(), hero_rect.size.width, hero_rect.size.height);
}

bool Levelone::initQuestion()
{
    rapidjson::Document reader;
    ssize_t size;
    unsigned char* data = FileUtils::getInstance()->getFileData(question_file, "r", &size);
    std::string str = std::string((const char*)data, size);
    reader.Parse<0>(str.c_str());
    if (reader.HasParseError()) {
        return false;
    }
    else {
        rapidjson::Value& key = reader["question_number"];
        for (int i = 0; i < key.Capacity(); i++) {
            Question qu;
            assert(key[i].HasMember("A") && key[i].HasMember("B"));
            qu.question = key[i]["A"].GetString();
            qu.answer = key[i]["B"].GetString();
            questions.push_back(qu);
        }
    }
    return true;
}

bool Levelone::isSpellRight(std::string word, int index, float x, float y)
{
    using namespace std;
    if (index == 0) {
        string a(1, word[0]);
        Vector<Box*> l_box = letter_box[a];
        for (int i = 0; i < l_box.size(); i++) {
            auto pos = l_box.at(i)->getBoundingBox();
            if (!inTarRect(tar_rect, l_box.at(i)->getPosition())) {
                continue;
            }
            if (isSpellRight(word, index + 1, pos.getMaxX(), pos.getMinY())) {
                return true;
            }
        }
        return false;
    }
    else {
        if (index >= word.size()) {
            log("success");
            return true;
        }
        string a(1, word[index]);
        Vector<Box*> l_box = letter_box[a];
        for (int i = 0; i < l_box.size(); i++) {
            auto pos = l_box.at(i)->getBoundingBox();
            if (abs(pos.getMinX() - x) <= 40 && abs(pos.getMinY() - y) <= 40) {
                if (!inTarRect(tar_rect, l_box.at(i)->getPosition())) {
                    continue;
                }
                if (isSpellRight(word, index + 1, pos.getMaxX(), y)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Levelone::checkSuccess(float delta)
{
    if (isSpellRight(questions[question_index].answer, 0)) {
        log("game success!");
        Setting::getInstance()->playSoundsEffect(Effects::effect_success);
        question_index++;
        if (question_index == questions.size()) {
            if (game_status == GAME_NOMALE) {
                game_status = GAME_SUCCESS;
                game_success();
                return true;
            }
        }
        else {
            question_label->label->setString(questions[question_index].question);
        }
    }
    else {
        if (time_data <= 0) {
            game_over();
            game_status = GAME_OVER;
            return false;
        }
        else {
            time_data -= delta;
            this->time_label->setString(std::to_string((int)time_data));
        }
    }
    return false;
}

void Levelone::initMap()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto hero_group = game_map->getObjectGroup("hero");
    auto hero_info = hero_group->getObject("hero");
    float x = hero_info["x"].asFloat();
    float y = hero_info["y"].asFloat();
    this->time_data = hero_info["time"].asInt();
    this->hero = Hero::create(game_map, Vec2(x, y) - leg_left, hero_tag);
    game_map->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2) - Vec2(x+40, y));
    auto box_group = game_map->getObjectGroup("boxes");
    auto boxes_ = box_group->getObjects();
    for (int i = 0; i < boxes_.size(); i++) {
        auto box_info = boxes_.at(i).asValueMap();
        auto content = box_info["content"].asString();
        x = box_info["x"].asFloat();
        y = box_info["y"].asFloat();
        auto box2 = Box::create("res/box/box_4.png", Vec2(x, y), content.c_str(), 100 + i, game_map);
        boxes.pushBack(box2);
        objects_tag.push_back(100 + i);
        letter_box[content].pushBack(box2);
    }

    auto tar_rect_info = game_map->getObjectGroup("tar_rect")->getObject("tar_rect");
    x = tar_rect_info["x"].asFloat();
    y = tar_rect_info["y"].asFloat();
    float width = tar_rect_info["width"].asFloat();
    float height = tar_rect_info["height"].asFloat();
    tar_rect = Rect(x, y, width, height);

    auto Setting_rects = game_map->getObjectGroup("setting");
    auto exit_info = Setting_rects->getObject("exit");
    x = exit_info["x"].asFloat();
    y = exit_info["y"].asFloat();
    width = exit_info["width"].asFloat();
    height = exit_info["height"].asFloat();
    exit_set_rect = Rect(x, y, width, height);
    /*exit_set_box = Box::create("res/box/box_0.png", Vec2(exit_set_rect.getMinX(), exit_set_rect.getMinY() - 100), "", 201, game_map);
    boxes.pushBack(exit_set_box);
    objects_tag.push_back(201);*/

    auto effect_info = Setting_rects->getObject("effect");
    x = effect_info["x"].asFloat();
    y = effect_info["y"].asFloat();
    width = effect_info["width"].asFloat();
    height = effect_info["height"].asFloat();
    effect_set_rect = Rect(x, y, width, height);
    effect_set_box = Box::create("res/box/box_0.png", Vec2(effect_set_rect.getMinX(), effect_set_rect.getMinY() + 64), "", 202, game_map);
    boxes.pushBack(effect_set_box);
    objects_tag.push_back(202);

    auto bgm_info = Setting_rects->getObject("bgm");
    x = bgm_info["x"].asFloat();
    y = bgm_info["y"].asFloat();
    width = bgm_info["width"].asFloat();
    height = bgm_info["height"].asFloat();
    bgm_set_rect = Rect(x, y, width, height);
    bgm_set_box = Box::create("res/box/box_0.png", Vec2(bgm_set_rect.getMinX(), bgm_set_rect.getMinY() + 64), "", 203, game_map);
    boxes.pushBack(bgm_set_box);
    objects_tag.push_back(203);
}

void Levelone::initLaser()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto lasers = game_map->getObjectGroup("lasers");
    auto laser_s = lasers->getObjects();
    const char* laser_res = "laser.png";
    for (int i = 0; i < laser_s.size(); i++) {
        auto laser_info = laser_s.at(i).asValueMap();
        float speed = laser_info["speed"].asFloat();
        int dir = laser_info["direction"].asInt();
        int zoom = laser_info["zoom"].asInt();
        auto laser_rect = Rect(laser_info["x"].asFloat(), laser_info["y"].asFloat(), laser_info["width"].asFloat(), laser_info["height"].asFloat());
        laser* laser_ = new laser(laser_rect, speed, laser_res, (direction)dir, Vec2(0, 0), zoom);
        laser_->addtoNode(game_map);
        this->lasers.push_back(laser_);
    }
}

void Levelone::initUI()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();

    auto led = Sprite::create("UI/led.png");
    led->setAnchorPoint(Vec2(0.5, 1));
    led->setPosition(visibleSize.width / 2, visibleSize.height);
    this->addChild(led, 100);

    auto &led_size = led->getContentSize();

    time_label = Label::createWithTTF("0", "fonts/superphonic.ttf", 80);
    time_label->setColor(Color3B(102, 102, 153));
    time_label->setAnchorPoint(Vec2(0, 0.5));
    time_label->setPosition(140, led_size.height/2);
    led->addChild(time_label, 90);

    auto clock_0 = Sprite::create("UI/clock.png");
    //clock_0->setAnchorPoint(Vec2(0.5, 0.5));
    //clock_0->setScale(0.9);
    clock_0->setAnchorPoint(Vec2(0, 0.5));
    clock_0->setPosition(0, led_size.height/2);
    led->addChild(clock_0);

    auto pointer = Sprite::create("UI/Pointer.png");
    //pointer->setAnchorPoint(Vec2(0, 0));
    auto clock_size = clock_0->getContentSize();
    pointer->setAnchorPoint(Vec2(0.5, 0.5));
    pointer->setPosition(clock_size.width/2, clock_size.height/2);
    //pointer->setRotation(45);
    this->clock_pointer = pointer;
    clock_0->addChild(pointer);

    led->setScale(0.7);
    auto led_bsize = led->getBoundingBox();

    auto blood_frame = Sprite::create("UI/blood_frame.png");
    blood_frame->setAnchorPoint(Vec2(0.5, 0.5));
    blood_frame->setPosition(visibleSize.width / 2, visibleSize.height - led_bsize.size.height - 10);
    this->addChild(blood_frame, 100);

    this->blood = Sprite::create("UI/blood.png");
    blood->setAnchorPoint(Vec2(0, 0));
    blood->setPosition(0, 0);
    blood_frame->addChild(blood);
}

void Levelone::checkSetting(float delta)
{
    Setting* setting = Setting::getInstance();
    auto box_info = bgm_set_box->getBoundingBox();
    if (!box_info.intersectsRect(bgm_set_rect)) {
        if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
            SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
        }
    }
    else {
        if (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
            SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
        }
    }

    auto box_1_info = effect_set_box->getBoundingBox();
    if (!box_1_info.intersectsRect(effect_set_rect)) {
        setting->isOpenSoundEffect = false;
    }
    else {
        setting->isOpenSoundEffect = true;
    }

    auto hero_pos = hero->getPosition()+leg_left;
    if (!inTarRect(exit_set_rect, hero_pos)) {
        exit_time = 0;
        hero->setOpacity(255);
    }
    else {
        exit_time += delta;
        hero->setOpacity(255 - (exit_time / 5) * 255);
        if (exit_time >= 5) {
            Director::getInstance()->popScene();
            setting->playSoundsBGM(Bgms::bgm_start);
        }
    }
}

void Levelone::game_success()
{
    game_status = GAME_SUCCESS;
    auto visualSize = Director::getInstance()->getVisibleSize();
    Setting::getInstance()->playSoundsEffect(Effects::effect_game_over);
    Label* label = Label::create("πßœ≤ƒ„!!", Setting::getInstance()->font_xiaodan, 200);
    label->setAnchorPoint(Vec2(0.5, 0.5));
    label->setPosition(visualSize.width / 2, visualSize.height / 2 - 100);
    this->addChild(label, 100);
    label->setOpacity(0);
    auto ac1 = FadeTo::create(2.0f, 255);
    auto ac2 = MoveBy::create(2.0f, Vec2(0, 100));
    auto ac3 = Spawn::create(ac1, ac2, NULL);
    auto ac4 = Sequence::create(ac3, CCCallFunc::create(this, callfunc_selector(Levelone::exit_Scene)), NULL);
    label->runAction(ac4);
}

void Levelone::game_over()
{
    game_status = GAME_OVER;
    auto visualSize = Director::getInstance()->getVisibleSize();
    Setting::getInstance()->playSoundsEffect(Effects::effect_game_over);
    Label* label = Label::create("”Œœ∑ ß∞‹!!", Setting::getInstance()->font_xiaodan, 200);
    label->setAnchorPoint(Vec2(0.5, 0.5));
    label->setPosition(visualSize.width / 2, visualSize.height / 2-100);
    this->addChild(label, 100);
    label->setOpacity(0);
    auto ac1 = FadeTo::create(2.0f, 255);
    auto ac2 = MoveBy::create(2.0f, Vec2(0, 100));
    auto ac3 = Spawn::create(ac1, ac2, NULL);
    auto ac4 = Sequence::create(ac3, CCCallFunc::create(this, callfunc_selector(Levelone::exit_Scene)), NULL);
    label->runAction(ac4);
}

void Levelone::exit_Scene()
{
    Director::getInstance()->popScene();
    Setting::getInstance()->playSoundsBGM(Bgms::bgm_start);
}
