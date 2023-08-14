cmake_minimum_required(VERSION 3.25)
project(Empyria)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS -dBUILD_SHARED_LIBS=OFF)

add_library(glad include/glad/src/glad.c)

set(ASSIMP_DIR /Users/erhanguven/assimp)
set(CMAKE_OSX_ARCHITECTURES "arm64")

include_directories(.)
include_directories(include)
include_directories(${ASSIMP_DIR}/include)

add_executable(Empyria main.cpp Engine/Window.cpp Engine/Window.h Engine/Input/InputHandler.cpp Engine/Input/InputHandler.h Engine/Scene/Scene.cpp Engine/Scene/Scene.h Engine/Scene/SceneManager.cpp Engine/Scene/SceneManager.h Engine/GameObject/GameObject.cpp Engine/GameObject/GameObject.h Engine/GameObject/Component.h Engine/Mesh/MeshRenderer.cpp Engine/Mesh/MeshRenderer.h Engine/Mesh/Mesh.cpp Engine/Mesh/Mesh.h Engine/loadShader.hpp Engine/GameObject/Transform.cpp Engine/GameObject/Transform.h Engine/UI/RectTransform.cpp Engine/UI/RectTransform.h Engine/UI/UIObject.cpp Engine/UI/UIObject.h Engine/UI/UIRenderer.cpp Engine/UI/UIRenderer.h Engine/Shaders/Shaders.h Empyria/Scenes/MainMenuScene.cpp Empyria/Scenes/MainMenuScene.h Engine/EngineStarter.hpp Engine/stb_image.h Engine/EmpyriaEngine.h Engine/GameObject/ModelObject.cpp Engine/GameObject/ModelObject.h Engine/GameObject/PrimitiveType.h Engine/Camera.cpp Empyria/Scenes/GameScene.cpp Empyria/Scenes/GameScene.h Engine/tiny_obj_loader.h Engine/tiny_obj_loader.cc Empyria/Scripts/Chunk.cpp Empyria/Scripts/Chunk.h Empyria/Scripts/Block.cpp Empyria/Scripts/Block.h Empyria/Scripts/VoxelRaycaster.cpp Empyria/Scripts/VoxelRaycaster.h Empyria/Scripts/ChunkManager.cpp Empyria/Scripts/ChunkManager.h Empyria/Scripts/Player.cpp Empyria/Scripts/Player.h Engine/Physics/Rigidbody.cpp Engine/Physics/Rigidbody.h Engine/Networking/UdpClient.cpp Engine/Networking/UdpClient.h Engine/Text/TextRenderer.cpp Engine/Text/TextRenderer.h Engine/Text/TextObject.cpp Engine/Text/TextObject.h Engine/UI/InputField.cpp Engine/UI/InputField.h Empyria/Scripts/ChatManager.cpp Empyria/Scripts/ChatManager.h)
include_directories(include/glad/include)

find_package(OpenGL REQUIRED)

find_package(glfw3 3.3 REQUIRED)

find_package(glm REQUIRED)

include_directories("/usr/local/include/freetype2/")
include_directories(${OPENGL_INCLUDE_DIR})

link_directories(${ASSIMP_DIR}/bin)

find_package(Freetype REQUIRED)
target_link_libraries(Empyria Freetype::Freetype)

target_link_libraries(Empyria ${OPENGL_LIBRARIES} glad glfw)
target_link_libraries(Empyria ${CMAKE_BINARY_DIR}/libassimp.5.2.5.dylib)