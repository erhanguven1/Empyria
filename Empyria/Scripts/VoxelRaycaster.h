//
// Created by erhan güven on 23.07.2023.
//

#ifndef EMPYRIA_VOXELRAYCASTER_H
#define EMPYRIA_VOXELRAYCASTER_H

#include "Block.h"
#include "ChunkManager.h"
#include "Engine/Scene/SceneManager.h"

namespace Empyria
{

class VoxelRaycaster
{
public:
    VoxelRaycaster()
    {
        for(int i = 0; i < 10; i++)
        {
            raycastObjects.push_back(SceneManager::getActiveScene()->instantiateGameObject<ModelObject>(1, PrimitiveTypes::Cube,""));
            raycastObjects.back()->getComponent<Transform>()->scale = vec3(.01f);
        }
    }
    ChunkManager* chunkManager = nullptr;

    void deleteCube();
    void spawnCube();
    void spawnCubeAtPos(vec3 pos);
    Block* cubeAtTheBottom();
    Block* cubeAtTheRight();
    Block* cubeAtTheLeft();

    vector<Block*> blocksAroundPoint(vec3 point);

private:
    Block* raycast(vec3* cubeListPosition, unsigned int* chunkId, bool isCameraRaycast = true, vec3 direction = vec3(0,-1,0));
    vector<ModelObject*> raycastObjects;
};

} // Empyria

#endif //EMPYRIA_VOXELRAYCASTER_H
