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
    ChatView() : Engine::ListView(vec2(-700,0),512,768,75,15,15,Engine::Alignment::LEFT)
    {
        setTextColor(vec4(1,0,0,1));
    }
private:
};

} // Empyria

#endif //EMPYRIA_CHATVIEW_H
