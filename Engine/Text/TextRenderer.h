//
// Created by erhan güven on 10.08.2023.
//

#ifndef EMPYRIA_TEXTRENDERER_H
#define EMPYRIA_TEXTRENDERER_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include "Engine/GameObject/Component.h"
#include "Engine/UI/RectTransform.h"
#include "Engine/Mesh/Mesh.h"
#include <unordered_map>
#include <glm/glm.hpp>

namespace Engine
{

enum class Font
{
    arial
};

enum class Alignment
{
    LEFT,
    MIDDLE,
    RIGHT
};

struct Character {
    unsigned int TextureID;  // ID handle of the glyph texture
    glm::ivec2   Size;       // Size of glyph
    glm::ivec2   Bearing;    // Offset from baseline to left/top of glyph
    unsigned int Advance;    // Offset to advance to next glyph
};

class TextRenderer : public Component
{
public:
    void init(const Font& font, std::string text, Alignment al = Alignment::LEFT);
    void start() override;
    void update(float dt) override;
    void render(RectTransform& rectTransform);
    inline void setText(const char* t)
    {
        text = t;
    }
    inline void setColor(const vec4& col)
    {
        color = col;
    }

    inline void setAlpha(const float& alpha)
    {
        color.w = alpha;
    }
private:
    std::unordered_map<Font, const char*> fontNames
            {
                    {Font::arial, "arial"}
            };
    inline static std::unordered_map<char, Character> characters;
    Mesh* mesh = nullptr;
    std::string text = "";
    Alignment alignment;
    vec4 color = vec4(0,0,0,1);
};

} // Engine

#endif //EMPYRIA_TEXTRENDERER_H
