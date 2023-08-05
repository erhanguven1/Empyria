//
// Created by erhan güven on 23.07.2023.
//

#ifndef EMPYRIA_CHUNK_H
#define EMPYRIA_CHUNK_H

#include "Block.h"
#include <vector>

namespace Empyria
{

class Chunk : public GameObject
{
public:
    Chunk(vec3& pos)
    {
        addComponent<Transform>();
        getComponent<Transform>()->position = pos;
    }
    void createChunk();
    void spawnBlock(vec3& pos);
    void deleteBlock(vec3& pos);

    std::vector<std::vector<std::vector<Block*>>> blocks;
};

} // Empyria

#endif //EMPYRIA_CHUNK_H
