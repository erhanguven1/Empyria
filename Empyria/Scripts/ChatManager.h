//
// Created by erhan güven on 14.08.2023.
//

#ifndef EMPYRIA_CHATMANAGER_H
#define EMPYRIA_CHATMANAGER_H

#include "Engine/EmpyriaEngine.h"

namespace Empyria
{

class ChatManager
{
public:
    inline static bool getIsChatActive()
    {
        return isChatActive;
    }
    inline static bool setIsChatActive(const bool& val)
    {
        isChatActive = val;
        Engine::EmpyriaEngine::setCursorEnable(isChatActive);
    }

private:
    inline static bool isChatActive = false;

};

} // Empyria

#endif //EMPYRIA_CHATMANAGER_H
