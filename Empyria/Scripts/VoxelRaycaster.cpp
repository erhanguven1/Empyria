//
// Created by erhan güven on 23.07.2023.
//

#include "VoxelRaycaster.h"
#include "../Engine/Camera.h"
#include "Player.h"

namespace Empyria
{

namespace VoxelConstantValues
{
    constexpr unsigned int cameraRaycastStepSize = 5;
    constexpr unsigned int collisionRaycastStepSize = 1;
}

Block *VoxelRaycaster::raycast(vec3* cubeListPosition, unsigned int* chunkId, bool isCameraRaycast, vec3 direction)
{
    auto& cam = Camera::getInstance();
    int stepCount = isCameraRaycast ? VoxelConstantValues::cameraRaycastStepSize : VoxelConstantValues::collisionRaycastStepSize;

    vec3 lookDirection = isCameraRaycast ? cam.lookDirection : direction;
    vec3 pos = isCameraRaycast ? cam.position : (Player::getInstance().getComponent<Transform>()->position + vec3(0,1.01f,0));

    for(float step = 0; step < stepCount; step+=1)
    {
        glm::vec3 currentPos = glm::round(pos + lookDirection * ((1.0f * step) / (1.0f * stepCount)) * (1.0f*stepCount));
        raycastObjects[step]->getComponent<Transform>()->position = currentPos;
        //std::cout << "Step: " << to_string(step) + " ---> " << currentPos.x << ", " << currentPos.y << ", " << currentPos.z << "\n";

        *chunkId = 0;

        for(auto chunk : chunkManager->chunks)
        {
            int posX = currentPos.x + chunk->getComponent<Transform>()->position.x;
            int posY = currentPos.y + chunk->getComponent<Transform>()->position.y;
            int posZ = currentPos.z + chunk->getComponent<Transform>()->position.z;

            if(chunk->blocks.size() > currentPos.x &&
               chunk->blocks[currentPos.x].size() > currentPos.y &&
               chunk->blocks[currentPos.x][currentPos.y].size() > currentPos.z)
            {
                if(auto block = chunk->blocks[currentPos.x][currentPos.y][currentPos.z])
                {
                    if( posX == block->x && posY == block->y && posZ == block->z )
                    {
                        cubeListPosition->x = currentPos.x;
                        cubeListPosition->y = currentPos.y;
                        cubeListPosition->z = currentPos.z;

                        return block;
                    }

                }
            }

            *chunkId+=1;
        }

    }

    return nullptr;
}

void VoxelRaycaster::deleteCube()
{
    vec3 cubePosOnChunk;
    unsigned int chunkId = -1;

    raycast(&cubePosOnChunk, &chunkId);

    chunkManager->chunks[chunkId]->deleteBlock(cubePosOnChunk);
}

void VoxelRaycaster::spawnCube()
{
    vec3 cubePosOnChunk;
    unsigned int chunkId = -1;

    raycast(&cubePosOnChunk, &chunkId);
    cubePosOnChunk.x -= 1;

    chunkManager->chunks[chunkId]->spawnBlock(cubePosOnChunk);
}

Block *VoxelRaycaster::cubeAtTheBottom()
{
    auto playerPos = Player::getInstance().getComponent<Transform>()->position;

    int x = playerPos.x + .5f;
    int y = floor(playerPos.y - 0.0f);
    int z = playerPos.z + .5f;

    auto chunk = chunkManager->chunks[0];

    if(chunk->blocks.size() > x &&
       chunk->blocks[x].size() > y &&
       chunk->blocks[x][y].size() > z) {
        if (auto block = chunk->blocks[x][y][z]) {
            return block;
        }
    }

    return nullptr;
}

vector<Block*> VoxelRaycaster::blocksAroundPoint(vec3 point)
{
    vector<Block*> ret = {nullptr, nullptr, nullptr, nullptr};

    auto chunk = chunkManager->chunks[0];

    for(int i = 0; i < 4; i++) // Z and -Z (left right)
    {
        for(int ylevel = 0; ylevel < 2; ylevel++)
        {
            int x = point.x + (i >= 2 ? (((i-2)*2-0.5f)*0.5f+0.2f) : 0.75f);
            int y = floor(point.y + 1.0f) + ylevel;
            int z = point.z + (i < 2 ? ((i*2-0.5f)*0.5f+0.2f) : 0.75f);

            if(chunk->blocks.size() > x &&
               chunk->blocks[x].size() > y &&
               chunk->blocks[x][y].size() > z)
            {
                if (auto block = chunk->blocks[x][y][z])
                {
                    ret[i] = block;
                }
            }
        }

    }

    return ret;
}
} // Empyria