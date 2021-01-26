#include "Box.h"
#include"Setting.h"

Box* Box::create(const char* filename, Vec2 pos, const char* letter, int tag,Node* parent)
{
    auto* box = new Box();
    auto fonts = Setting::getInstance()->font_sup;
    box->initWithFile(filename);
    box->setPosition(pos);
    box->initPos = pos;
    box->tag = tag;
    box->letter = letter;
    box->setAnchorPoint(Vec2(0, 0));
    auto label = Label::createWithTTF(letter, fonts, box->getContentSize().height);
    label->setAnchorPoint(Vec2(0.5, 0.5));
    label->setPosition(Vec2(box->getContentSize().width/2, box->getContentSize().height/2));
    box->addChild(label);
    parent->addChild(box, 2, tag);
    return box;
}
