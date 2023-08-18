//
// Created by erhan güven on 24.06.2023.
//

#include "UIRenderer.h"
#include "Engine/Shaders/Shaders.h"
#define STB_IMAGE_IMPLEMENTATION
#include "Engine/stb_image.h"
#include "../Input/InputHandler.h"
#include <iostream>

namespace Engine
{
void UIRenderer::init(std::string texturePath, vec4 col, bool _isButton)
{
    color = col;
    isButton = _isButton;

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

    int left = rectTransform.position.x/2 - (mesh->rawWidth / 1024.0f) * rectTransform.scale.x * mesh->rawWidth/2*0-512*rectTransform.scale.x/2;
    int right = rectTransform.position.x/2 + (mesh->rawWidth / 1024.0f) * rectTransform.scale.x * mesh->rawWidth/2*0+512*rectTransform.scale.x/2;
    int up = rectTransform.position.y/2 + (mesh->rawHeight / 768.0f) * rectTransform.scale.y * mesh->rawHeight*0+384*rectTransform.scale.y/2;
    int down = rectTransform.position.y/2 - (mesh->rawHeight / 768.0f) * rectTransform.scale.y * mesh->rawHeight/2*0-384*rectTransform.scale.y/2;

    if(isButton)
        updateRaycastInfo(left,right,up,down);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, 1024, 768, 0.0, -1.0, -5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_CULL_FACE);
    glClear(GL_DEPTH_BUFFER_BIT);
    glUseProgram(Shaders::uiShaderProgram);

    GLuint posID = glGetUniformLocation(Shaders::uiShaderProgram, "pos");
    glUniform2fv(posID, 1, &modifiedTransform.position[0]);

    GLuint scaleMultiplerId = glGetUniformLocation(Shaders::uiShaderProgram, "scale");
    glUniform2fv(scaleMultiplerId, 1, &modifiedTransform.scale[0]);

    GLuint colorId = glGetUniformLocation(Shaders::uiShaderProgram, "color");
    glUniform3fv(colorId, 1, &color[0]);

    GLuint alphaId = glGetUniformLocation(Shaders::uiShaderProgram, "alpha");
    glUniform1f(alphaId, color.w);

    glBindTexture(GL_TEXTURE_2D, mesh->texture);
    glBindVertexArray(mesh->vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

void UIRenderer::updateRaycastInfo(int& left, int& right, int& top, int& bottom)
{
    auto mousePos = (InputHandler::mousePosition - vec2(1024/2,768/2));
    mousePos.y *= -1;
    buttonState.isHovering = (left < mousePos.x && right > mousePos.x) && (top > mousePos.y && bottom < mousePos.y);

    if(buttonState.isHovering)
    {
        if(!buttonState.isClicked)
        {
            buttonState.isClicked = InputHandler::mouseStates[0] == 1;
            if(buttonState.isClicked)
            {
                color = vec4(.5f,.5f,.5f, 1.0f);
                buttonState.onClick();
            }
            else
            {
                color = vec4(.75f,.75f,.75f, 1.0f);
            }
        }
        else
        {
            if(InputHandler::mouseStates[0] == 0)
            {
                buttonState.isClicked = false;
                color = vec4(.75f,.75f,.75f,1);
                    buttonState.onRelease();
            }
        }
    }
    else
    {
        buttonState.isClicked = false;
        color = vec4(1,1,1,1);
    }
}
} // Engine