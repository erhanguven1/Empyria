//
// Created by erhan güven on 23.07.2023.
//

#include "Chunk.h"
#include "Engine/Scene/SceneManager.h"
#include "Engine/Networking/UdpClient.h"

namespace Empyria
{
void Chunk::createChunk()
{
    for(int x = 0; x < 10; x++)
    {
        blocks.push_back(std::vector<std::vector<Block*>>());

        for(int y = 0; y < 10; y++)
        {
            blocks[x].push_back(std::vector<Block*>());

            for (int z = 0; z < 10; z++)
            {
                Block* cube = nullptr;

                if(y < 1 || x == 0 || z == 0 || x == 9 || z == 9)
                {
                    cube = SceneManager::getActiveScene()->instantiateGameObject<Block>(1, "grass.png");
                    cube->getComponent<Transform>()->position = getComponent<Transform>()->position + vec3(x,y,z);
                    cube->x = getComponent<Transform>()->position.x + x;
                    cube->y = getComponent<Transform>()->position.y + y;
                    cube->z = getComponent<Transform>()->position.z + z;

                    cube->calculatePlanes();
                }

                blocks[x][y].push_back(cube);
            }
        }
    }
}

void Chunk::spawnBlock(vec3 &pos)
{
    if(this == nullptr)
        return;
    pos -= getComponent<Transform>()->position;

    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    if(x > blocks.size() ||
       y > blocks[x].size() ||
       z > blocks[x][y].size())
        return;


    if(blocks[x][y][z] == nullptr)
    {
        auto* cube = SceneManager::getActiveScene()->instantiateGameObject<Block>(1, "grass.png");
        cube->getComponent<Transform>()->position = getComponent<Transform>()->position + vec3(x,y,z);
        cube->x = getComponent<Transform>()->position.x + x;
        cube->y = getComponent<Transform>()->position.y + y;
        cube->z = getComponent<Transform>()->position.z + z;
        blocks[x][y][z] = cube;

        cube->calculatePlanes();

        BlockStateMessage msg;
        msg.add = true;
        msg.pos = pos + getComponent<Transform>()->position;

        UdpClient::getInstance()->sendData(msg);
    }
}

void Chunk::deleteBlock(vec3 &pos)
{
    if(this == nullptr)
        return;
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;


    if(blocks[x][y][z] != nullptr)
    {
        blocks[x][y][z]->destroy();
        blocks[x][y][z] = nullptr;

        BlockStateMessage msg;
        msg.add = false;
        msg.pos = pos;

        UdpClient::getInstance()->sendData(msg);
    }
}
} // Empyria