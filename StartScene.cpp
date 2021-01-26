#include "StartScene.h"
#include"Levelone.h"
#include"ChToEn.h"
#include "CharacterScene.h"
#include "json/document.h"

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

cocos2d::Scene* StartScene::createScene()
{
    return StartScene::create();
}

bool StartScene::init()
{
    USING_NS_CC;
    if (!Scene::init()) {
        return false;
    }
    const char* fonts = Setting::getInstance()->font_pang;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto label_1 = Label::createWithTTF("设置", fonts, 100);
    label_1->setScale(0.5);
    label_1->setAnchorPoint(Vec2(0.5, 0.5));
    label_1->setPosition(Vec2(visibleSize.width / 2 - 1000, visibleSize.height / 2 - 40));
    this->addChild(label_1, 1, 1);
    label_box.pushBack(label_1);

    min_pos = label_1->getPosition();

    label_1 = Label::createWithTTF("新手教程", fonts, 100);
    label_1->setScale(0.5);
    label_1->setAnchorPoint(Vec2(0.5, 0.5));
    label_1->setPosition(Vec2(visibleSize.width / 2 - 500, visibleSize.height / 2 - 40));
    this->addChild(label_1, 1, 2);
    label_box.pushBack(label_1);

    

    label_1 = Label::createWithTTF("谜题", fonts, 100);
    label_1->setScale(0.5);
    label_1->setAnchorPoint(Vec2(0.5, 0.5));
    label_1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 40));
    label_1->setScale(1.1);
    this->addChild(label_1, 1, 3);
    label_box.pushBack(label_1);

    label_1 = Label::createWithTTF("中英", fonts, 100);
    label_1->setScale(0.5);
    label_1->setAnchorPoint(Vec2(0.5, 0.5));
    label_1->setPosition(Vec2(visibleSize.width / 2 + 500, visibleSize.height / 2 - 40));
    this->addChild(label_1, 1, 4);
    label_box.pushBack(label_1);

    label_1 = Label::createWithTTF("角色", fonts, 100);
    label_1->setScale(0.5);
    label_1->setAnchorPoint(Vec2(0.5, 0.5));
    label_1->setPosition(Vec2(visibleSize.width / 2 + 1000, visibleSize.height / 2 - 40));
    this->addChild(label_1, 1, 5);
    label_box.pushBack(label_1);

    auto help_label = Label::createWithTTF("[A][D] for switch,[Enter] to select", "fonts/superphonic.ttf", 20);
    help_label->setAnchorPoint(Vec2(1, 0));
    help_label->setPosition(Vec2(visibleSize.width, 0));
    this->addChild(help_label, 1);

    auto back_ground_0 = Sprite::create("res/start_back.png");
    back_ground_0->setAnchorPoint(Vec2(0, 0));
    back_ground_0->setPosition(0, 0);
    back_ground_0->setRotation(10);
    this->addChild(back_ground_0, 0, 101);
    auto back_ground_1 = Sprite::create("res/start_back.png");
    back_ground_1->setAnchorPoint(Vec2(0, 0));
    auto wid = back_ground_1->getContentSize().width;
    back_ground_1->setRotation(10); back_ground_1->setPosition(Vec2(-wid, 0));
    this->addChild(back_ground_1, 0 , 102);

    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        keys[keyCode] = true;
    };
    listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_A || keyCode == EventKeyboard::KeyCode::KEY_A) {
            onKeyDClick();
            
        }
        else if (keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_D || keyCode == EventKeyboard::KeyCode::KEY_D) {
            onKeyAClick();
        }
        else if (keyCode == EventKeyboard::KeyCode::KEY_ENTER) {
            onKeyEnterClick();
        }
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    Setting::getInstance()->playSoundsBGM(Bgms::bgm_start);
    
    this->scheduleUpdate();

    return true;
}

void StartScene::update(float delta)
{
    back_run();
}

