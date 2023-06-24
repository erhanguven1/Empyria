//
// Created by erhan güven on 24.06.2023.
//

#include "UIRenderer.h"
#include "Shaders/Shaders.h"

namespace Engine
{
UIRenderer::UIRenderer()
{
    GLfloat vertex_buffer_data[18] =
            {
                    -1,1,0,
                    -1,-1,0,
                    1,1,0,

                    -1,-1,0,
                    1,1,0,
                    1,-1,0,
            };

    mesh = new Mesh();
    mesh->init(vertex_buffer_data, sizeof(vertex_buffer_data), sizeof(vertex_buffer_data)/(3*sizeof(GLfloat)));
}

void UIRenderer::update(float dt)
{

}

void UIRenderer::render(RectTransform& rectTransform)
{
    glUseProgram(Shaders::uiShaderProgram);

    GLuint posID = glGetUniformLocation(Shaders::uiShaderProgram, "pos");
    //auto pos = glm::vec2(0.5f,-0.5f);
    glUniform2fv(posID, 1, &rectTransform.position[0]);

    glBindVertexArray(mesh->vao);
    glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle
}
} // Engine