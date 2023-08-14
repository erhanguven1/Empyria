//
// Created by erhan güven on 13.08.2023.
//

#include "InputField.h"

namespace Engine
{
void InputField::update(float dt)
{
    GameObject::update(dt);
    if(textObject != nullptr)
    {
        textObject->getComponent<RectTransform>()->position = getComponent<RectTransform>()->position;
    }
}

void InputField::handleInputOnSelectedInputField(unsigned char &key)
{

    if(selectedInputField == nullptr)
        return;

    int k = key;

    if(key >= 97 && key <= 122 || key == 32)
    {
        string s = "";
        s+=key;
        selectedInputField->textObject->addText(s.c_str());
    }
    else if(k == 3) //Backspace
    {
        selectedInputField->textObject->removeFromBack();
    }

}
} // Engine