//
// Created by erhan güven on 25.06.2023.
//

#ifndef EMPYRIA_EMPYRIAENGINE_H
#define EMPYRIA_EMPYRIAENGINE_H

#ifdef EMPYRIA_interface
#include "Engine/UI/RectTransform.h"
#include "Engine/UI/InputField.h"
#include "Engine/UI/UIObject.h"
#include "Engine/UI/UIRenderer.h"
#include "Engine/Text/TextObject.h"
#include "Engine/Text/TextRenderer.h"
#endif

#ifndef EMPYRIA_interface
#ifdef INCLUDE_TEXT
#include "Engine/Text/TextRenderer.h"
#include "Engine/Text/TextObject.h"
#include "Engine/UI/InputField.h"
#endif
#endif

#ifndef EMPYRIA_interface
#ifdef INCLUDE_UI
#include "Engine/UI/RectTransform.h"
#include "Engine/UI/UIRenderer.h"
#include "Engine/UI/UIObject.h"
#include "Engine/UI/ListView.h"
#endif
#endif

#include <glm/glm.hpp>
#include "Window.h"

namespace Engine
{

#define REGISTER_CREATE(T) \
static T* create() \
{ \
    T *pRet = new T(); \
}                          \

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
