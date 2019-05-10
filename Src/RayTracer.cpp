#include <cmath>

#include "RayTracer.h"
#include "Objects/Intersection.h"
#include "Objects/Object.h"
#include "Objects/Sphere.h"
#include "Objects/Triangle.h"
#include "CImg.h"

#include <iostream>

float RayTracer::getAspectRatio() {
    return imageWidth / (float)imageHeight;
}

Ray RayTracer::getPrimaryRay(int x, int y) {
    // From: http://web.cse.ohio-state.edu/~shen.94/681/Site/Slides_files/basic_algo.pdf

    // Specify the size of each pixel, because that should be independant from vector space.
    int planeWidth = imageWidth;
    int planeHeight = imageHeight;
    int pixelWidth = planeWidth / imageWidth;
    int pixelHeight = planeHeight / imageHeight;

    // Get the distance from the eye to the camera plane.
    float distance = planeHeight / (std::tanf(cam.getFOV() / 2) / 2);

    Vector3f centerOfPlane = cam.getPosition().subtract(cam.getForward().multiply(distance));
    Vector3f bottomLeft = centerOfPlane.subtract(cam.getRight().multiply(planeWidth / 2.0f)).subtract(cam.getUp().multiply(planeHeight / 2.0f));

    Vector3f location = bottomLeft.add(cam.getRight().multiply(x).multiply(pixelWidth)).add(cam.getUp().multiply(y).multiply(pixelHeight));

    Vector3f pos = cam.getPosition();
    Vector3f dir = location.subtract(cam.getPosition()).normalize();

    return Ray(pos, dir);
}

void RayTracer::rayTrace() {
    Vector3f camPos = Vector3f(0, 0, 50);

    // Point to the origin.
    Vector3f lookAt = Vector3f(0, 0, 0);

    // Unit vector that defines what "up" is since there's no way the camera can derive this.
    Vector3f viewUp = Vector3f(0, 1, 0);

    cam = Camera(camPos, lookAt, viewUp, 170.0f);

    imageWidth = 780;
    imageHeight = 720;
    backgroundColor = Vector3f(0,0,0); // Black.
    objects.push_back(new Sphere(Vector3f(0, 0, 0), 15, Vector3f(255,0,0)));
    objects.push_back(new Triangle(
        Vector3f(0, 0, 0),
        Vector3f(0, 125, 0),
        Vector3f(125, 0, 0),
        Vector3f(0, 125, 0)
    )
                      );

    Vector3f finalImage[imageHeight][imageWidth];

    for (int y = 0; y < imageHeight; y++) {
        for (int x = 0; x < imageWidth; x++) {
            Ray primaryRay = getPrimaryRay(x, y);
            Vector3f finalColor = computeRay(primaryRay);
            finalImage[y][x] = finalColor;
        }
    }

    // Generate output image.
    cimg_library::CImg<float> img(imageWidth, imageHeight, 1, 3);
    cimg_forXY(img,x,y) {
        float color[3];
        color[0] = finalImage[y][x].x; // R
        color[1] = finalImage[y][x].y; // G
        color[2] = finalImage[y][x].z; // B

        img.draw_point(x, y, color);
    }

    img.save("output.bmp");
}

Vector3f RayTracer::computeRay(const Ray& ray) {
    // TODO: Add a cache to speed this up when there's high spatial locality.
    float closestContactSquared = INFINITY;
    Intersection closestIntersect = Intersection();

    for (int i = 0; i < (int)objects.size(); i++) {
        Intersection intersect = objects[i]->intersects(ray);

        if (intersect.didHit()) {
            // Check that it's the closest intersection so far.
            float distanceSquared = intersect.contact.subtract(ray.origin).lengthSquared();
            if (distanceSquared < closestContactSquared) {
                closestContactSquared = distanceSquared;
                closestIntersect = intersect;
            }
        }
    }

    // TODO: Shadow rays god dammit.
    if (closestIntersect.didHit()) {
        return closestIntersect.obj->color;
    }

    return backgroundColor;
}
