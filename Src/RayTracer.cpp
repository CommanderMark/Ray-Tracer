#include <cmath>

#include "RayTracer.h"
#include "Objects/Intersection.h"
#include "Objects/Object.h"
#include "Objects/Light.h"
#include "CImg.h"

#include <iostream>

RayTracer::RayTracer(const Camera& camera, int imageWidth, int imageHeight, int planeWidth, int planeHeight) : cam(camera), imageWidth(imageWidth), imageHeight(imageHeight) {
    // From: http://web.cse.ohio-state.edu/~shen.94/681/Site/Slides_files/basic_algo.pdf

    // Specify the size of each pixel, because that should be independent from vector space.
    pixelWidth = planeWidth / imageWidth;
    pixelHeight = planeHeight / imageHeight;

    // Get the distance from the eye to the camera plane.
    float focalLength = planeHeight / (std::tanf(cam.getFOV() / 2) / 2);
    centerOfPlane = cam.getPosition().subtract(cam.getForward().multiply(focalLength));
    bottomLeftOfPlane = centerOfPlane.subtract(cam.getRight().multiply(planeWidth / 2.0f)).subtract(cam.getUp().multiply(planeHeight / 2.0f));
}

RayTracer::~RayTracer() {
    for (int i = 0; i < (int)objects.size(); i++) {
        delete objects[i];
    }
    for (int i = 0; i < (int)lights.size(); i++) {
        delete lights[i];
    }
}

float RayTracer::getAspectRatio() const {
    return imageWidth / (float)imageHeight;
}

Ray RayTracer::getPrimaryRay(int x, int y) const {
    Vector3f location = bottomLeftOfPlane.add(cam.getRight().multiply(x).multiply(pixelWidth)).add(cam.getUp().multiply(y).multiply(pixelHeight));

    Vector3f pos = cam.getPosition();
    Vector3f dir = location.subtract(cam.getPosition()).normalize();

    return Ray(pos, dir);
}

void RayTracer::rayTrace(const char outputFile[]) const {
    // Generate output image.
    cimg_library::CImg<float> img(imageWidth, imageHeight, 1, 3);
    cimg_forXY(img,x,y) {
        Ray primaryRay = getPrimaryRay(x, y);
        Vector3f finalColor = computeRay(primaryRay);

        float color[3];
        color[0] = finalColor.x * 255.0f; // R
        color[1] = finalColor.y * 255.0f; // G
        color[2] = finalColor.z * 255.0f; // B

        img.draw_point(x, y, color);
    }

    img.save(outputFile);
}

Vector3f RayTracer::computeRay(const Ray& ray) const {
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

    // TODO: Phong shading.
    if (closestIntersect.didHit()) {
        // Check if the light source has line of sight towards the object.
        // Move the contact point one unit towards the camera to avoid colliding with the initial object.
        Vector3f position = closestIntersect.contact.subtract(ray.direction);
        Vector3f direction = lights[0]->getPosition().subtract(position).normalize();

        Ray shadowRay = Ray(position, direction);
        bool isInShadow = false;

        for (int i = 0; i < (int)objects.size(); i++) {
            Intersection intersect = objects[i]->intersects(shadowRay);

            if (intersect.didHit()) {
                isInShadow = true;
                break;
            }
        }

        if (isInShadow) {
            return Vector3f::zero;
        }

        return closestIntersect.obj->getDiffuseColor();
    }

    return backgroundColor;
}
