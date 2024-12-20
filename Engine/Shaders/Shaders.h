//
// Created by erhan güven on 24.06.2023.
//

#ifndef EMPYRIA_SHADERS_H
#define EMPYRIA_SHADERS_H

#include "glad/glad.h"

namespace Engine
{

class Shaders
{
public:
    inline static GLuint uiShaderProgram;
    inline static GLuint standardShaderProgram;
    inline static GLuint textShaderProgram;
};

} // Engine

#endif //EMPYRIA_SHADERS_H
