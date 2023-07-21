//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_GAMEOBJECT_H
#define EMPYRIA_GAMEOBJECT_H

#include <iostream>
#include "Component.h"
#include <unordered_map>
#include "Engine/Mesh/MeshRenderer.h"
#include "Transform.h"
#include "Engine/UI/RectTransform.h"
#include "Engine/UI/UIRenderer.h"

#include <string>

using namespace std;

namespace Engine
{

class GameObject;

class GameObject
{
friend class Scene;
friend class shared_ptr;
public:
    virtual void start();
    virtual void update(float dt);

    template<class T>
    shared_ptr<T> getComponent()
    {
        string tName = string(typeid(T).name());
        weak_ptr<T> weakPtr = static_pointer_cast<T>(components[tName]);
        return weakPtr.lock();
    }

    template<class T>
    void addComponent()
    {
        string tName = string(typeid(T).name());
        assert("A GameObject can only have 1 of the same component!" && components[tName] == nullptr);
        components[tName] = make_shared<T>();
    }

    inline unsigned int getOrder() const { return order; }
    inline void setOrder(unsigned int _order) { order = _order; }

    void destroy()
    {
        isDead = true;
    }

    bool isDead = false;

private:
    unordered_map<string, shared_ptr<Component>> components;
    unsigned int order = 0;
    void deleteGameObject()
    {
        delete this;
    }

protected:
    virtual ~GameObject()
    {

    }
};

struct GameObjectDeleter
{
    void operator()(GameObject* go) const
    {
        go->destroy();
    }
};


template<class T, typename... Args>
unique_ptr<T,GameObjectDeleter> gameObject_shared_ptr(Args&&... args)
{
    return unique_ptr<T,GameObjectDeleter>(new T(std::forward<Args>(args)...), GameObjectDeleter());
}

} // Engine

#endif //EMPYRIA_GAMEOBJECT_H
