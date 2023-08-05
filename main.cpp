#include "Engine/EngineStarter.hpp"
#include "Empyria/Scenes/MainMenuScene.h"
#include "Empyria/Scenes/GameScene.h"
#include <future>

using namespace Empyria;

int main(int argc, char *argv[])
{
    startEngine();

    auto t = std::async(std::launch::async, &UdpClient::init, UdpClient::getInstance());

    auto* mainMenu = MainMenuScene::create();
    auto* game = GameScene::create();

    startLoop();
    UdpClient::getInstance()->closeSocket();
}
