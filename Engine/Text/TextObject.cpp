//
// Created by erhan güven on 11.08.2023.
//

#include "TextObject.h"

namespace Engine
{
TextObject::TextObject(const char* text, const Font& font, Alignment alignment)
{
    addComponent<RectTransform>();
    addComponent<TextRenderer>();
    getComponent<TextRenderer>()->init(font, text, alignment);
    setText(text);
}
} // Engine