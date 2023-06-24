//
// Created by erhan güven on 24.06.2023.
//

#ifndef EMPYRIA_UIRENDERER_H
#define EMPYRIA_UIRENDERER_H

#include "Component.h"
#include "Mesh.h"
#include "RectTransform.h"

namespace Engine
{

class UIRenderer : public Component
{
friend class Mesh;
public:
    UIRenderer();
    void update(float dt) override;
    void render(RectTransform& rectTransform);

private:
    Mesh* mesh = nullptr;
};

} // Engine

#endif //EMPYRIA_UIRENDERER_H
