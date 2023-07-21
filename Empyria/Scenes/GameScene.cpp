//
// Created by erhan güven on 13.07.2023.
//

#include "GameScene.h"
#include "Engine/GameObject/ModelObject.h"
#include "Engine/Input/InputHandler.h"
#include "Engine/GameObject/ModelObject.h"
#include "Engine/Camera.h"
#include <map>
#include <glm/gtx/perpendicular.hpp>

namespace Empyria
{
GameScene::GameScene()
{
    auto* capsule = instantiateGameObject<ModelObject>(3, "capsule.obj", "");
    capsule->getComponent<Transform>()->position = vec3(10.0f,-1.0f,-8.0f);
    capsule->getComponent<Transform>()->scale = vec3(0.01f);

    auto* mountain = instantiateGameObject<ModelObject>(3, "mountain.obj", "");
    mountain->getComponent<Transform>()->position = vec3(10.0f,-20.0f,-5.5f);
    mountain->getComponent<Transform>()->scale = vec3(0.25f,0.1f,0.25f);

    auto* cube = instantiateGameObject<ModelObject>(3, "cube.obj", "");
    cube->getComponent<Transform>()->position = vec3(10.0f,-1.0f,-2.5f);
    cube->getComponent<Transform>()->scale = vec3(1.0f);

    auto* cylinder = instantiateGameObject<ModelObject>(3, "cylinder.obj", "");
    cylinder->getComponent<Transform>()->position = vec3(10.0f,-2.0f,1.0f);
    cylinder->getComponent<Transform>()->scale = vec3(1.0f);

    auto* dome = instantiateGameObject<ModelObject>(3, "dome.obj", "");
    dome->getComponent<Transform>()->position = vec3(10.0f,-2.0f,4.0f);
    dome->getComponent<Transform>()->scale = vec3(0.01f);

    auto* torus = instantiateGameObject<ModelObject>(3, "torus.obj", "");
    torus->getComponent<Transform>()->position = vec3(10.0f,-2.0f,7.0f);
    torus->getComponent<Transform>()->scale = vec3(0.01f);

    auto* torusknot = instantiateGameObject<ModelObject>(3, "torusknot.obj", "");
    torusknot->getComponent<Transform>()->position = vec3(10.0f,-2.0f,10.0f);
    torusknot->getComponent<Transform>()->scale = vec3(0.01f);

    car = instantiateGameObject<ModelObject>(3, "Car.obj", "");
    car->getComponent<Transform>()->position = vec3(10.0f,-2.0f,-7.0f);
    car->getComponent<Transform>()->scale = vec3(1.0f);
}

void GameScene::update(float dt)
{
    Scene::update(dt);
    car->getComponent<Transform>()->angle += 0.1f;
    car->getComponent<Transform>()->scale.y += sin(glfwGetTime())*0.0025f;

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