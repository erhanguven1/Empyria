//
// Created by erhan güven on 13.07.2023.
//

#include "GameScene.h"
#include "Engine/Input/InputHandler.h"
#include <map>
#include <glm/ext/matrix_projection.hpp>
#include "Engine/UI/UIObject.h"
#include "Engine/Physics/Rigidbody.h"
#include "Engine/Networking/UdpClient.h"
#include "Engine/Text/TextObject.h"
#include "../Scripts/ChatManager.h"


namespace Empyria
{
GameScene::GameScene()
{

}

void GameScene::start()
{
    Scene::start();

    auto* messageInputField = instantiateGameObject<InputField>(3);
    messageInputField->getComponent<RectTransform>()->position = vec2(-486,-612);
    messageInputField->getComponent<RectTransform>()->scale.x = 1.0f;
    messageInputField->getTextObject()->setText("usernamee");

    string k = "Joined as: " + Player::playerName;

    auto* joinedInfoText = instantiateGameObject<TextObject>(4,k.c_str(),Font::arial);
    joinedInfoText->getComponent<RectTransform>()->position = vec2(0,612);
    vec2 scale = vec2(.5f);
    joinedInfoText->getComponent<RectTransform>()->scale = scale;

    auto cursor = instantiateGameObject<UIObject>(1, "");
    cursor->getComponent<RectTransform>()->scale = vec2(.025f);

    ChatManager::setIsChatActive(false);

    ChunkManager* chunkManager = new ChunkManager;

    voxelRaycaster = new VoxelRaycaster;

    voxelRaycaster->chunkManager = chunkManager;

    vec3 spawnPos = vec3(5.0f,4.0f,5.0f);
    player = instantiateGameObject<Player>(1, spawnPos, *voxelRaycaster);
    player->getComponent<Transform>()->scale = vec3(0.01f);

    playerListView = instantiateGameObject<PlayerListView>(1);
    playerListView->addPlayer(Player::playerName);
    playerListView->getComponent<RectTransform>()->scale = vec2(.5f,1.0f);
    playerListView->getComponent<RectTransform>()->position = vec2(-750,0);

    auto pos = vec3(0.0f,0,0.0f);
    Chunk* c1 = instantiateGameObject<Chunk>(1,pos);
    c1->createChunk();
    chunkManager->chunks.push_back(c1);

    function onReceiveDataEvent = [&](char* buffer, int bufSize, int n)
    {
        if(n == sizeof(vec3))
        {
            vec3 receivedPos;
            memcpy(&receivedPos, buffer, sizeof(vec3));
            if(otherPlayer != nullptr)
            {
                otherPlayer->getComponent<Transform>()->position = receivedPos;
            }
        }
        else if(n == sizeof(BlockStateMessage))
        {
            BlockStateMessage msg;
            memcpy(&msg, buffer, sizeof(BlockStateMessage));
            if(msg.add)
                spawnedCube = true;
            else
                deletedCube = true;
            spawnedCubePos = msg.pos;
        }
        else
        {
            if(buffer[0]=='S')
            {
                first = true;
                spawned = true;
            }
        }
    };

    UdpClient::getInstance()->registerOnReceiveData(onReceiveDataEvent);

}

void GameScene::update(float dt)
{
    Scene::update(dt);

    if(spawned)
    {
        spawned = false;
        otherPlayer = instantiateGameObject<ModelObject>(3, PrimitiveTypes::Cube);
        otherPlayer->getComponent<Transform>()->position = vec3(5.0f,2.0f,5.0f);
        playerListView->addPlayer(Player::playerName);
        printf("Spawn second player");
    }

    if(spawnedCube)
    {
        spawnedCube = false;
        voxelRaycaster->spawnCubeAtPos(spawnedCubePos);
    }
    if(deletedCube)
    {
        deletedCube = false;
        voxelRaycaster->deleteCubeAtPos(spawnedCubePos);
    }

    if(InputHandler::onPressKey(GLFW_KEY_L))
    {
        ChatManager::setIsChatActive(!ChatManager::getIsChatActive());
    }

    if(ChatManager::getIsChatActive())
        return;

    if(InputHandler::onPressMouseButton(GLFW_MOUSE_BUTTON_1))
    {
        voxelRaycaster->deleteCube();
    }

    if(InputHandler::onPressMouseButton(GLFW_MOUSE_BUTTON_2))
    {
        voxelRaycaster->spawnCube();
    }

    Camera::getInstance().rotation -= vec3(0,-InputHandler::mouseMovement.x,InputHandler::mouseMovement.y);
}

} // Empyria