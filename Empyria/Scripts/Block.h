//
// Created by erhan güven on 23.07.2023.
//

#ifndef EMPYRIA_BLOCK_H
#define EMPYRIA_BLOCK_H

#include "Engine/GameObject/ModelObject.h"

using namespace Engine;

namespace Empyria
{

enum BlockType
{
    Dirt,
    Rock
};

class Block : public ModelObject
{
public:
    Block(string path) : ModelObject(PrimitiveTypes::Cube, path)
    {

    }

    int x;
    int y;
    int z;
};

} // Empyria

#endif //EMPYRIA_BLOCK_H
