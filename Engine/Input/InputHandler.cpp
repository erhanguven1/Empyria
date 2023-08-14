//
// Created by erhan güven on 19.06.2023.
//

#include "InputHandler.h"
#include <iostream>

namespace Engine
{
void InputHandler::keyEvent(int key, int action)
{
    if(action == GLFW_PRESS)
    {
        unsigned char k = key;
        if(key >= 65 && key <= 90)
            k = key + 32;

        InputField::handleInputOnSelectedInputField(k);
    }
    keyStates[key] = action;
}

void InputHandler::cursorPosEvent(double xPos, double yPos)
{

    mouseMovement.x = xPos - last_xPos;
    mouseMovement.y = yPos - last_yPos;

    last_xPos = xPos;
    last_yPos = yPos;

    mousePosition.x = xPos;
    mousePosition.y = yPos;
}

void InputHandler::mouseButtonEvent(int button, int action, int mods)
{
    mouseStates[button] = action;
    std::cout << "Button: " << button << " State: " << action << " \n";
}
} // Engine