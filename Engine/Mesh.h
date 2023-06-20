//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_MESH_H
#define EMPYRIA_MESH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Engine
{

class Mesh
{
public:
    void init(const GLfloat vertex_buffer_data[], const size_t size, const int count1);

private:
    GLuint* vertexBuffer = nullptr;
    GLuint* colorBuffer = nullptr;
    GLuint vao;
    GLuint vertexCount;
};

} // Engine

#endif //EMPYRIA_MESH_H
