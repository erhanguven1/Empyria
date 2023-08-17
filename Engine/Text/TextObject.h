//
// Created by erhan güven on 11.08.2023.
//

#ifndef EMPYRIA_TEXTOBJECT_H
#define EMPYRIA_TEXTOBJECT_H

#include "Engine/GameObject/GameObject.h"

namespace Engine
{

class TextObject : public GameObject
{
public:
    TextObject()
    {

    }

    TextObject(const char* text, const Font& font = Font::arial);

    inline void setText(const char* t)
    {
        text = t;
        getComponent<TextRenderer>()->setText(t);
    }
    inline string getText()
    {
        return text;
    }
    inline void addText(const char* t)
    {
        if(text.length() > 10)
            return;
        text += t;
        getComponent<TextRenderer>()->setText(text.c_str());
    }
    inline void removeFromBack()
    {
        if(text.length() == 0)
            return;
        text.pop_back();
        getComponent<TextRenderer>()->setText(text.c_str());
    }
protected:
    ~TextObject() override
    {

    }
private:
    string text = "asd";
};

} // Engine

#endif //EMPYRIA_TEXTOBJECT_H
