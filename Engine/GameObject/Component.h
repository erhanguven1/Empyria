//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_COMPONENT_H
#define EMPYRIA_COMPONENT_H

namespace Engine
{

class Component
{
public:
    virtual void start() = 0;
    virtual void update(float dt) = 0;
private:

};

} // Engine

#endif //EMPYRIA_COMPONENT_H