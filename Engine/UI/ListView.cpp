//
// Created by erhan güven on 16.08.2023.
//

#include "ListView.h"

namespace Engine
{
ListView::ListView(const glm::vec2& pos,const int &width, const int &height, const int &elementWidth, const int &elementHeight,
                   const int &space,const Alignment& alignment) : width(width), height(height), elementWidth(elementWidth), elementHeight(elementHeight), space(space), alignment(alignment)
{
    background = Engine::SceneManager::getActiveScene()->instantiateGameObject<Engine::UIObject>(5,"default_texture_bordered.png",vec4(1,1,1,0.5f));
    background->getComponent<RectTransform>()->position = pos;
    background->getComponent<RectTransform>()->scale = vec2(width/1024.0f, height/768.0f);
}

void ListView::addElement(const char *element)
{
    auto* t = Engine::SceneManager::getActiveScene()->instantiateGameObject<Engine::TextObject>(6,element, Font::arial, alignment);
    t->setColor(textColor);
    elements.push_back(t);
}

void ListView::update(float dt)
{
    GameObject::update(dt);

    int i = 0;

    auto bgRectTransform = background->getComponent<Engine::RectTransform>();

    for(auto* element : elements)
    {
        if(updatedTextColor)
            element->setColor(textColor);

        auto elementRectTransform = element->getComponent<Engine::RectTransform>();

        elementRectTransform->position.x = bgRectTransform->position.x + (alignment == Alignment::LEFT ? width*1.85f : 0);
        elementRectTransform->position.y = bgRectTransform->position.y - height*0.35f + (space/30.0f)*(height*0.01f-i)*height/5.0f;

        float length = element->getText().length();

        float desiredScaleX = (50.0f*width/length) / 1024.0f;
        float scaleX = desiredScaleX <= width/1024.0f ? desiredScaleX : width/1024.0f;

        elementRectTransform->scale.x = scaleX;
        elementRectTransform->scale.y = scaleX * 0.5f / 0.375f;

        i++;
    }
}
} // Engine