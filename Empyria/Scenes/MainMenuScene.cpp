//
// Created by erhan güven on 24.06.2023.
//

#include "MainMenuScene.h"
#include "Engine/Scene/SceneManager.h"
#include "Engine/Input/InputHandler.h"

namespace Empyria
{
MainMenuScene::MainMenuScene() : Scene()
{
    SceneManager::setActiveScene(this);

    background = instantiateGameObject<UIObject>(1, "Menu/bg.jpeg");
    background->getComponent<RectTransform>()->scale.x = 4;
    background->getComponent<RectTransform>()->scale.y = 2;

    playButton = instantiateGameObject<UIObject>(2, "Menu/start-button.png");
    playButton->getComponent<RectTransform>()->position.y = -768/2;
    playButton->getComponent<RectTransform>()->scale.x *= 0.5f;
    playButton->getComponent<RectTransform>()->scale.y *= 0.5f;
}

void MainMenuScene::update(float dt)
{
    Scene::update(dt);

    if(InputHandler::onPressKey(GLFW_KEY_SPACE))
    {
        SceneManager::loadScene(1);
    }
}
} // Empyria