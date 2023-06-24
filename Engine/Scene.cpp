//
// Created by erhan güven on 19.06.2023.
//

#include "Scene.h"

namespace Engine
{

Scene::Scene(unsigned int scene_id)
{

}

void Scene::update(float dt)
{
    for(auto go : gameObjects)
    {
        go->update(dt);
    }
}

} // Engine