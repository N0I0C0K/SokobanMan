#include "CharacterScene.h"


Scene* CharacterScene::createScene()
{
    return CharacterScene::create();
}

bool CharacterScene::init()
{
    USING_NS_CC;
    if (!Scene::create()) {
        return false;
    }
    this->setVisible(false);
    auto visibleSize = Director::getInstance()->getVisibleSize();
 
    game_map = cocos2d::TMXTiledMap::create("map/Character.tmx");
    game_map->setAnchorPoint(Vec2(0, 0));
    game_map->setPosition(Vec2(0, 0));
    this->addChild(game_map);

    const int xxx = visibleSize.width / 6;
    const int yyy = visibleSize.height / 2;
    for (int i = 0; i <= 4; i++) {
        auto hero_0 = Hero::create(this, Vec2(xxx * (i+1), yyy), i, i);
        heros.push_back(hero_0);
    }
    heros[0]->runAction(MoveBy::create(1.0f, Vec2(0, -100)));
    
    auto help_label = Label::createWithTTF("[A][D] for switch,[Enter] to select", Setting::getInstance()->font_sup, 20);
    help_label->setAnchorPoint(Vec2(1, 0));
    help_label->setPosition(Vec2(visibleSize.width, 0));
    this->addChild(help_label, 1);
    
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        keys[keyCode] = true;
    };
    listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_A || keyCode == EventKeyboard::KeyCode::KEY_A) {
            onKeyAClick();
        }
        else if (keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_D || keyCode == EventKeyboard::KeyCode::KEY_D) {
            onKeyDClick();
        }
        else if (keyCode == EventKeyboard::KeyCode::KEY_ENTER) {
            Setting::getInstance()->playSoundsEffect(Effects::effect_enter);
            //SimpleAudioEngine::getInstance()->playEffect(Setting::getInstance()->getSoundsEffect(Effects::effect_enter));
            Setting::getInstance()->hero_index = this->hero_index;
            Director::getInstance()->popScene();
        }
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

void CharacterScene::onEnterTransitionDidFinish()
{
    this->setVisible(true);
}

void CharacterScene::onKeyAClick()
{
    Setting::getInstance()->playSoundsEffect(Effects::effect_select);
    //SimpleAudioEngine::getInstance()->playEffect();
    auto action1 = MoveBy::create(1.0f, Vec2(0, 100));
    auto action2 = MoveBy::create(1.0f, Vec2(0, -100));
    heros[hero_index]->runAction(action1);
    heros[(hero_index + (heros.size()-1)) % heros.size()]->runAction(action2);
    this->hero_index = (hero_index + 4) % heros.size();
}

void CharacterScene::onKeyDClick()
{
    Setting::getInstance()->playSoundsEffect(Effects::effect_select);
    //SimpleAudioEngine::getInstance()->playEffect(Setting::getInstance()->getSoundsEffect(Effects::effect_select));
    auto action1 = MoveBy::create(1.0f, Vec2(0, 100));
    auto action2 = MoveBy::create(1.0f, Vec2(0, -100));
    heros[hero_index]->runAction(action1);
    heros[(hero_index + 1) % heros.size()]->runAction(action2);
    this->hero_index = (hero_index + 1) % heros.size();
}


