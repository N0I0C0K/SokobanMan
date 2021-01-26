#pragma once
#include "cocos2d.h"
#include <iostream>
#include "json/document.h"

USING_NS_CC;

struct Question
{
	std::string question;
	std::string answer;
};

class QuestionLabel
{
public:
	static QuestionLabel* create(const char* question, const char* ttf_file, short int size, Vec2 pos, Node* parent);
	Label* label;
	std::string answer;
};

Question getQuestion(const char* file, short int index, const char* question_model);