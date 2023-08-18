//
// Created by erhan güven on 22.06.2023.
//

#ifndef EMPYRIA_UIOBJECT_H
#define EMPYRIA_UIOBJECT_H

#include "Engine/GameObject/GameObject.h"

namespace Engine
{

class UIObject : public GameObject
{
public:
    UIObject()
    {

    }
    UIObject(string imagePath, vec4 color = vec4(1,1,1,1), bool isButton = false);

protected:
    ~UIObject() override
    {

    }
};

} // Engine

#endif //EMPYRIA_UIOBJECT_H
