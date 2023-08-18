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
    inline void setTextColor(const vec4& col)
    {
        if(textColor != col)
            updatedTextColor = true;
        textColor = col;
    }
private:
    Engine::UIObject* background = nullptr;
    std::vector<Engine::TextObject*> elements;

    bool updatedTextColor = false;
protected:
    ListView() = delete;
    ListView(const glm::vec2& pos, const int& width, const int& height, const int& elementWidth, const int& elementHeight, const int& space, const Alignment& alignment);

    int width;
    int height;
    int elementWidth;
    int elementHeight;
    int space;
    Alignment alignment;
    vec4 textColor = vec4(0,0,0,1);
};

} // Engine

#endif //EMPYRIA_LISTVIEW_H
