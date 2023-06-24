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
    friend class UIRenderer;
    friend class MeshRenderer;

public:
    void init(const GLfloat vertexBufferData[], const size_t size, const int count1);

private:
    GLfloat vertex_buffer_data[18] =
            {
                    -1,1,0,
                    -1,-1,0,
                    1,1,0,

                    -1,-1,0,
                    1,1,0,
                    1,-1,0,
            };
    GLuint vertexBuffer;
    GLuint vao;
};

} // Engine

#endif //EMPYRIA_MESH_H
