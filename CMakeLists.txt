cmake_minimum_required(VERSION 3.25)
project(Empyria)

set(CMAKE_CXX_STANDARD 14)

add_library(glad include/glad/src/glad.c)

include_directories(.)
include_directories(include)

add_executable(Empyria main.cpp Engine/Window.cpp Engine/Window.h Engine/InputHandler.cpp Engine/InputHandler.h Engine/Scene.cpp Engine/Scene.h Engine/SceneManager.cpp Engine/SceneManager.h Engine/GameObject.cpp Engine/GameObject.h Engine/Component.h Engine/MeshRenderer.cpp Engine/MeshRenderer.h Engine/Mesh.cpp Engine/Mesh.h Engine/UIElement.cpp Engine/UIElement.h)
include_directories(include/glad/include)

find_package(OpenGL REQUIRED)

find_package(glfw3 3.3 REQUIRED)

find_package(glm REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

target_link_libraries(Empyria ${OPENGL_LIBRARIES} glad glfw)