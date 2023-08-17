//
// Created by erhan güven on 16.08.2023.
//

#ifndef EMPYRIA_CHATVIEW_H
#define EMPYRIA_CHATVIEW_H

#include "Engine/Text/TextObject.h"
#include "Engine/Scene/SceneManager.h"
#include "Engine/UI/UIObject.h"
#include "Engine/UI/ListView.h"

namespace Empyria
{

class ChatView : public Engine::ListView
{
public:
    ChatView() : Engine::ListView(vec2(-500,0),512,384,75,15,30)
    {

    }
private:
};

} // Empyria

#endif //EMPYRIA_CHATVIEW_H
