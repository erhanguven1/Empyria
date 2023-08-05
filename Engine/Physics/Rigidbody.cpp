//
// Created by erhan güven on 1.08.2023.
//

#include "Rigidbody.h"

namespace Engine
{
void Rigidbody::start()
{

}

void Rigidbody::update(float dt)
{
    if(isGrounded)
        velocity->y = 0;
    else
        velocity->y -= 0.1f*dt;

    transform.position += *velocity;
}
} // Engine