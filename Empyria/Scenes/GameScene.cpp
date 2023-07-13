//
// Created by erhan güven on 13.07.2023.
//

#include "GameScene.h"
#include "Engine/ModelObject.h"
#include "Engine/Input/InputHandler.h"
#include "Engine/ModelObject.h"
#include "Engine/Camera.h"
#include <map>
#include <glm/gtx/perpendicular.hpp>

namespace Empyria
{
GameScene::GameScene()
{
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

void GameScene::update(float dt)
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

}
} // Empyria