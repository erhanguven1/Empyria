//
// Created by erhan güven on 19.06.2023.
//

#include "MeshRenderer.h"
#include <string>
#include "Engine/Shaders/Shaders.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Engine/Camera.h"
#include "../tiny_obj_loader.h"

using namespace std;

namespace Engine
{

void MeshRenderer::init(const PrimitiveTypes& primitiveType, std::string texturePath)
{
    float vertex_buffer_data[] =
    {
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
            0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
            0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
            0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
            0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };
    mesh = new Mesh();
    if(texturePath == "")
        texturePath = "default_texture.png";

    unsigned int indices[36];

    for(int i = 0; i < 6*6; i+=6)
    {
        indices[i] = i+0;
        indices[i+1] = i+1;
        indices[i+2] = i+2;

        indices[i+3] = i+3;
        indices[i+4] = i+4;
        indices[i+5] = i+5;
    }

    mesh->initMesh(vertex_buffer_data, indices, sizeof(vertex_buffer_data), sizeof(indices), texturePath);

    model = glm::mat4(1.0f);
}

void MeshRenderer::init(const std::string modelFilePath, std::string texturePath)
{
    float vertex_buffer_data[] =
            {
                    0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
                    0.5f, 0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
                    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
                    -0.5f,  -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f
            };

    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err,("/Users/erhanguven/CLionProjects/Empyria/Empyria/Models/"+modelFilePath).c_str())) {
        throw std::runtime_error(warn + err);
    }

    mesh = new Mesh();
    if(texturePath == "")
        texturePath = "default_texture.png";

    int vertexBufferSize = 8*(attrib.vertices.size()/3);

    float vertices[vertexBufferSize];
    unsigned int indices[shapes[0].mesh.indices.size()];

    for(int i = 0; i < vertexBufferSize; i+=8)
    {
        // Vertex positions
        vertices[i] = attrib.vertices[3*i/8]; // 0 , 3 , 6
        vertices[i+1] = attrib.vertices[3*i/8+1]; // 1 , 4 , 7
        vertices[i+2] = attrib.vertices[3*i/8+2]; // 2 , 5 , 8

        // Default vertex colors
        vertices[i+3] = 0.0f;
        vertices[i+4] = 0.0f;
        vertices[i+5] = 1.0f;

        // Default texture coordinates
        //vertices[i+6] = attrib.texcoords[2*i/8]; // 0 , 2
        //vertices[i+7] = attrib.texcoords[2*i/8+1]; // 1 , 3
    }

    for(int i = 0; i < shapes[0].mesh.indices.size(); i+=1)
    {
        indices[i] = shapes[0].mesh.indices[i].vertex_index;
    }

    mesh->initMesh(vertices, indices, sizeof(vertices), sizeof(indices), texturePath);

    model = glm::mat4(1.0f);
}

void MeshRenderer::init(Mesh &mesh)
{
    this->mesh = &mesh;
    model = glm::mat4(1.0f);
}

void MeshRenderer::start()
{

}

void MeshRenderer::update(float dt)
{
}
int i = 0;
void MeshRenderer::render(Transform& transform)
{
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    GLuint programID = Shaders::standardShaderProgram;
    glUseProgram(programID);

    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), transform.position);
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(transform.angle), transform.rotation);
    glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f),transform.scale);

    model = translationMatrix * rotationMatrix * scaleMatrix;
    auto projection = Camera::getInstance().getProjectionMatrix();
    auto view = Camera::getInstance().getViewMatrix();

    i++;

    #pragma region ShaderBinding

    glm::vec3 objColor = glm::vec3(1,0.5f,0.31f);
    GLuint objColorID = glGetUniformLocation(programID, "objectColor");
    glUniform3fv(objColorID, 1, &objColor[0]);

    GLuint lightColorID = glGetUniformLocation(programID, "lightColor");
    glm::vec3 lightColor = glm::vec3(1,0, 0);
    glUniform3fv(lightColorID, 1, &lightColor[0]);

    GLuint lightPosID = glGetUniformLocation(programID, "light.position");
    glm::vec3 lightPos = glm::vec3(0,0,30);
    glUniform3fv(lightPosID, 1, &lightPos[0]);

    GLuint viewPosID = glGetUniformLocation(programID, "viewPos");
    glm::vec3 viewPos = glm::vec3(0,1, 0);
    glUniform3fv(viewPosID, 1, &viewPos[0]);

    GLuint modelID = glGetUniformLocation(programID, "model");
    glUniformMatrix4fv(modelID, 1, GL_FALSE, &model[0][0]);

    GLuint viewID = glGetUniformLocation(programID, "view");
    glUniformMatrix4fv(viewID, 1, GL_FALSE, &(view[0][0]));

    GLuint projectionID = glGetUniformLocation(programID, "projection");
    glUniformMatrix4fv(projectionID, 1, GL_FALSE, &(projection[0][0]));

    GLuint diffuseID = glGetUniformLocation(programID, "material.diffuse");
    glUniform1i(diffuseID, 0);

    GLuint specularID = glGetUniformLocation(programID, "material.specular");
    glm::vec3 specularValue = glm::vec3(0.5f, 0.5f, 0.5f);
    glUniform3fv(specularID, 1, &specularValue[0]);

    GLuint shininessID = glGetUniformLocation(programID, "material.shininess");
    float shininessValue = 4;
    glUniform1f(shininessID, shininessValue);

    GLuint lightDiffuseID = glGetUniformLocation(programID, "light.diffuse");
    glm::vec3 lightDiffuseValue = glm::vec3(0.5f, 0.5f, 0.5f);
    glUniform3fv(lightDiffuseID, 1, &lightDiffuseValue[0]);

    GLuint lightSpecularID = glGetUniformLocation(programID, "light.specular");
    glm::vec3 lightSpecularValue = glm::vec3(1,1,1);
    glUniform3fv(lightSpecularID, 1, &lightSpecularValue[0]);

    GLuint lightAmbientID = glGetUniformLocation(programID, "light.ambient");
    glm::vec3 lightAmbientValue = glm::vec3(0.5f, 0.5f, 0.5f);
    glUniform3fv(lightAmbientID, 1, &lightAmbientValue[0]);

    #pragma endregion

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mesh->texture);

    glBindVertexArray(mesh->vao);
    glDrawElements(GL_TRIANGLES, mesh->indexBufferElementCount, GL_UNSIGNED_INT, (void*)0);
    //glDrawArrays(GL_TRIANGLES, 0, mesh->vertexBufferSize); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glBindVertexArray(0);
    glActiveTexture(GL_TEXTURE0);
}

} // Engine