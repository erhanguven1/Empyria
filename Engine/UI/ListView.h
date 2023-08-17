//
// Created by erhan güven on 16.08.2023.
//

#ifndef EMPYRIA_LISTVIEW_H
#define EMPYRIA_LISTVIEW_H

#define INCLUDE_TEXT
#include "Engine/EmpyriaEngine.h"

namespace Engine
{

class ListView : public GameObject
{
public:
    virtual void addElement(const char* element);
    void update(float dt) override;

private:
    Engine::UIObject* background = nullptr;
    std::vector<Engine::TextObject*> elements;
protected:
    ListView() = delete;
    ListView(const glm::vec2& pos, const int& width, const int& height, const int& elementWidth, const int& elementHeight, const int& space);

    int width;
    int height;
    int elementWidth;
    int elementHeight;
    int space;
};

} // Engine

#endif //EMPYRIA_LISTVIEW_H
