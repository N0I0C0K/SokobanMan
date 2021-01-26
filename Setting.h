#pragma once
#include<iostream>
#include<vector>

enum status_hero
{
    WALK_UP,
    WALK_LEFT,
    WALK_DOWN,
    WALK_RIGHT,
    STAND,
    STAND_RIGHT,
    STAND_LEFT
};

enum Bgms {
    bgm_level_one,
    bgm_newpeople,
    bgm_start
};

enum Effects {
    effect_enter,
    effect_game_over,
    effect_game_start,
    effect_select,
    effect_die,
    effect_success
};

enum Game_status
{
    GAME_NOMALE,
    GAME_OVER,
    GAME_SUCCESS,
    GAME_PAUSE
};

enum bolck_fun
{
    none_fun,
    conveyer_band,

};

enum game_key
{
    KEY_W,
    KEY_A,
    KEY_S,
    KEY_D,
    KEY_SHIFT,
    KEY_NONE
};
class Setting
{
public:
	static Setting* getInstance();
	short int hero_index = 0;
	short int volume = 40;
    int bgm_tag = -1;
	bool isOpenSoundEffect = true;
	bool isOpenBGM = true;
    const char* font_sup = "fonts/superphonic.ttf";
    const char* font_pang = "fonts/pangpang.ttf";
    const char* font_xiaodan = "fonts/xiaodan.ttf";
    void playSoundsBGM(Bgms id);
    unsigned int playSoundsEffect(Effects id);
    std::vector<std::string> bgms;
    std::vector<std::string> effects;
private:
	Setting();
};

