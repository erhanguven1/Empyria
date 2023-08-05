//
// Created by erhan güven on 24.06.2023.
//
//
// Created by erhan güven on 19.06.2023.
//


#include <iostream>
#include "Engine/Window.h"
#include "Engine/Input/InputHandler.h"
#include "Engine/loadShader.hpp"
#include "Engine/Shaders/Shaders.h"
#include "Engine/Scene/SceneManager.h"
#include "Engine/EmpyriaEngine.h"
#include "Engine/Networking/UdpClient.h"

bool isRunning = false;

const int width = 1024;
const int height = 768;

constexpr float calAspectRatio() { return 1.0f * width / height; }
constexpr float aspectRatio = calAspectRatio();

using namespace Engine;
Window* window = nullptr;
bool closeWindow = false;
void startEngine()
{
    window = new Window();
    window->init(width, height, "Empyria");

    vec2* v = new vec2(width, height);
    EmpyriaEngine::setScreenSize(*v);

    InputHandler* inputHandler = new InputHandler();

    EmpyriaEngine::setCursorEnable(true);

    // Set the key callback function using a lambda function
    glfwSetKeyCallback(window->getGLFWwindow(), [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        InputHandler* instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        instance->keyEvent(key, action);
    });

    glfwSetCursorPosCallback(window->getGLFWwindow(), [](GLFWwindow* window, double xPos, double yPos)
    {
        InputHandler* instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        instance->cursorPosEvent(xPos, yPos);
    });

    glfwSetMouseButtonCallback(window->getGLFWwindow(), [](GLFWwindow* window, int button, int action, int mods)
    {
        InputHandler* instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        instance->mouseButtonEvent(button, action, mods);
    });

    // Set the user pointer for the window
    glfwSetWindowUserPointer(window->getGLFWwindow(), &inputHandler);

    Shaders::uiShaderProgram = LoadShaders( "/Users/erhanguven/CLionProjects/Empyria/Engine/Shaders/DefaultUIShader.vertexshader", "/Users/erhanguven/CLionProjects/Empyria/Engine/Shaders/DefaultUIShader.fragmentshader" );
    Shaders::standardShaderProgram = LoadShaders( "/Users/erhanguven/CLionProjects/Empyria/Engine/Shaders/DefaultShader.vertexshader", "/Users/erhanguven/CLionProjects/Empyria/Engine/Shaders/DefaultShader.fragmentshader" );

    isRunning = true;
}

void startLoop()
{
    const double fpsLimit = 1.0 / 120.0;
    double lastUpdateTime = 0;  // number of seconds since the last loop
    double lastFrameTime = 0;   // number of seconds since the last frame

    while( !closeWindow && (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window->getGLFWwindow()) == 0) )
    {
        double now = glfwGetTime();
        double deltaTime = now - lastUpdateTime;

        InputHandler::mouseMovement.x = 0;
        InputHandler::mouseMovement.y = 0;

        glfwWaitEventsTimeout(fpsLimit);


        if ((now - lastFrameTime) >= fpsLimit)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glUseProgram(Shaders::uiShaderProgram);

            SceneManager::getActiveScene()->update(now - lastFrameTime);

            glfwSwapBuffers(window->getGLFWwindow());
            lastFrameTime = now;
        }

        //lastFrameTime = now;

    }

    isRunning = false;

}