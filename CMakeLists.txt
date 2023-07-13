cmake_minimum_required(VERSION 3.25)
project(Empyria)

set(CMAKE_CXX_STANDARD 17)

add_library(glad include/glad/src/glad.c)

include_directories(.)
include_directories(include)

add_executable(Empyria main.cpp Engine/Window.cpp Engine/Window.h Engine/InputHandler.cpp Engine/InputHandler.h Engine/Scene.cpp Engine/Scene.h Engine/SceneManager.cpp Engine/SceneManager.h Engine/GameObject.cpp Engine/GameObject.h Engine/Component.h Engine/MeshRenderer.cpp Engine/MeshRenderer.h Engine/Mesh.cpp Engine/Mesh.h Engine/loadShader.hpp Engine/Transform.cpp Engine/Transform.h Engine/RectTransform.cpp Engine/RectTransform.h Engine/UIObject.cpp Engine/UIObject.h Engine/UIRenderer.cpp Engine/UIRenderer.h Engine/Shaders/Shaders.h Empyria/Scenes/MainMenuScene.cpp Empyria/Scenes/MainMenuScene.h Engine/EngineStarter.hpp Engine/stb_image.h Engine/EmpyriaEngine.h Engine/CanvasScaler.cpp Engine/CanvasScaler.h Engine/ModelObject.cpp Engine/ModelObject.h Engine/PrimitiveType.h Engine/Camera.cpp)
include_directories(include/glad/include)

find_package(OpenGL REQUIRED)

find_package(glfw3 3.3 REQUIRED)

find_package(glm REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

target_link_libraries(Empyria ${OPENGL_LIBRARIES} glad glfw)