//
// Created by erhan güven on 16.08.2023.
//

#include "ListView.h"

namespace Engine
{
ListView::ListView(const glm::vec2& pos,const int &width, const int &height, const int &elementWidth, const int &elementHeight,
                   const int &space) : width(width), height(height), elementWidth(elementWidth), elementHeight(elementHeight), space(space)
{
    background = Engine::SceneManager::getActiveScene()->instantiateGameObject<Engine::UIObject>(5,"");
    background->getComponent<RectTransform>()->position = pos;
    background->getComponent<RectTransform>()->scale = vec2(width/1024.0f, height/768.0f);
}

void ListView::addElement(const char *element)
{
    auto* t = Engine::SceneManager::getActiveScene()->instantiateGameObject<Engine::TextObject>(6,element);
    elements.push_back(t);
}

void ListView::update(float dt)
{
    GameObject::update(dt);

    int i = 0;

    auto bgRectTransform = background->getComponent<Engine::RectTransform>();

    for(auto* element : elements)
    {
        auto elementRectTransform = element->getComponent<Engine::RectTransform>();

        elementRectTransform->position.x = bgRectTransform->position.x;
        elementRectTransform->position.y = bgRectTransform->position.y - height*0.4f + (4-i)*75.0f;

        float length = element->getText().length();

        elementRectTransform->scale.x = (14.0f*width/length) / 1024.0f;
        elementRectTransform->scale.y = 1.4f*height / 768.0f;

        i++;
    }
}
} // Engine