//
// Created by erhan güven on 19.06.2023.
//

#include "Mesh.h"

namespace Engine
{
void Mesh::init(const GLfloat *vertex_buffer_data, const size_t size, const int count1)
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vertexBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, size, vertex_buffer_data, GL_STATIC_DRAW);

    glBindVertexArray(vao);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
} // Engine