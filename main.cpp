#include <iostream>
#include "Engine/EngineStarter.hpp"
#include "Empyria/Scenes/MainMenuScene.h"
#include "Empyria/Scenes/GameScene.h"
#include<unistd.h>
using namespace Empyria;

int main(int argc, char *argv[])
{
    startEngine();

    auto* mainMenu = MainMenuScene::create();
    auto* game = GameScene::create();

    startLoop();
}
