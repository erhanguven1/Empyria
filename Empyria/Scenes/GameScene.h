//
// Created by erhan güven on 13.07.2023.
//

#ifndef EMPYRIA_GAMESCENE_H
#define EMPYRIA_GAMESCENE_H

#include "Engine/EmpyriaEngine.h"
#include "Engine/Scene/Scene.h"

using namespace Engine;

namespace Empyria
{

class GameScene : public Scene
{
public:
    REGISTER_CREATE(GameScene)

    GameScene();
    void update(float dt) override;
private:
    GameObject* car = nullptr;
};

} // Empyria

#endif //EMPYRIA_GAMESCENE_H
