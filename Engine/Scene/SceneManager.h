//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_SCENEMANAGER_H
#define EMPYRIA_SCENEMANAGER_H

#include "Scene.h"

namespace Engine
{

class SceneManager
{
public:
    inline static void addScene(Scene* scene)
    {
        //scene->sceneId = scenes.size();
        scenes.push_back(scene);
    }

    inline static Scene* getActiveScene()
    {
        return activeScene;
    }

    inline static void setActiveScene(Scene* scene)
    {
        activeScene = scene;
    }

    inline static void loadScene(unsigned int sceneId)
    {
        setActiveScene(scenes[sceneId]);
    }

private:
    inline static Scene* activeScene;
    inline static std::vector<Scene*> scenes;
};

} // Engine

#endif //EMPYRIA_SCENEMANAGER_H
