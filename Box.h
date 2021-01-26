#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Box :
    public Sprite
{
public:
    static Box* create(const char* filename, Vec2 pos, const char* letter, int tag,Node* parent);
    String letter;
    Vec2 initPos;
    int tag;
};

