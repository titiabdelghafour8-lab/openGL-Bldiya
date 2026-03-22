#include <limits>
#include <cmath>
#include <vector>

/***********types**************/
typedef struct float3
{
    float x, y, z;
}float3;

typedef struct color
{
    unsigned char r, g, b;
}color;
typedef struct float2
{
    float x, y;
}float2, couple;

typedef struct sphere
{
    float3 center;
    float radius;
    color colour;
}sphere;
/*****************************/

/*****************************/


float dotProduct3D(const float3 u, const float3 v)
{
    return u.x * v.x + u.y * v.y + u.z * v.z;
}



couple intersectRaySphere(
    const float3 direction,
    const sphere& sceneSphere,
    const float3 origin
    )
{
    couple result { std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity() };
    float r = sceneSphere.radius;
    float3 CO {
        sceneSphere.center.x - origin.x,
        sceneSphere.center.y - origin.y,
        sceneSphere.center.z - origin.z
    };
    float a { dotProduct3D(direction, direction) };
    float b { 2 * dotProduct3D(CO, direction) };
    float c { dotProduct3D(CO, CO) - r * r };

    float discriminant { b * b - 4 * a * c };
    if (discriminant < 0)
    {
        return result;
    }

    result.x = (-b + std::sqrt(discriminant)) / (2 * a);
    result.y = (-b - std::sqrt(discriminant)) / (2 * a);

    return result;
}




float3 screenPixelToViewport(
    couple pixelPosition,
    float screenWidth,
    float screenHeight,
    float viewportWidth,
    float viewportHeight,
    float VPDistanceFromCamera
    )
{
    float3 viewportPosition{
        pixelPosition.x * viewportWidth / screenWidth,
        pixelPosition.y * viewportHeight / screenHeight,
        VPDistanceFromCamera
    };
    return viewportPosition;

}

color traceRay(
    const float3 direction,
    const float3 origin,
    float t_min,
    float t_max,
    const std::vector<sphere>& scene
    )
{
    color result { 0, 0, 0 };
    float closest_t { std::numeric_limits<float>::infinity() };
    for (const sphere& sSphere : scene)
    {
        couple intersection { intersectRaySphere(direction, sSphere, origin) };
        if ( intersection.x < closest_t && ( intersection.x <= t_max && intersection.x >= t_min) )
        {
            closest_t = intersection.x;
            result = sSphere.colour;
        }

        if ( intersection.y < closest_t && ( intersection.y <= t_max && intersection.y >= t_min) )
        {
            closest_t = intersection.y;
            result = sSphere.colour;
        }
    }
    return result;

}

/*****************************/
