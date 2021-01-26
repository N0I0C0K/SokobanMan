#include "Setting.h"
#include"SimpleAudioEngine.h"


Setting* Setting::getInstance()
{
    static Setting* set = new Setting();
    return set;
}

void Setting::playSoundsBGM(Bgms id)
{
    using namespace CocosDenshion;
    if (isOpenBGM) {
        auto bgm = this->bgms[id];
        SimpleAudioEngine::getInstance()->playBackgroundMusic(bgm.c_str(), true);
        //SimpleAudioEngine::getInstance()->playBackgroundMusic(bgm, true);
    }
    return;
}

unsigned int Setting::playSoundsEffect(Effects id)
{
    using namespace CocosDenshion;
    if (isOpenSoundEffect) {
        auto name = this->effects[id];
        unsigned int e_id = SimpleAudioEngine::getInstance()->playEffect(name.c_str(), false);
        return e_id;
    }
    else {
        return 0;
    }
}

Setting::Setting()
{
    this->bgms.push_back("sounds/bgm_level_one.mp3");
    this->bgms.push_back("sounds/bgm_newpeople.wav");
    this->bgms.push_back("sounds/bgm_start.wav");
    this->effects.push_back("sounds/effect_enter.wav");
    this->effects.push_back("sounds/effect_game_over.wav");
    this->effects.push_back("sounds/effect_game_start.wav");
    this->effects.push_back("sounds/effect_select.wav");
    this->effects.push_back("sounds/effect_die.wav");
    this->effects.push_back("sounds/effect_success.wav");

    //std::string bgms[] = {"sounds/bgm_level_one.mp3", "sounds/bgm_newpeople.wav", "sounds/bgm_start.wav" };
    //std::string effects[] = { "sounds/effect_enter.wav","sounds/effect_game_over.wav","sounds/effect_game_start.wav","sounds/effect_select.wav" };
}
