//
// Created by erhan güven on 10.07.2023.
//

#ifndef EMPYRIA_MODELOBJECT_H
#define EMPYRIA_MODELOBJECT_H

#include "GameObject.h"
#include "PrimitiveType.h"

namespace Engine
{
class ModelObject : public GameObject
{
public:
    ModelObject(const PrimitiveTypes& primitiveType);
    ModelObject(const PrimitiveTypes& primitiveType, string imagePath);
private:
};

} // Engine

#endif //EMPYRIA_MODELOBJECT_H
