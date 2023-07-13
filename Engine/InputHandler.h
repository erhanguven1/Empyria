//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_INPUTHANDLER_H
#define EMPYRIA_INPUTHANDLER_H

#include <unordered_map>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

namespace Engine
{

class InputHandler
{
public:
    void keyEvent(int key, int action);
    void cursorPosEvent(double xPos, double yPos);
    inline static std::unordered_map<int, int> keyStates;
    inline static glm::vec2 mouseState = glm::vec2(0.0f);
    inline static bool isPressingKey(int keycode)
    {
        return keyStates[keycode] == GLFW_REPEAT || keyStates[keycode] == GLFW_PRESS;
    }
    inline static bool onPressKey(int keycode)
    {
        return keyStates[keycode] == GLFW_PRESS;
    }
private:
    inline static double last_xPos = 0;
    inline static double last_yPos = 0;
};

} // Engine

#endif //EMPYRIA_INPUTHANDLER_H
