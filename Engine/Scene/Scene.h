//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_SCENE_H
#define EMPYRIA_SCENE_H

#include <vector>
#include "Engine/GameObject.h"
#include <map>

namespace Engine
{

class Scene
{
public:
    template<class T, typename... Args>
    inline T* instantiateGameObject(int order, Args&&... args)
    {
        gameObjects[order].push_back(gameObject_shared_ptr<T>(std::forward<Args>(args)...));
        gameObjects[order].back().get()->setOrder(order);
        return (T*)gameObjects[order].back().get();
    }

    virtual void start();
    virtual void update(float dt);
    int sceneId = -1;
    Scene();

    std::map<int, vector<unique_ptr<GameObject, GameObjectDeleter>>> gameObjects;
};

} // Engine

#endif //EMPYRIA_SCENE_H
