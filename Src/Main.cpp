#include "RayTracer.h"
#include "Objects/Sphere.h"
#include "Objects/Triangle.h"
#include "Objects/Plane.h"
#include "Objects/Mesh.h"
#include "Objects/Light.h"

int main(int argc, char** argv) {
    Vector3f camPos = Vector3f(0, 70, 250);

    // Point to the origin.
    Vector3f lookAt = Vector3f(0, 0, 0);

    // Unit vector that defines what "up" is since there's no way the camera can derive this.
    Vector3f viewUp = Vector3f(0, 1, 0);

    float fovInDegrees = 90.0f;

    Camera cam = Camera(camPos, lookAt, viewUp, fovInDegrees);

    int imageWidth = 1280;
    int imageHeight = 720;

    RayTracer rt = RayTracer(cam, imageWidth, imageHeight, imageWidth, imageHeight);

    rt.backgroundColor = Vector3f(0.2f, 0.2f, 0.2f);
    rt.lights.push_back(new Light(Vector3f(-30, 55, 50), Vector3f(1.0, 1.0, 1.0), Vector3f::one));
//    rt.lights.push_back(new Light(Vector3f(-30, 55, 25), Vector3f(0, 1.0, 0), Vector3f::one));
//    rt.lights.push_back(new Light(Vector3f(-30, 55, 40), Vector3f(0, 0, 1.0), Vector3f::one));

    rt.objects.push_back(new Sphere(Vector3f(0, 25, 20), 10,
                                    Vector3f(1.0f, 0, 0),
                                    Vector3f::one,
                                    Vector3f::zero,
                                    20.0f));

//    rt.objects.push_back(new Triangle(Vector3f(0, 10, 0),
//                                   Vector3f(50, 10, 10),
//                                   Vector3f(50, 60, 10),
//                                   Vector3f(0, 1.0f, 0.04f),
//                                   Vector3f(0.2f, 0.5f, 0.5f),
//                                   Vector3f(0.1f, 0.5f, 0.5f),
//                                   1.0f));
    rt.objects.push_back(new Plane(Vector3f(10, 0, 0), Vector3f(-10, 0, 0), Vector3f(0, -10, 20), Vector3f::one, Vector3f::one, Vector3f(0.2, 0.2, 0.2), 1.0f));

//    std::vector<Mesh*> model = Mesh::loadOBJ("box_stack.obj", Vector3f::zero, 20.0f, Vector3f(1.0f, 0, 0), Vector3f::one, Vector3f::zero, 5.0f);
//   for (int i = 0; i < (int)model.size(); i++) {
//       rt.objects.push_back(model[i]);
//   }

    rt.rayTrace("output.bmp");
}
