//
// Created by erhan güven on 24.06.2023.
//

#ifndef EMPYRIA_MAINMENUSCENE_H
#define EMPYRIA_MAINMENUSCENE_H

#include "Engine/EmpyriaEngine.h"
#include "Engine/Scene/Scene.h"
#include "Engine/UI/UIObject.h"
#include "Engine/GameObject/ModelObject.h"

using namespace Engine;

namespace Empyria
{

class MainMenuScene : public Scene
{
public:
    REGISTER_CREATE(MainMenuScene)

    MainMenuScene();
    void update(float dt) override;
private:
    UIObject* background = nullptr;
    UIObject* playButton = nullptr;
    UIObject* exitButton = nullptr;
};

} // Empyria

#endif //EMPYRIA_MAINMENUSCENE_H
