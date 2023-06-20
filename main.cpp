//
// Created by erhan güven on 19.06.2023.
//
#include <iostream>
#include "Engine/Window.h"
#include "Engine/InputHandler.h"
#include "Engine/UIElement.h"

const int width = 1280;
const int height = 720;

constexpr float calAspectRatio() { return 1.0f * width / height; }
constexpr float aspectRatio = calAspectRatio();

using namespace Engine;

int main(int argc, char *argv[])
{
    Window* window = new Window();
    window->init(width, height, "Empyria");

    InputHandler* inputHandler = new InputHandler();

    // Set the key callback function using a lambda function
    glfwSetKeyCallback(window->getGLFWwindow(), [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        InputHandler* instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        instance->keyEvent(key, action);
    });

    // Set the user pointer for the window
    glfwSetWindowUserPointer(window->getGLFWwindow(), &inputHandler);

    UIElement* uiElement = new UIElement;

    while( glfwGetKey(window->getGLFWwindow(), GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window->getGLFWwindow()) == 0 )
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        uiElement->render();

        glfwSwapBuffers(window->getGLFWwindow());
    }

    return 1;
}