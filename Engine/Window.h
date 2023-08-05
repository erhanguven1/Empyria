//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_WINDOW_H
#define EMPYRIA_WINDOW_H

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine
{

class Window
{
    friend class EmpyriaEngine;
public:
    bool init(int width, int height, std::string title);
    inline static GLFWwindow* getGLFWwindow(){ return glfwWindow; }
private:
    inline static GLFWwindow* glfwWindow = nullptr;
    inline static void setCursorEnable(bool isEnabled)
    {
        glfwSetInputMode(getGLFWwindow(), GLFW_CURSOR, isEnabled ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
    }
};

} // Engine

#endif //EMPYRIA_WINDOW_H
