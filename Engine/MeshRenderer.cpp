//
// Created by erhan güven on 19.06.2023.
//

#include "MeshRenderer.h"

namespace Engine
{

void MeshRenderer::update(float dt)
{
    if(mesh != nullptr)
        render();
}

void MeshRenderer::render()
{

}

} // Engine