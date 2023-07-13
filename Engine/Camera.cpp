//
// Created by erhan güven on 14.06.2023.
//

#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <iostream>
#include "Camera.h"
#include "glm/gtx/rotate_vector.hpp"

Camera::Camera()
{

}

glm::mat4 Camera::getViewMatrix()
{
    std::cout << rotation.z << ":";

    lookDirection.x = cos(glm::radians(rotation.x)) * cos(glm::radians(rotation.y));
    lookDirection.y = sin(glm::radians(rotation.z));
    lookDirection.z = cos(glm::radians(rotation.z)) * sin(glm::radians(rotation.y));
    cameraFront = glm::normalize(lookDirection);
    return glm::lookAt(position, position+cameraFront,upAxis);
}

glm::mat4 Camera::getProjectionMatrix()
{
    return glm::perspective(glm::radians(fieldOfView), aspectRatio, nearClip, farClip);
}
