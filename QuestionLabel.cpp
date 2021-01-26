#include "QuestionLabel.h"
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

QuestionLabel* QuestionLabel::create(const char* question, const char* ttf_file, short int size, Vec2 pos, Node* parent)
{
    QuestionLabel* qu = new QuestionLabel();
    assert(qu != nullptr);
    qu->label = Label::createWithTTF(question, ttf_file, size);
    qu->label->setAnchorPoint(Vec2(0.5, 0.5));
    qu->label->setPosition(pos);
    parent->addChild(qu->label, 1);
    //qu->answer = answer;
    return qu;
}

Question getQuestion(const char* file, short int index, const char* question_model)
{
    rapidjson::Document reader;
    ssize_t size;
    unsigned char* data = FileUtils::getInstance()->getFileData(file, "r", &size);
    std::string str = std::string((const char*)data, size);
    reader.Parse<0>(str.c_str());
    if (reader.HasParseError()) {
        log("error");
    }
    else {
        rapidjson::Value& key = reader["question"][0]["A"];
        log(key.GetString());
    }
    return Question();
}
