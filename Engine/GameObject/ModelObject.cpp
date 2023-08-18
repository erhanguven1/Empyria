//
// Created by erhan güven on 10.07.2023.
//

#include "ModelObject.h"

namespace Engine
{

ModelObject::ModelObject(const PrimitiveTypes &primitiveType)
{
    addComponent<Transform>();
    addComponent<MeshRenderer>();
    getComponent<MeshRenderer>()->init(primitiveType);
}

ModelObject::ModelObject(const PrimitiveTypes &primitiveType, string imagePath)
{
    addComponent<Transform>();
    addComponent<MeshRenderer>();
    getComponent<MeshRenderer>()->init(primitiveType, imagePath);
}

ModelObject::ModelObject(string modelPath, string imagePath)
{
    addComponent<Transform>();
    addComponent<MeshRenderer>();
    getComponent<MeshRenderer>()->init(modelPath, imagePath);
}

ModelObject::ModelObject(Mesh &fromMesh)
{
    addComponent<Transform>();
    addComponent<MeshRenderer>();
    getComponent<MeshRenderer>()->init(fromMesh);
}
} // Engine