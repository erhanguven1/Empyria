//
// Created by erhan güven on 22.06.2023.
//

#include "UIObject.h"

namespace Engine
{
UIObject::UIObject()
{
    addComponent<RectTransform>();
    addComponent<UIRenderer>();
}
} // Engine