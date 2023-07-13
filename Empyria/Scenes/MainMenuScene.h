//
// Created by erhan güven on 24.06.2023.
//

#ifndef EMPYRIA_MAINMENUSCENE_H
#define EMPYRIA_MAINMENUSCENE_H

#include "Engine/EmpyriaEngine.h"
#include "Engine/Scene.h"
#include "Engine/UIObject.h"
#include "Engine/ModelObject.h"

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
    UIObject* button1 = nullptr;
    UIObject* button2 = nullptr;
    ModelObject* modelObject = nullptr;

};

} // Empyria

#endif //EMPYRIA_MAINMENUSCENE_H
