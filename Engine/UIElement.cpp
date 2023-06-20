//
// Created by erhan güven on 20.06.2023.
//

#include "UIElement.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace Engine
{
void UIElement::render()
{
    // Clear the color buffer
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a colored rectangle
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.6f, 0.8f);
    glVertex2f(100.0f, 100.0f);
    glVertex2f(300.0f, 100.0f);
    glVertex2f(300.0f, 300.0f);
    glVertex2f(100.0f, 300.0f);
    glEnd();
}
} // Engine