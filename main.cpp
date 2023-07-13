#include <iostream>
#include "Engine/EngineStarter.hpp"
#include "Empyria/Scenes/MainMenuScene.h"

using namespace Empyria;

int main(int argc, char *argv[])
{
    startEngine();

    auto* mainMenu = MainMenuScene::create();

    startLoop();
}
