//
// Created by erhan güven on 24.06.2023.
//

#include "UIRenderer.h"
#include "Engine/Shaders/Shaders.h"
#define STB_IMAGE_IMPLEMENTATION
#include "Engine/stb_image.h"

namespace Engine
{
void UIRenderer::init(std::string texturePath)
{
    float vertex_buffer_data[] = {
            // positions                    // colors                      // texture coords
            0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
            0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f    // top left
    };

    mesh = new Mesh();
    if(texturePath == "")
        texturePath = "default_texture.png";
    mesh->initUIMesh(vertex_buffer_data, sizeof(vertex_buffer_data), sizeof(vertex_buffer_data) / (8 * sizeof(GLfloat)),
                     texturePath);
}

void UIRenderer::start()
{

}

void UIRenderer::update(float dt)
{

}

void UIRenderer::render(RectTransform& rectTransform)
{
    auto modifiedTransform = rectTransform;
    modifiedTransform.position.x /= 1024.0f;
    modifiedTransform.position.y /= 768.0f;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, 1024, 768, 0.0, -1.0, -10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_CULL_FACE);
    glClear(GL_DEPTH_BUFFER_BIT);
    glUseProgram(Shaders::uiShaderProgram);

    GLuint posID = glGetUniformLocation(Shaders::uiShaderProgram, "pos");
    glUniform2fv(posID, 1, &modifiedTransform.position[0]);

    GLuint scaleMultiplerId = glGetUniformLocation(Shaders::uiShaderProgram, "scale");
    glUniform2fv(scaleMultiplerId, 1, &modifiedTransform.scale[0]);

    glBindTexture(GL_TEXTURE_2D, mesh->texture);
    glBindVertexArray(mesh->vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
} // Engine