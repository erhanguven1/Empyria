//
// Created by erhan güven on 19.06.2023.
//

#include "InputHandler.h"

namespace Engine
{
void InputHandler::keyEvent(int key, int action)
{
    keyStates[key] = action;
}

void InputHandler::cursorPosEvent(double xPos, double yPos)
{
    if(xPos > last_xPos)
        mouseState.x = 1;
    else if(xPos < last_xPos)
        mouseState.x = -1;
    else
        mouseState.x = 0;

    if(yPos > last_yPos)
        mouseState.y = 1;
    else if(yPos < last_yPos)
        mouseState.y = -1;
    else
        mouseState.y = 0;

    last_xPos = xPos;
    last_yPos = yPos;
}
} // Engine