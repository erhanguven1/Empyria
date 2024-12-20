//
// Created by erhan güven on 19.06.2023.
//

#ifndef EMPYRIA_MESH_H
#define EMPYRIA_MESH_H

#include "include/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

namespace Engine
{

class Mesh
{
    friend class UIRenderer;
    friend class MeshRenderer;
    friend class TextRenderer;

public:
    void initUIMesh(const GLfloat vertex_buffer_data[], const size_t size, const int count1, std::string& path);
    void initTextMesh();
    void initMesh(const GLfloat vertex_buffer_data[], const GLuint indices[], const size_t vertexBufferSize, const size_t indicesSize, std::string& path);
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
    GLuint elementBuffer;
    GLuint vao;
    GLuint texture;

    int rawWidth;
    int rawHeight;

    int indexBufferElementCount = 0;
    int vertexBufferSize = 0;
};

} // Engine

#endif //EMPYRIA_MESH_H
