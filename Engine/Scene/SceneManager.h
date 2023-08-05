//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_SCENEMANAGER_H
#define EMPYRIA_SCENEMANAGER_H

#include <unistd.h>
#include "Scene.h"

namespace Engine
{

class SceneManager
{
public:
    inline static void addScene(Scene* scene)
    {
        scenes.push_back(scene);
    }

    inline static Scene* getActiveScene()
    {
        return activeScene;
    }

    inline static void setActiveScene(Scene* scene)
    {
        activeScene = scene;
        activeScene->start();
    }

    inline static void loadScene(unsigned int sceneId)
    {
        setActiveScene(scenes[sceneId]);
    }

    inline static void loadScene(unsigned int sceneId, const unsigned int waitTime)
    {
        sleep(waitTime);
        setActiveScene(scenes[sceneId]);
    }

private:
    inline static Scene* activeScene;
    inline static std::vector<Scene*> scenes;
};

} // Engine

#endif //EMPYRIA_SCENEMANAGER_H
