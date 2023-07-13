//
// Created by erhan güven on 19.06.2023.
//

#include "Scene.h"
#include "SceneManager.h"

namespace Engine
{

Scene::Scene()
{
    SceneManager::addScene(this);
}

void Scene::start()
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        auto count = gameObjects[i].size();
        for(int j = 0; j < count; j++)
        {
            auto go = gameObjects[i][j].get();
            if(go == nullptr)
                continue;

            go->start();
        }
    }
}

void Scene::update(float dt)
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        auto count = gameObjects[i].size();
        for(int j = 0; j < count; j++)
        {
            auto go = gameObjects[i][j].get();
            if(go == nullptr)
                continue;

            if (go->isDead)
            {
                go->isDead = false;

                gameObjects[go->getOrder()][j]->deleteGameObject();
                //gameObjects[i].erase(gameObjects[i].begin() + j);

                gameObjects[i][j].release();
                j--;
                continue;
            }
            go->update(dt);
        }
        /*for(auto go : pair.second)
        {
            if (go->isDead)
            {
                go->isDead = false;
                removeGameObject(go->getOrder(), i);
                go.reset();
                auto* k = go.get();
                continue;
            }
            go->update(dt);
            i++;
        }*/
    }
}

} // Engine