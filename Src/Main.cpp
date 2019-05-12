#include "RayTracer.h"
#include "Objects/Sphere.h"
#include "Objects/Triangle.h"
#include "Objects/Plane.h"
#include "Objects/Light.h"

int main(int argc, char** argv) {
    Vector3f camPos = Vector3f(0, 10, 30);

    // Point to the origin.
    Vector3f lookAt = Vector3f(0, 0, 0);

    // Unit vector that defines what "up" is since there's no way the camera can derive this.
    Vector3f viewUp = Vector3f(0, 1, 0);

    float fovInDegrees = 170.0f;

    Camera cam = Camera(camPos, lookAt, viewUp, fovInDegrees);

    int imageWidth = 1280;
    int imageHeight = 720;

    RayTracer rt = RayTracer(cam, imageWidth, imageHeight, imageWidth, imageHeight);

    rt.backgroundColor = Vector3f(0.2f, 0.2f, 0.2f);
    rt.lights.push_back(new Light(Vector3f(10, 50, 25), Vector3f::one, Vector3f::zero));
    
    rt.objects.push_back(new Sphere(Vector3f(0, 15, 0), 15,
                                    Vector3f(1.0f, 0, 0),
                                    Vector3f::zero,
                                    Vector3f::zero,
                                    1.0f));

//    rt.objects.push_back(new Triangle(Vector3f(30, 0, 0),
//                                   Vector3f(20, 0, 0),
//                                   Vector3f(50, 40, -20),
//                                   Vector3f(0, 1.0f, 0.04f),
//                                   Vector3f(0.2f, 0.5f, 0.5f),
//                                   Vector3f(0.1f, 0.5f, 0.5f),
//                                   1.0f));
    rt.objects.push_back(new Plane(Vector3f(10, 0, 0), Vector3f(-10, 0, 0), Vector3f(0, -10, 20), Vector3f::one, Vector3f::one, Vector3f(0.2, 0.2, 0.2), 1.0f));

    rt.rayTrace("output.bmp");
}
