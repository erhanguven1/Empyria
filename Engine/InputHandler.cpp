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
} // Engine