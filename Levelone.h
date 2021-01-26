#pragma once

#include "cocos2d.h"
#include "proj.win32/Obstacle.h"
#include "proj.win32/Box.h"
#include "proj.win32/Setting.h"
#include "proj.win32/QuestionLabel.h"
#include "Hero.h"
#include <vector>

USING_NS_CC;

class Levelone : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    virtual void onEnterTransitionDidFinish() override;

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

   // void heroAction(EventKeyboard::KeyCode keyCode);

    void update(float delta) override;
    bool canPass(Vec2 position, int tag);
    Vec2 tileCoordForPosition(Vec2 position);
    Vec2 PositionForTileCoord(Vec2 position);
    int getSpeed(Vec2 position);
    int getBlockFunction(Vec2 world_position);
    ValueMap getProperties(Vec2 world_pos);
    void hero_update(game_key keyCode);
    void hero_nomal_update();
    void box_nomal_update();
    void laser_update();
    bool inTarRect(Rect rect, Vec2 pos);
    bool isSpriteAinB(Node* sprite_A, Node* sprite_B);
    void runAction(Node* hero, const char* name, float speed = 3.7);
    Vec2 getTarPosition(Node* tar, int modle/*0:上中 1:左中 2:下中 3:右中*/);
    Rect getHeroRect();
    bool initQuestion();
    bool isSpellRight(std::string word, int index, float x = 0, float y = 0);
    bool checkSuccess(float delta);
    void initMap();
    void initLaser();
    void initUI();
    void checkSetting(float delta);
    void game_success();
    void game_over();
    void exit_Scene();

    std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
    std::map<std::string, Vector<Box*>> letter_box;

    TMXTiledMap* game_map = nullptr;

    //Vector<Sprite*> tar_place;
    Label* time_label = nullptr;
    long float time_data = 120;
    Sprite* clock_pointer = nullptr;
    Game_status game_status = GAME_NOMALE;
    //bool isGameOver = false;

    Rect tar_rect;
    Rect bgm_set_rect;
    Rect effect_set_rect;
    Rect exit_set_rect;
    Box* bgm_set_box;
    Box* effect_set_box;
    Box* exit_set_box;
    float exit_time = 0;


    Vector<Box*> boxes;
    std::vector<Vec2> box_initpos;
    std::vector<laser*> lasers;
    std::vector<Question> questions;
    std::vector<int> objects_tag;
    bool tar_one_ready = false;
    short int question_index = 0;
    QuestionLabel* question_label = nullptr;

    short int hero_tag = 3;
    short int box_1_tag = 4;
    short int laser_tag = 5;

    Hero* hero = nullptr;
    Sprite* blood = nullptr;
    status_hero hero_status = STAND;
    const char* hero_walk_right_str = "hero_walk_right";
    const char* hero_stand_right_str = "hero_stand_right";
    const char* hero_stand_left_str = "hero_stand_left";
    const char* hero_walk_left_str = "hero_walk_left";
    bool face_right = true;

    Vec2 initialpos = Vec2(12, 12);
    Vec2 leg_right = Vec2(102, 50);
    Vec2 leg_left = Vec2(90, 50);
    Vec2 hand_right = Vec2(114, 82);
    Vec2 hand_left = Vec2(80, 82);
    Vec2 head_up = Vec2(100, 160);
    Rect hero_rect = Rect(75, 50, 40, 109);


    const char* question_file = "question.json";

    CREATE_FUNC(Levelone);
};

