cmake_minimum_required(VERSION 3.25)
project(Empyria)

set(CMAKE_CXX_STANDARD 17)

add_library(glad include/glad/src/glad.c)

include_directories(.)
include_directories(include)

add_executable(Empyria main.cpp Engine/Window.cpp Engine/Window.h Engine/Input/InputHandler.cpp Engine/Input/InputHandler.h Engine/Scene/Scene.cpp Engine/Scene/Scene.h Engine/Scene/SceneManager.cpp Engine/Scene/SceneManager.h Engine/GameObject.cpp Engine/GameObject.h Engine/Component.h Engine/Mesh/MeshRenderer.cpp Engine/Mesh/MeshRenderer.h Engine/Mesh/Mesh.cpp Engine/Mesh/Mesh.h Engine/loadShader.hpp Engine/Transform.cpp Engine/Transform.h Engine/UI/RectTransform.cpp Engine/UI/RectTransform.h Engine/UI/UIObject.cpp Engine/UI/UIObject.h Engine/UI/UIRenderer.cpp Engine/UI/UIRenderer.h Engine/Shaders/Shaders.h Empyria/Scenes/MainMenuScene.cpp Empyria/Scenes/MainMenuScene.h Engine/EngineStarter.hpp Engine/stb_image.h Engine/EmpyriaEngine.h Engine/CanvasScaler.cpp Engine/CanvasScaler.h Engine/ModelObject.cpp Engine/ModelObject.h Engine/PrimitiveType.h Engine/Camera.cpp Empyria/Scenes/GameScene.cpp Empyria/Scenes/GameScene.h)
include_directories(include/glad/include)

find_package(OpenGL REQUIRED)

find_package(glfw3 3.3 REQUIRED)

find_package(glm REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

target_link_libraries(Empyria ${OPENGL_LIBRARIES} glad glfw)