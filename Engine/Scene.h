//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_SCENE_H
#define EMPYRIA_SCENE_H

#include <vector>
#include "GameObject.h"

namespace Engine
{

class Scene
{
public:
    Scene(unsigned int scene_id);
    inline static Scene* activeScene;

    inline void addGameObject(GameObject& gameObject){ gameObjects.push_back(&gameObject); }
private:
    int sceneId = -1;
    std::vector<GameObject*> gameObjects;
};

} // Engine

#endif //EMPYRIA_SCENE_H