void StartScene::back_run()
{
    log("aaa");
    auto visualSize = Director::getInstance()->getVisibleSize();
    auto back_0 = this->getChildByTag(101);
    auto _size = back_0->getContentSize();
    auto back_1 = this->getChildByTag(102);
    auto back_0_pos = back_0->getPosition();
    auto back_1_pos = back_1->getPosition();
    back_0->setPosition(back_0_pos + Vec2(2.7, 0));
    back_1->setPosition(back_1_pos + Vec2(2.7, 0));
    if (back_0_pos.x >= visualSize.width) {
        back_0->setPosition(back_1_pos + Vec2(-_size.width+10, 0));
    }
    else if (back_1_pos.x >= visualSize.width) {
        back_1->setPosition(back_0_pos + Vec2(-_size.width+10, 0));
    }
}

void StartScene::onKeyAClick()
{
    USING_NS_CC;
    //log("A down");
    Setting::getInstance()->playSoundsEffect(Effects::effect_select);
    //SimpleAudioEngine::getInstance()->playEffect();
    int length = label_box.size();
    for (int i = 0; i < length; i++) {
        auto label = label_box.at(i);
        auto action = MoveBy::create(0.5f, Vec2(-500, 0));
        if ((index + 3)% length == i) {
            label->setPosition(min_pos.x + 500 * (length), min_pos.y);
            label->runAction(action);
        }
        else if ((index + 1) % length == i) {
            auto action_1 = ScaleTo::create(0.5f, 1.1);
            auto squen = Spawn::create(action, action_1, NULL);
            label->runAction(squen);
        }
        else if (index == i) {
            auto action_1 = ScaleTo::create(0.5f, 0.5);
            auto squen = Spawn::create(action, action_1, NULL);
            label->runAction(squen);
        }
        else {
            label->runAction(action);
        }
    }
    index = (index + 1) % label_box.size();
}

void StartScene::onKeyDClick()
{
    //log("D down");
    //SimpleAudioEngine::getInstance()->playEffect(Setting::getInstance()->getSoundsEffect(Effects::effect_select));
    Setting::getInstance()->playSoundsEffect(Effects::effect_select);
    int length = label_box.size();
    //auto tin = TintBy::create(1.0f, 120.0f, 232.0f, 254.0f);
    //this->runAction(tin);
    for (int i = 0; i < length; i++) {
        auto label = label_box.at(i);
        auto action = MoveBy::create(0.5f, Vec2(+500, 0));
        if ((index + 2) % length == i) {
            label->setPosition(min_pos.x - 500, min_pos.y);
            label->runAction(action);
        }
        else if ((index + 4) % length == i) {
            auto action_1 = ScaleTo::create(0.5f, 1.1);
            auto squen = Spawn::create(action, action_1, NULL);
            label->runAction(squen);
        }
        else if (index == i) {
            auto action_1 = ScaleTo::create(0.5f, 0.5);
            auto squen = Spawn::create(action, action_1, NULL);
            label->runAction(squen);
        }
        else {
            label->runAction(action);
        }
    }
    index = (index + 4) % label_box.size();
}

void StartScene::onKeyEnterClick()
{
    log("Enter down");
    Setting::getInstance()->playSoundsEffect(Effects::effect_enter);
    //SimpleAudioEngine::getInstance()->playEffect();
    auto label = label_box.at(index);
    auto action_1 = ScaleTo::create(0.1f, 1.3);
    auto action_2 = ScaleTo::create(0.1f, 1.1);
    auto squen = Sequence::create(action_1, action_2, NULL);
    label->runAction(squen);
    if (index == SIMPLE) {
        auto scene = HelloWorld::create();
        auto sc_action = TransitionCrossFade::create(1.0f, scene);
        Director::getInstance()->pushScene(sc_action);
    }
    else if (index == HARD) {
        auto scene = Levelone::create();
        auto sc_action = TransitionCrossFade::create(1.0f, scene);
        Director::getInstance()->pushScene(sc_action);
    }
    else if (index == VERYHARD) {
        auto scene = ChToEn::create();
        auto sc_action = TransitionCrossFade::create(1.0f, scene);
        Director::getInstance()->pushScene(sc_action);
    }
    else if (index == CHARACTER) {
        auto scene = CharacterScene::create();
        auto sc_action = TransitionCrossFade::create(1.0f, scene);
        Director::getInstance()->pushScene(sc_action);
    }
}
