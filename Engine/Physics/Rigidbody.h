//
// Created by erhan güven on 1.08.2023.
//

#ifndef EMPYRIA_RIGIDBODY_H
#define EMPYRIA_RIGIDBODY_H

#include <glm/glm.hpp>
#include "Engine/GameObject/Component.h"
#include "Engine/GameObject/Transform.h"

using namespace glm;

namespace Engine
{

class Rigidbody : public Component
{
public:
    Rigidbody(Transform& tr) : transform(tr)
    {

    }

    bool isGrounded = false;
    vec3* velocity = new vec3(0,0,0);

    void start() override;

    void update(float dt) override;

private:
    Transform& transform;
};

} // Engine

#endif //EMPYRIA_RIGIDBODY_H
