//
// Created by erhan güven on 13.07.2023.
//

#include "GameScene.h"
#include "Engine/Input/InputHandler.h"
#include <map>
#include "Engine/UI/UIObject.h"
#include "Engine/Physics/Rigidbody.h"
#include "Engine/Networking/UdpClient.h"


namespace Empyria
{
GameScene::GameScene()
{

}

void GameScene::start()
{
    Scene::start();

    EmpyriaEngine::setCursorEnable(false);

    auto cursor = instantiateGameObject<UIObject>(1, "");
    cursor->getComponent<RectTransform>()->scale = vec2(.025f);


    ChunkManager* chunkManager = new ChunkManager;
    voxelRaycaster = new VoxelRaycaster;

    vec3 spawnPos = vec3(5.0f,4.0f,5.0f);
    player = instantiateGameObject<Player>(3, spawnPos, *voxelRaycaster);
    player->getComponent<Transform>()->scale = vec3(0.01f);

    voxelRaycaster->chunkManager = chunkManager;

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