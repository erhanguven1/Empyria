//
// Created by erhan güven on 22.06.2023.
//

#ifndef EMPYRIA_RECTTRANSFORM_H
#define EMPYRIA_RECTTRANSFORM_H

#include "Component.h"
#include <glm/glm.hpp>
using namespace glm;
namespace Engine
{

class RectTransform : public Component
{
public:
    vec2 position = vec2(0);
    vec2 scale = vec2(1);

    void update(float dt) override;
private:

};

enum class SCREEN_FIXED_POSITIONS
{
    TOP = 0x01,
    BOTTOM = 0x02,
    LEFT = 0x4,
    RIGHT = 0x08,

};

} // Engine

#endif //EMPYRIA_RECTTRANSFORM_H
