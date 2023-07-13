//
// Created by erhan güven on 14.06.2023.
//

#ifndef OPENGL_TEST_CAMERA_H
#define OPENGL_TEST_CAMERA_H

#include <glm/glm.hpp>

class Camera
{
public:
    Camera();
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();

    inline void addPosition(glm::vec3 posToAdd)
    {
        position += posToAdd;
    }

    inline void setFov(float fov)
    {
        fieldOfView = fov;
    }

    inline static Camera& getInstance()
    {
        if(instance == nullptr)
            instance = new Camera;
        return *instance;
    }

    glm::vec3 position = glm::vec3(0,0.0f,0.0f);
    glm::vec3 rotation = glm::vec3(0,0.0f,0.0f);
    glm::vec3 lookDirection = glm::vec3(0,0,1);
    glm::vec3 cameraFront = glm::vec3(0,0,1);
    glm::vec3 right = glm::vec3(1,0,0);
    glm::vec3 up = glm::vec3(0,1,0);
    glm::vec3 upAxis = glm::vec3(0,1,0);

    float fieldOfView = 60.0f;
    float aspectRatio = 800.0f/600.0f;

    float nearClip = 0.1f;
    float farClip = 100.0f;
private:
    inline static Camera* instance;
};


#endif //OPENGL_TEST_CAMERA_H
