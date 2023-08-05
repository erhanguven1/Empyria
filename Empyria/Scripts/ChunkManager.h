//
// Created by erhan güven on 23.07.2023.
//

#ifndef EMPYRIA_CHUNKMANAGER_H
#define EMPYRIA_CHUNKMANAGER_H

#include <vector>
#include "Chunk.h"

namespace Empyria
{

class ChunkManager
{
public:
    std::vector<Chunk*> chunks;
};

} // Empyria

#endif //EMPYRIA_CHUNKMANAGER_H
