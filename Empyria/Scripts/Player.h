//
// Created by erhan güven on 28.07.2023.
//

#ifndef EMPYRIA_PLAYER_H
#define EMPYRIA_PLAYER_H

#include "Engine/Camera.h"
#include "Engine/GameObject/ModelObject.h"
#include "VoxelRaycaster.h"

using namespace Engine;

namespace Empyria
{

class Player : public ModelObject
{
public:
    Player(vec3& spawnPosition, VoxelRaycaster& voxelRaycaster);
    void update(float dt) override;

    inline static Player& getInstance()
    {
        return *instance;
    }

    inline static string playerName;

private:
    inline static Player* instance;
    Camera& camera;
    VoxelRaycaster& m_voxelRaycaster;
};

} // Empyria

#endif //EMPYRIA_PLAYER_H
