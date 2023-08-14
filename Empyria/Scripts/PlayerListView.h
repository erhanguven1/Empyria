//
// Created by erhan güven on 14.08.2023.
//

#ifndef EMPYRIA_PLAYERLISTVIEW_H
#define EMPYRIA_PLAYERLISTVIEW_H

#include <string>
#include "Engine/Text/TextObject.h"
#include "Engine/Scene/SceneManager.h"
#include "Engine/UI/UIObject.h"

namespace Empyria
{

class PlayerListView : public Engine::UIObject
{
public:
    PlayerListView() : Engine::UIObject("")
    {

    }

    void addPlayer(const std::string& playerName)
    {
        auto* t = Engine::SceneManager::getActiveScene()->instantiateGameObject<Engine::TextObject>(5,playerName.c_str());
        players.push_back(t);
    }

    void update(float dt) override;
private:
    std::vector<Engine::TextObject*> players;
};

} // Empyria

#endif //EMPYRIA_PLAYERLISTVIEW_H
