//
// Created by erhan güven on 19.06.2023.
//
#include <iostream>
#include "Engine/Window.h"
#include "Engine/InputHandler.h"
#include "Engine/loadShader.hpp"
#include "Engine/UIObject.h"
#include "Engine/Shaders/Shaders.h"

const int width = 1280;
const int height = 720;

constexpr float calAspectRatio() { return 1.0f * width / height; }
constexpr float aspectRatio = calAspectRatio();

using namespace Engine;

#pragma region VertexBufferData
GLfloat g_vertex_buffer_data[] = {
        -1.0f,-1.0f,-1.0f, // triangle 1 : begin
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, // triangle 1 : end
        1.0f, 1.0f,-1.0f, // triangle 2 : begin
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f, // triangle 2 : end
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f
};
#pragma endregion

int main(int argc, char *argv[])
{
    Window* window = new Window();
    window->init(width, height, "Empyria");

    InputHandler* inputHandler = new InputHandler();

    GameObject* go = new GameObject();
    go->addComponent<Transform>();
    go->addComponent<MeshRenderer>();
    go->addComponent<UIRenderer>();


    // Set the key callback function using a lambda function
    glfwSetKeyCallback(window->getGLFWwindow(), [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        InputHandler* instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        instance->keyEvent(key, action);
    });

    // Set the user pointer for the window
    glfwSetWindowUserPointer(window->getGLFWwindow(), &inputHandler);

    UIObject* uiObject = new UIObject;
    uiObject->getComponent<RectTransform>().lock()->position += vec2(-0.001f,0);

    Shaders::uiShaderProgram = LoadShaders( "/Users/erhanguven/CLionProjects/Empyria/Engine/Shaders/DefaultUIShader.vertexshader", "/Users/erhanguven/CLionProjects/Empyria/Engine/Shaders/DefaultUIShader.fragmentshader" );

    while( glfwGetKey(window->getGLFWwindow(), GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window->getGLFWwindow()) == 0 )
    {

        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(Shaders::uiShaderProgram);

        uiObject->update(0);

        glfwSwapBuffers(window->getGLFWwindow());
    }

    return 1;
}