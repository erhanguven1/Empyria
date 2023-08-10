//
// Created by erhan güven on 23.07.2023.
//

#ifndef EMPYRIA_BLOCK_H
#define EMPYRIA_BLOCK_H

#include "Engine/GameObject/ModelObject.h"
#include "Engine/Scene/SceneManager.h"

using namespace Engine;

namespace Empyria
{

enum BlockType
{
    Dirt,
    Rock
};

enum PlaneDirection
{
    X,
    MINUS_X,
    Z,
    MINUS_Z
};

class BlockPlane
{
public:
    vec3 center;
    vec3 normal;
};

class Block : public ModelObject
{
public:
    Block(string path) : ModelObject(PrimitiveTypes::Cube, path)
    {

    }

    void calculatePlanes()
    {
        vec3 center = vec3(x,y,z);

        planes[X].center = center + vec3(0.5f,0,0);
        planes[X].normal = vec3(1,0,0);

        planes[MINUS_X].center = center + vec3(-0.5f,0,0);
        planes[MINUS_X].normal = vec3(-1,0,0);

        planes[Z].center = center + vec3(0.0f,0,0.5f);
        planes[Z].normal = vec3(0,0,1);

        planes[MINUS_Z].center = center + vec3(0.0f,0,-0.5f);
        planes[MINUS_Z].normal = vec3(0,0,-1);
    }

    vec3 getHitFaceDirection(vec3 rayDirection, vec3 rayOrigin)
    {
        float min = 100000.0f;
        BlockPlane nearestPlane;

        for(auto planesPair : planes)
        {
            auto plane = planesPair.second;

            auto planeCenter = plane.center;
            auto planeNormal = plane.normal;

            float denom = dot(planeNormal, rayDirection);
            if (abs(denom) > 0.0001f) // your favorite epsilon
            {
                vec3 dPlaneRay = (planeCenter - rayOrigin);
                float t = dot(dPlaneRay,planeNormal) / denom;
                if (t >= 0)
                {
                    if(t < min)
                    {
                        min = t;
                        nearestPlane = plane;
                    }
                }
            }
        }

        return nearestPlane.normal;
    }

    vec3 f2(vec3 rayDirection, vec3 rayOrigin)
    {
        float min = 100000.0f;
        BlockPlane nearestPlane;

        for(auto planesPair : planes)
        {
            auto plane = planesPair.second;

            auto planeCenter = plane.center;
            auto planeNormal = plane.normal;

            vec3 difference = planeCenter -vec3(0.5f,0,0.5f) - rayOrigin;
            double product_1 = dot(difference,planeNormal);
            double product_2 = dot(rayDirection,planeNormal);
            float distance_from_origin_to_plane = product_1 / product_2;
            vec3 intersection = rayOrigin + rayDirection * distance_from_origin_to_plane;

            if(distance_from_origin_to_plane >= 0)
            {
                if(distance_from_origin_to_plane < min)
                {
                    min = distance_from_origin_to_plane;
                    nearestPlane = plane;
                }
            }
        }

        return nearestPlane.normal;
    }

    int x;
    int y;
    int z;

private:
    unordered_map<PlaneDirection, BlockPlane> planes;
};

} // Empyria

#endif //EMPYRIA_BLOCK_H
