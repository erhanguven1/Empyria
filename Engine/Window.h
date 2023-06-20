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
public:
    bool init(int width, int height, std::string title);
    inline GLFWwindow* getGLFWwindow(){ return glfwWindow; }
private:
    GLFWwindow* glfwWindow = nullptr;
};

} // Engine

#endif //EMPYRIA_WINDOW_H
