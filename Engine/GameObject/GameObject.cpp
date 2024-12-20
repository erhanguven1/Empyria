//
// Created by erhan güven on 19.06.2023.
//

#include "GameObject.h"
#include "../Physics/Rigidbody.h"

namespace Engine
{
void GameObject::update(float dt)
{
    for(auto comp : components)
    {
        if(comp.second != nullptr)
        {
            comp.second->update(dt);
            if(!render)
                continue;

            if(comp.first == string(typeid(UIRenderer).name()))
            {
                static_pointer_cast<UIRenderer>(comp.second)->render(*getComponent<RectTransform>());
            }
            else if(comp.first == string(typeid(MeshRenderer).name()))
            {
                static_pointer_cast<MeshRenderer>(comp.second)->render(*getComponent<Transform>());
            }
            else if(comp.first == string(typeid(TextRenderer).name()))
            {
                static_pointer_cast<TextRenderer>(comp.second)->render(*getComponent<RectTransform>());
            }
        }
    }
}

void GameObject::start()
{
    for(auto comp : components)
    {
        if(comp.second != nullptr)
            comp.second->start();
    }
}
} // Engine