//
// Created by erhan güven on 24.06.2023.
//

#include "MainMenuScene.h"
#include "Engine/Scene/SceneManager.h"
#include "Engine/Input/InputHandler.h"
#include "../Scripts/Player.h"

namespace Empyria
{
MainMenuScene::MainMenuScene() : Scene()
{
    SceneManager::setActiveScene(this);

    Player::playerName = "Player_" + to_string(rand() % 1000);

    usernameInputField = instantiateGameObject<InputField>(3);
    usernameInputField->getComponent<RectTransform>()->position.x = 0;
    usernameInputField->getComponent<RectTransform>()->position.y = 300;
    usernameInputField->getTextObject()->setText("username");

    background = instantiateGameObject<UIObject>(1, "Menu/bg.jpeg");
    background->getComponent<RectTransform>()->scale.x = 2.0f;
    background->getComponent<RectTransform>()->scale.y = 2.0f;

    playButton = instantiateGameObject<UIObject>(2, "Menu/start-button.png",vec4(1,1,1,1), true);
    playButton->getComponent<RectTransform>()->position.y = 0;
    playButton->getComponent<RectTransform>()->scale.x = 0.5f;
    playButton->getComponent<RectTransform>()->scale.y *= 0.25f;

    exitButton = instantiateGameObject<UIObject>(2, "Menu/exit-button.png",vec4(1,1,1,1), true);
    exitButton->getComponent<RectTransform>()->position.y = -200;
    exitButton->getComponent<RectTransform>()->scale.x = 0.5 * 0.75f;
    exitButton->getComponent<RectTransform>()->scale.y *= 0.25f * 0.75f;

    playButton->getComponent<UIRenderer>()->getButtonState().onRelease = [&]()
    {
        Player::playerName = usernameInputField->getTextObject()->getText();
        SceneManager::loadScene(1);
    };
}

void MainMenuScene::update(float dt)
{
    Scene::update(dt);

    if(playButton->getComponent<UIRenderer>()->getButtonState().getIsHovering())
        playButton->getComponent<RectTransform>()->scale = vec2(0.5f*1.05f,0.25f*1.05f);
    else
        playButton->getComponent<RectTransform>()->scale = vec2(0.5f,0.25f);

    if(exitButton->getComponent<UIRenderer>()->getButtonState().getIsHovering())
        exitButton->getComponent<RectTransform>()->scale = vec2(0.5f,0.25f);
    else
        exitButton->getComponent<RectTransform>()->scale = vec2(0.5f * 0.925f,0.25f * 0.925f);

    if(InputHandler::isPressingKey(GLFW_KEY_UP))
    {
        usernameInputField->getComponent<RectTransform>()->position.x += .5f;
        usernameInputField->getComponent<RectTransform>()->position.y += .5f;
    }
}
} // Empyria