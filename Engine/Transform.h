//
// Created by erhan güven on 22.06.2023.
//

#ifndef EMPYRIA_TRANSFORM_H
#define EMPYRIA_TRANSFORM_H

#include "Component.h"
#include <glm/glm.hpp>

using namespace glm;

namespace Engine
{

class Transform : public Component
{
public:
    vec3 position = vec3(0);
    vec3 scale = vec3(1);

    void update(float dt) override
    {

    }

private:
};

} // Engine

#endif //EMPYRIA_TRANSFORM_H
