//
// Created by erhan güven on 13.08.2023.
//

#ifndef EMPYRIA_INPUTFIELD_H
#define EMPYRIA_INPUTFIELD_H

#include "../Text/TextObject.h"
#include "../UI/UIObject.h"
#include "Engine/Scene/SceneManager.h"

namespace Engine
{

class InputField : public UIObject
{
public:
    InputField() : UIObject("",vec4(1,1,1,1),true)
    {
        textObject = SceneManager::getActiveScene()->instantiateGameObject<TextObject>(4,"abcdefghijklmnopqrstuvwxyz ",Font::arial);
        textObject->setText("");
        getComponent<RectTransform>()->scale.x= .75f;
        getComponent<RectTransform>()->scale.y = .25f;

        getComponent<UIRenderer>()->getButtonState().onRelease = [&]()
        {
            setSelectedInputField(*this);
            textObject->setText("");
        };
    }
    void update(float dt) override;
    inline TextObject* getTextObject()
    {
        return textObject;
    }

    inline void registerOnPressEnter(std::function<void()>& func)
    {
        onPressEnter.push_back(func);
    }

    inline static void setSelectedInputField(InputField& inputField)
    {
        selectedInputField = &inputField;
    }
    static void handleInputOnSelectedInputField(unsigned char& key);
private:
    TextObject* textObject = nullptr;
    inline static InputField* selectedInputField;
protected:
    std::vector<std::function<void()>> onPressEnter;
};

} // Engine

#endif //EMPYRIA_INPUTFIELD_H
