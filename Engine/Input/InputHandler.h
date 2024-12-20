//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_INPUTHANDLER_H
#define EMPYRIA_INPUTHANDLER_H

#include <unordered_map>
#include "Engine/UI/InputField.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

namespace Engine
{

class InputHandler
{
public:
    void keyEvent(int key, int action);
    void cursorPosEvent(double xPos, double yPos);
    void mouseButtonEvent(int button, int action, int mods);
    inline static std::unordered_map<int, int> keyStates;
    inline static std::unordered_map<int, int> mouseStates;
    inline static glm::vec2 mousePosition = glm::vec2(0.0f);
    inline static glm::vec2 mouseMovement = glm::vec2(0.0f);
    inline static bool isPressingKey(int keycode)
    {
        return keyStates[keycode] == GLFW_REPEAT || keyStates[keycode] == GLFW_PRESS;
    }
    inline static bool onPressKey(int keycode)
    {
        bool ret = keyStates[keycode] == GLFW_PRESS;
        if(ret)
        {
            keyStates[keycode] = GLFW_RELEASE;
        }
        return ret;
    }

    inline static bool onPressMouseButton(int mousecode)
    {
        bool ret = mouseStates[mousecode] == GLFW_PRESS;
        if(ret)
            mouseStates[mousecode] = GLFW_RELEASE;
        return ret;
    }

private:
    inline static double last_xPos = 0;
    inline static double last_yPos = 0;
};

} // Engine

#endif //EMPYRIA_INPUTHANDLER_H
