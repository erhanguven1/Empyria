//
// Created by erhan güven on 25.06.2023.
//

#ifndef EMPYRIA_EMPYRIAENGINE_H
#define EMPYRIA_EMPYRIAENGINE_H

#include <glm/glm.hpp>
#include "Window.h"

namespace Engine
{

#define REGISTER_CREATE(T) \
static T* create() \
{ \
    T *pRet = new T(); \
} \



class EmpyriaEngine
{
public:
    inline static glm::vec2* getScreenSize() { return screenSize; }
    inline static void setScreenSize(glm::vec2& ss)
    {
        if(screenSize != nullptr)
            screenSize = &ss;
    }

    inline static void setCursorEnable(bool isEnabled)
    {
        Window::setCursorEnable(isEnabled);
    }

private:
    inline static glm::vec2* screenSize;
};

} // Engine

#endif //EMPYRIA_EMPYRIAENGINE_H
