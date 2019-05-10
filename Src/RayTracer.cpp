#include <cmath>

#include "RayTracer.h"
#include "Objects/Intersection.h"
#include "Objects/Object.h"
#include "Objects/Sphere.h"
#include "CImg.h"

#include <iostream>

float RayTracer::getAspectRatio() {
    return imageWidth / (float)imageHeight;
}

Ray RayTracer::getPrimaryRay(int x, int y) {
   Vector3f direction = Vector3f(x, y, 5).normalize();
   Vector3f origin = Vector3f(x, y, 0);

   return Ray(origin, direction);
}

void RayTracer::rayTrace() {
    cam = Camera(Vector3f(8, 8, 8), Vector3f(0, 0, 0));

    fieldOfViewDeg = 90;
    imageWidth = 720;
    imageHeight = 480;
    backgroundColor = Vector3f(0,0,0); // Black.
    objects.push_back(new Sphere(Vector3f(imageWidth / 2, imageHeight / 2, 5), 16, Vector3f(0,255,0)));

    Vector3f finalImage[imageWidth * imageHeight];

    for (int y = 1; y <= imageHeight; y++) {
        for (int x = 1; x <= imageWidth; x++) {
            Ray primaryRay = getPrimaryRay(x, y);
            Vector3f finalColor = computeRay(primaryRay);
            finalImage[(x - 1) + (y - 1)] = finalColor;
        }
    }

    // Generate output image.
    cimg_library::CImg<float> img(imageWidth, imageHeight, 1, 3);
    cimg_forXY(img,x,y) {
        float color[3];
        color[0] = finalImage[x + y].x; // R
        color[1] = finalImage[x + y].y; // G
        color[2] = finalImage[x + y].z; // B

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
       Sphere* sp = (Sphere*)objects[0];
//       if (std::abs(sp->center.x - closestIntersect.contact.x) > 4
//           || std::abs(sp->center.y - closestIntersect.contact.y) > 4
//           || std::abs(sp->center.z - closestIntersect.contact.z) > 4) {
//          std::cout << "yikes";
//       }
        return closestIntersect.obj->color;
    }

    return backgroundColor;
}
