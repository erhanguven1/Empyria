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
protected:
    ~TextObject() override
    {

    }
};

} // Engine

#endif //EMPYRIA_TEXTOBJECT_H
