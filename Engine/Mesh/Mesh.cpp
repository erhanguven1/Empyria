//
// Created by erhan güven on 19.06.2023.
//

#include "Mesh.h"
#include "Engine/stb_image.h"

namespace Engine
{
void Mesh::initUIMesh(const GLfloat *vertex_buffer_data, const size_t size, const int count1, std::string& path)
{
    unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };

    indexBufferElementCount = 6;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &elementBuffer);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, size, vertex_buffer_data, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // xxxx,yyyy,zzzz,rrrr,gggg,bbbb,uuuu,vvvv - xxxx,yyyy,......

    //vertex positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //vertex colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //vertex texture coords
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_set_flip_vertically_on_load(true);

    // load image, create texture and generate mipmaps
    int nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *data = stbi_load(("/Users/erhanguven/CLionProjects/Empyria/Empyria/Textures/"+path).c_str(), &rawWidth, &rawHeight, &nrChannels, 0);
    if (data)
    {
        if(nrChannels == 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, rawWidth, rawHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        else if(nrChannels == 4)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, rawWidth, rawHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Data couldn't be loaded");
    }
    stbi_image_free(data);
    glBindVertexArray(0);

}

void Mesh::initTextMesh()
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vertexBuffer);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Mesh::initMesh(const GLfloat *vertex_buffer_data, const GLuint *indices, const size_t vertexBufferSize, const size_t indicesSize, std::string& path)
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &elementBuffer);

    glBindVertexArray(vao);


    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexBufferSize, vertex_buffer_data, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    this->vertexBufferSize = vertexBufferSize;
    indexBufferElementCount = indicesSize / sizeof(unsigned int);

    #pragma region TextureGeneration
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //stbi_set_flip_vertically_on_load(true);

    // load image, create texture and generate mipmaps
    int nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *data = stbi_load(("/Users/erhanguven/CLionProjects/Empyria/Empyria/Textures/"+path).c_str(), &rawWidth, &rawHeight, &nrChannels, 0);
    if (data)
    {
        if(nrChannels == 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, rawWidth, rawHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        else if(nrChannels == 4)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, rawWidth, rawHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Data couldn't be loaded");
    }
    stbi_image_free(data);
    #pragma endregion

    glBindVertexArray(0);
}
} // Engine