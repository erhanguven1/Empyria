//
// Created by erhan güven on 19.06.2023.
//

#include "MeshRenderer.h"
#include <string>
#include "Engine/Shaders/Shaders.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Engine/Camera.h"

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
    mesh->initMesh(vertex_buffer_data, sizeof(vertex_buffer_data), sizeof(vertex_buffer_data) / (8 * sizeof(GLfloat)), texturePath);

    model = glm::mat4(1.0f);
}

void MeshRenderer::start()
{

}

void MeshRenderer::update(float dt)
{
}

void MeshRenderer::render(Transform& transform)
{
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    GLuint programID = Shaders::standardShaderProgram;
    glUseProgram(programID);

    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), transform.position);
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), transform.rotation);
    glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f),transform.scale);

    model = translationMatrix * rotationMatrix * scaleMatrix;
    auto projection = Camera::getInstance().getProjectionMatrix();
    auto view = Camera::getInstance().getViewMatrix();

    glm::vec3 objColor = glm::vec3(1,0.5f,0.31f);
    GLuint objColorID = glGetUniformLocation(programID, "objectColor");
    glUniform3fv(objColorID, 1, &objColor[0]);

    GLuint lightColorID = glGetUniformLocation(programID, "lightColor");
    glm::vec3 lightColor = glm::vec3(1,1, 1);
    glUniform3fv(lightColorID, 1, &lightColor[0]);

    GLuint lightPosID = glGetUniformLocation(programID, "light.position");
    glm::vec3 lightPos = glm::vec3(3,3,3);
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


    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mesh->texture);

    glBindVertexArray(mesh->vao);
    glDrawArrays(GL_TRIANGLES, 0, 287/3); // Starting from vertex 0; 3 vertices total -> 1 triangle
}

} // Engine