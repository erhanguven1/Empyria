//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_GAMEOBJECT_H
#define EMPYRIA_GAMEOBJECT_H

#include <iostream>
#include "Component.h"
#include <unordered_map>
#include "Transform.h"
#include "RectTransform.h"
#include "MeshRenderer.h"
#include "UIRenderer.h"

#include <string>

using namespace std;

namespace Engine
{

class GameObject
{
public:
    virtual void update(float dt);

    template<class T>
    weak_ptr<T> getComponent()
    {
        string tName = string(typeid(T).name());
        return static_pointer_cast<T>(components[tName]);
    }

    template<class T>
    void addComponent()
    {
        string tName = string(typeid(T).name());
        assert("A GameObject can only have 1 of the same component!" && components[tName] == nullptr);
        components[tName] = make_shared<T>();
    }

private:
    unordered_map<string, shared_ptr<Component>> components;
};

} // Engine

#endif //EMPYRIA_GAMEOBJECT_H
