//
// Created by erhan güven on 14.08.2023.
//

#include "PlayerListView.h"

namespace Empyria
{
void PlayerListView::update(float dt)
{
    GameObject::update(dt);

    int i = 0;

    for(auto* playerText : players)
    {
        playerText->getComponent<Engine::RectTransform>()->position.x = getComponent<Engine::RectTransform>()->position.x;
        playerText->getComponent<Engine::RectTransform>()->position.y = getComponent<Engine::RectTransform>()->position.y + i*75.0f;
        i++;
    }
}
} // Empyria