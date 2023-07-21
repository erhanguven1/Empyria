//
// Created by erhan güven on 24.06.2023.
//

#ifndef EMPYRIA_UIRENDERER_H
#define EMPYRIA_UIRENDERER_H

#include "Engine/GameObject/Component.h"
#include "Engine/Mesh/Mesh.h"
#include "RectTransform.h"
#include <functional>

namespace Engine
{

class AetheriaFunction
{
public:
    void operator()()
    {
        if(func != nullptr)
            func();
    }
    AetheriaFunction& operator=(const std::function<void()>& f)
    {
        func = f;
        return *this;
    }

private:
    std::function<void()> func;
};

class ButtonState
{
    friend class UIRenderer;
public:
    inline bool getIsClicked(){ return isClicked; }
    inline bool getIsHovering() { return isHovering; }
    AetheriaFunction onClick;
    AetheriaFunction onRelease;

private:
    bool isHovering = false;
    bool isClicked = false;
};

class UIRenderer : public Component
{
friend class Mesh;
public:
    void init(std::string texturePath = "", bool _isButton = false);

    void start() override;
    void update(float dt) override;
    void render(RectTransform& rectTransform);

    inline void setIsButton(bool val){ isButton = val; }
    inline bool getIsButton() const{ return isButton; }

    inline ButtonState& getButtonState(){ return buttonState; }

    vec3 color = vec3(1.0f);
private:
    Mesh* mesh = nullptr;
    bool isButton = false;
    ButtonState buttonState;

    void updateRaycastInfo(int& left, int& right, int& top, int& bottom);

};

} // Engine

#endif //EMPYRIA_UIRENDERER_H
