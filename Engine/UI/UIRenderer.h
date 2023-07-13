//
// Created by erhan güven on 24.06.2023.
//

#ifndef EMPYRIA_UIRENDERER_H
#define EMPYRIA_UIRENDERER_H

#include "Engine/Component.h"
#include "Engine/Mesh/Mesh.h"
#include "RectTransform.h"

namespace Engine
{

class UIRenderer : public Component
{
friend class Mesh;
public:
    void init(std::string texturePath = "");

    void start() override;
    void update(float dt) override;
    void render(RectTransform& rectTransform);

private:
    Mesh* mesh = nullptr;
};

} // Engine

#endif //EMPYRIA_UIRENDERER_H
