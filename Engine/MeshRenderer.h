//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_MESHRENDERER_H
#define EMPYRIA_MESHRENDERER_H

#include "Component.h"
#include "Mesh.h"

namespace Engine
{

class MeshRenderer : public Component<MeshRenderer>
{
    friend class Mesh;

public:
    void update(float dt) override;
private:
    Mesh* mesh = nullptr;
    void render();
};

} // Engine

#endif //EMPYRIA_MESHRENDERER_H
