//
// Created by erhan güven on 28.07.2023.
//

#include "Player.h"
#include "../Engine/Input/InputHandler.h"
#include "../Engine/Physics/Rigidbody.h"
#include "Engine/Networking/UdpClient.h"
#include "ChatManager.h"

namespace Empyria
{

Player::Player(vec3& spawnPosition, VoxelRaycaster& voxelRaycaster) : ModelObject("capsule.obj", "") , camera(Camera::getInstance()), m_voxelRaycaster(voxelRaycaster)
{
    getComponent<Transform>()->position = spawnPosition;
    addComponent<Rigidbody>(*getComponent<Transform>());
    instance = this;
}

void Player::update(float dt)
{
    GameObject::update(dt);

    auto camLook = camera.cameraFront;
    camLook.y = 0;

    auto camRight = camera.right;
    camRight.y = 0;

    auto transform = getComponent<Transform>();
    getComponent<Rigidbody>()->isGrounded = m_voxelRaycaster.cubeAtTheBottom() != nullptr;

    auto deltaPos = vec3(0,0,0);

    if ((InputHandler::keyStates[GLFW_KEY_Q] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_Q] == GLFW_PRESS))
    {
        if(UdpClient::getInstance() != nullptr)
        {
            glm::vec3 pos = getComponent<Transform>()->position;

            UdpClient::getInstance()->sendData(pos);
        }
    }

    if(!ChatManager::getIsChatActive())
    {
        if ((InputHandler::keyStates[GLFW_KEY_A] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_A] == GLFW_PRESS))
            deltaPos -= camRight*0.05f;

        if ((InputHandler::keyStates[GLFW_KEY_D] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_D] == GLFW_PRESS))
            deltaPos += camRight*0.05f;

        if (InputHandler::keyStates[GLFW_KEY_W] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_W] == GLFW_PRESS)
            deltaPos += camLook*0.05f;

        if (InputHandler::keyStates[GLFW_KEY_S] == GLFW_REPEAT || InputHandler::keyStates[GLFW_KEY_S] == GLFW_PRESS)
            deltaPos += -camLook*0.05f;

        auto blocksAroundPlayer = m_voxelRaycaster.blocksAroundPoint(getComponent<Transform>()->position);

        if(blocksAroundPlayer[0] != nullptr)
        {
            if(deltaPos.z < 0)
                deltaPos.z = 0.0f;
        }

        if(blocksAroundPlayer[1] != nullptr)
        {
            if(deltaPos.z > 0)
                deltaPos.z = 0.0f;
        }

        if(blocksAroundPlayer[2] != nullptr)
        {
            if(deltaPos.x < 0)
                deltaPos.x = 0.0f;
        }

        if(blocksAroundPlayer[3] != nullptr)
        {
            if(deltaPos.x > 0)
                deltaPos.x = 0.0f;
        }

        if(InputHandler::onPressKey(GLFW_KEY_SPACE))
        {
            getComponent<Rigidbody>()->velocity->y = .075f;
            getComponent<Rigidbody>()->isGrounded = false;
        }

        transform->position+=deltaPos;

        camera.position = transform->position + vec3(0,1.25f,0);
    }

}
} // Empyria