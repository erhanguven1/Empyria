//
// Created by erhan güven on 14.08.2023.
//

#ifndef EMPYRIA_PLAYERLISTVIEW_H
#define EMPYRIA_PLAYERLISTVIEW_H

#include <string>
#include "Engine/Text/TextObject.h"
#include "Engine/Scene/SceneManager.h"
#include "Engine/UI/UIObject.h"
#include "Engine/UI/ListView.h"

namespace Empyria
{

class PlayerListView : public Engine::ListView
{
public:
    PlayerListView() : Engine::ListView(vec2(500,0),256,384,75,15,30)
    {

    }
};

} // Empyria

#endif //EMPYRIA_PLAYERLISTVIEW_H
