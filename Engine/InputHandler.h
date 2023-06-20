//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_INPUTHANDLER_H
#define EMPYRIA_INPUTHANDLER_H

#include <unordered_map>

namespace Engine
{

class InputHandler
{
public:
    void keyEvent(int key, int action);
    inline static std::unordered_map<int, int> keyStates;
};

} // Engine

#endif //EMPYRIA_INPUTHANDLER_H
