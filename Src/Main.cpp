#include "RayTracer.h"
#include "Objects/Sphere.h"
#include "Objects/Triangle.h"
#include "Objects/Plane.h"

int main(int argc, char** argv) {
    Vector3f camPos = Vector3f(0, 0, 30);

    // Point to the origin.
    Vector3f lookAt = Vector3f(0, 0, 0);

    // Unit vector that defines what "up" is since there's no way the camera can derive this.
    Vector3f viewUp = Vector3f(0, 1, 0);

    float fovInDegrees = 170.0f;

    Camera cam = Camera(camPos, lookAt, viewUp, fovInDegrees);

    int imageWidth = 780;
    int imageHeight = 720;

    RayTracer rt = RayTracer(cam, imageWidth, imageHeight, imageWidth, imageHeight);

    rt.backgroundColor = Vector3f(0.2f, 0.2f, 0.2f);
    rt.lightPosition = Vector3f(10, 20, 0);

    rt.objects.push_back(new Sphere(Vector3f(0, 10, 0), 5, Vector3f(1.0f, 0, 0)));
    rt.objects.push_back(new Triangle(Vector3f(30, 0, 0),
                                   Vector3f(20, 0, 0),
                                   Vector3f(50, 40, -20),
                                   Vector3f(0, 1.0f, 0.04f)));
    rt.objects.push_back(new Plane(Vector3f(-10, 0, 0), Vector3f(10, 0, 0), Vector3f(0, 10, -20), Vector3f(1.0f, 1.0f, 1.0f)));

    rt.rayTrace("output.bmp");
}
