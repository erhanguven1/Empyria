//
// Created by erhan güven on 13.07.2023.
//

#include "GameScene.h"
#include "Engine/Input/InputHandler.h"
#include <map>
#include "../Scripts/ChatManager.h"


namespace Empyria
{
GameScene::GameScene()
{

}

void GameScene::start()
{
    Scene::start();

    ClientJoinMessage joinMessage;
    strcpy(joinMessage.playerName, Player::playerName.c_str());
    UdpClient::getInstance()->sendData(joinMessage);

    FetchOtherPlayerMessage fetchPlayerNameMsg;
    strcpy(fetchPlayerNameMsg.playerName, Player::playerName.c_str());
    UdpClient::getInstance()->sendData(fetchPlayerNameMsg);

    auto* messageInputField = instantiateGameObject<InputField>(3);
    messageInputField->getComponent<RectTransform>()->position = vec2(-486,-612);
    messageInputField->getComponent<RectTransform>()->scale.x = 1.0f;
    messageInputField->getTextObject()->setText("your message");

    std::function messageInput_onPressEnter = [messageInputField](){
        ChatMessage chatMsg;
        strcpy(chatMsg.sender, Player::playerName.c_str());
        strcpy(chatMsg.msg, messageInputField->getTextObject()->getText().c_str());
        UdpClient::getInstance()->sendData(chatMsg);
        messageInputField->getTextObject()->setText("");
    };

    messageInputField->registerOnPressEnter(messageInput_onPressEnter);

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
    playerListView->addElement(Player::playerName.c_str());

    chatView = instantiateGameObject<ChatView>(1);

    auto pos = vec3(0.0f,0,0.0f);
    Chunk* c1 = instantiateGameObject<Chunk>(1,pos);
    c1->createChunk();
    chunkManager->chunks.push_back(c1);

    function onReceiveDataEvent = [=](char* buffer, int bufSize, int n)
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
        else if(n == sizeof(ClientJoinMessage))
        {
            ClientJoinMessage msg;
            memcpy(&msg, buffer, sizeof(ClientJoinMessage));

            spawnSecondPlayer(msg);
        }
        else if(n == sizeof(ChatMessage))
        {
            ChatMessage msg;
            memcpy(&msg, buffer, sizeof(ClientJoinMessage));

            string message = msg.sender;
            message += ": ";
            message += msg.msg;

            chatView->addElement(message.c_str());
        }
        else if(n == sizeof(FetchOtherPlayerMessage))
        {
            FetchOtherPlayerMessage msg;
            memcpy(&msg, buffer, sizeof(FetchOtherPlayerMessage));

            playerListView->addElement(msg.playerName);
        }
    };

    UdpClient::getInstance()->registerOnReceiveData(onReceiveDataEvent);

}

void GameScene::update(float dt)
{
    Scene::update(dt);
    UdpClient::getInstance()->update();

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
        voxelRaycaster->deleteCube();

    if(InputHandler::onPressMouseButton(GLFW_MOUSE_BUTTON_2))
        voxelRaycaster->spawnCube();

    Camera::getInstance().rotation -= vec3(0,-InputHandler::mouseMovement.x,InputHandler::mouseMovement.y);
}

void GameScene::spawnSecondPlayer(ClientJoinMessage &msg)
{
    /*otherPlayer = instantiateGameObject<ModelObject>(3, PrimitiveTypes::Cube);
    otherPlayer->getComponent<Transform>()->position = vec3(5.0f,2.0f,5.0f);
    otherPlayer->getComponent<Transform>()->position = vec3(5.0f,2.0f,5.0f);*/
    playerListView->addElement(msg.playerName);
    printf("Spawn second player");
}

} // Empyria