//
// Created by erhan güven on 10.08.2023.
//

#include "TextRenderer.h"
#include "glad/glad.h"
#include "Engine/Shaders/Shaders.h"
#include "Engine/Camera.h"
#include <iostream>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace Engine
{
void TextRenderer::init(const Font &font, std::string text)
{
    this->text = text;
    std::string fontStr = "/Users/erhanguven/CLionProjects/Empyria/Engine/Fonts/";
    fontStr += fontNames[font];
    fontStr += ".ttf";

    FT_Library ft;
    if (FT_Init_FreeType(&ft))
    {
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
        return;
    }

    FT_Face face;
    if (FT_New_Face(ft, fontStr.c_str(), 0, &face))
    {
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
        return;
    }

    FT_Set_Pixel_Sizes(face, 0, 48);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

    for (unsigned char c : text)
    {
        if(characters.find(c) != characters.end()) //If key exists, do not add it again
            continue;

        // load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }
        // generate texture
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,
                GL_RED,
                GL_UNSIGNED_BYTE,
                face->glyph->bitmap.buffer
        );
        // set texture options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // now store character for later use
        Character character = {
                texture,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                static_cast<unsigned int>(face->glyph->advance.x)
        };

        characters.insert(std::pair<char, Character>(c, character));
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    mesh = new Mesh();
    mesh->initTextMesh();

    glm::mat4 projection = glm::ortho(0.0f, 1024.0f, 0.0f, 768.0f);
    glUseProgram(Shaders::textShaderProgram);
    glUniformMatrix4fv(glGetUniformLocation(Shaders::textShaderProgram, "projection"), 1, GL_FALSE, &projection[0][0]);
}

void TextRenderer::start()
{

}

void TextRenderer::update(float dt)
{

}

void TextRenderer::render(Engine::RectTransform &rectTransform)
{
    float x = 400.0f*rectTransform.position.x/1024.0f + 256*1.55 - text.length() * 12.5f;
    float y = 370 + rectTransform.position.y * .5f;

    float scaleX = rectTransform.scale.x;
    float scaleY = rectTransform.scale.y;

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

    glm::vec3 color = vec3(0,0,0);
    glUseProgram(Shaders::textShaderProgram);
    glUniform3f(glGetUniformLocation(Shaders::textShaderProgram, "textColor"), color.x, color.y, color.z);

    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(mesh->vao);

    // iterate through all characters
    std::string::const_iterator c;

    float ww = 0;

    for (c = text.begin(); c != text.end(); c++)
    {
        Character ch = characters[*c];
        ww += (ch.Size.x) * scaleX / 2.0f + ch.Bearing.x / 2.0f;
    }

    x = rectTransform.position.x/2.0f + 768/1.5f - ww;

    for (c = text.begin(); c != text.end(); c++)
    {
        Character ch = characters[*c];

        float xpos = x + ch.Bearing.x * scaleX;
        float ypos = y - (ch.Size.y - ch.Bearing.y) * scaleY;

        float w = ch.Size.x * scaleX;
        float h = ch.Size.y * scaleY;
        // update VBO for each character
        float vertices[6][4] = {
                { xpos,     ypos + h,   0.0f, 0.0f },
                { xpos,     ypos,       0.0f, 1.0f },
                { xpos + w, ypos,       1.0f, 1.0f },

                { xpos,     ypos + h,   0.0f, 0.0f },
                { xpos + w, ypos,       1.0f, 1.0f },
                { xpos + w, ypos + h,   1.0f, 0.0f }
        };
        // render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        // update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        x += (ch.Advance >> 6) * scaleX; // bitshift by 6 to get value in pixels (2^6 = 64)
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}
} // Engine