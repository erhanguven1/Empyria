//
// Created by erhan güven on 24.06.2023.
//

#include "MainMenuScene.h"
#include "Engine/SceneManager.h"
#include "Engine/InputHandler.h"
#include "Engine/ModelObject.h"
#include "Engine/Camera.h"
#include <map>
#include <glm/gtx/perpendicular.hpp>
namespace Empyria
{
MainMenuScene::MainMenuScene() : Scene()
{
    SceneManager::setActiveScene(this);

    //button1 = instantiateGameObject<UIObject>(1, "start_button.png");
    button2 = instantiateGameObject<UIObject>(2, "wall.jpg");

    modelObject = instantiateGameObject<ModelObject>(3, PrimitiveTypes::Cube,"front.png");
    modelObject->getComponent<Transform>()->position = vec3(0,0,-2.5f);

    auto* a = instantiateGameObject<ModelObject>(3, PrimitiveTypes::Cube, "right.png");
    a->getComponent<Transform>()->position = vec3(2.5f,0,0);

    auto* b = instantiateGameObject<ModelObject>(3, PrimitiveTypes::Cube, "back.png");
    b->getComponent<Transform>()->position = vec3(0,0,2.5f);

    auto* c = instantiateGameObject<ModelObject>(3, PrimitiveTypes::Cube, "left.png");
    c->getComponent<Transform>()->position = vec3(-2.5f,0,0);

    auto* d = instantiateGameObject<ModelObject>(3, PrimitiveTypes::Cube, "up.png");
    d->getComponent<Transform>()->position = vec3(0,5.0f,0);

    auto* e = instantiateGameObject<ModelObject>(3, PrimitiveTypes::Cube,"down.png");
    e->getComponent<Transform>()->position = vec3(0,-5.0f,0);
}

void MainMenuScene::update(float dt)
{
    Scene::update(dt);

    if (InputHandler::keyStates[GLFW_KEY_A] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_A] == GLFW_PRESS)
    {
        Camera::getInstance().position += Camera::getInstance().right*0.15f + vec3(-0.015f,0,0);
    }
    if (InputHandler::keyStates[GLFW_KEY_D] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_D] == GLFW_PRESS)
        Camera::getInstance().position -= Camera::getInstance().right*0.15f + vec3(-0.015f,0,0);

    if (InputHandler::keyStates[GLFW_KEY_W] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_W] == GLFW_PRESS)
        Camera::getInstance().position += Camera::getInstance().lookDirection*0.15f + vec3(0,0,-0.0015f);

    if (InputHandler::keyStates[GLFW_KEY_S] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_S] == GLFW_PRESS)
        Camera::getInstance().position += -Camera::getInstance().lookDirection*0.15f + vec3(0,0,0.0015f);

    if (InputHandler::keyStates[GLFW_KEY_LEFT] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_LEFT] == GLFW_PRESS)
        Camera::getInstance().rotation -= vec3(0,0.5f,0);
    if (InputHandler::keyStates[GLFW_KEY_RIGHT] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_RIGHT] == GLFW_PRESS)
        Camera::getInstance().rotation += vec3(0,0.5f,0);

    if (InputHandler::keyStates[GLFW_KEY_DOWN] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_DOWN] == GLFW_PRESS)
        Camera::getInstance().rotation -= vec3(0,0,0.5f);
    if (InputHandler::keyStates[GLFW_KEY_UP] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_UP] == GLFW_PRESS)
        Camera::getInstance().rotation += vec3(0,0,0.5f);

    if(button2 != nullptr)
    {
        if (InputHandler::keyStates[GLFW_KEY_P] == GLFW_PRESS)
            button2->destroy();
    }

    if(modelObject != nullptr)
    {
        //modelObject->getComponent<Transform>()->position += vec3(0.001f,0,0);
    }
}
} // Empyria