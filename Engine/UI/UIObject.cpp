//
// Created by erhan güven on 22.06.2023.
//

#include "UIObject.h"

namespace Engine
{
UIObject::UIObject(string imagePath, bool isButton)
{
    setOrder(getOrder()+1000);
    addComponent<RectTransform>();
    addComponent<UIRenderer>();
    if(auto uiRenderer = getComponent<UIRenderer>())
    {
        uiRenderer->init(imagePath, isButton);
    }
}
} // Engine