//
// Created by erhan güven on 13.07.2023.
//

#ifndef EMPYRIA_GAMESCENE_H
#define EMPYRIA_GAMESCENE_H

#include "Engine/EmpyriaEngine.h"
#include "Engine/Scene/Scene.h"
#include "../Scripts/VoxelRaycaster.h"
#include "../Scripts/Player.h"

using namespace Engine;

namespace Empyria
{

class GameScene : public Scene
{
public:
    REGISTER_CREATE(GameScene)

    GameScene();
    void start() override;
    void update(float dt) override;

    bool spawned = false;
    bool spawnedCube = false;
    bool deletedCube = false;
    vec3 spawnedCubePos;
private:
    Player* player = nullptr;
    ModelObject* otherPlayer = nullptr;
    GameObject* car = nullptr;
    VoxelRaycaster* voxelRaycaster;
    bool first = false;
};

} // Empyria

#endif //EMPYRIA_GAMESCENE_H
