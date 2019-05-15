#include <vector>
#include <iostream>

#include "Mesh.h"
#include "Triangle.h"
#include "../Math/Vector.h"
#include "../Utils/OBJ_Loader.h"

Mesh::Mesh(const Vector3f& diff, const Vector3f& spec, const Vector3f& amb, float shininessCoe) : Object(diff, spec, amb, shininessCoe) { }

std::vector<Mesh*> Mesh::loadOBJ(const char* path, const Vector3f& pos, const float scaleFactor, const Vector3f& diff, const Vector3f& spec, const Vector3f& amb, float shininessCoe) {
    std::vector<Mesh*> retVal;

    // Initialize Loader
    objl::Loader Loader;
    bool loaded = Loader.LoadFile(path);

    if (loaded) {
        for (int i = 0; i < (int)Loader.LoadedMeshes.size(); i++) {
            objl::Mesh currMesh = Loader.LoadedMeshes[i];
            retVal.push_back(new Mesh(spec, diff, amb, shininessCoe));

            for (int j = 0; j < (int)currMesh.Vertices.size(); j++) {
                retVal[i]->vertices.push_back(Vector3f(currMesh.Vertices[j].Position.X, currMesh.Vertices[j].Position.Y, currMesh.Vertices[j].Position.Z));
            }

            for (int j = 0; j < (int)currMesh.Indices.size(); j += 3) {
                Vector3f p1 = retVal[i]->vertices[currMesh.Indices[j]].multiply(scaleFactor).add(pos);
                Vector3f p2 = retVal[i]->vertices[currMesh.Indices[j + 1]].multiply(scaleFactor).add(pos);
                Vector3f p3 = retVal[i]->vertices[currMesh.Indices[j + 2]].multiply(scaleFactor).add(pos);

                retVal[i]->triangles.push_back(new Triangle(p1, p2, p3, diff, spec, amb, shininessCoe));
            }
        }
    } else {
        std::cerr << "Failed to Load File. May have failed to find it or it was not an .obj file.\n";
    }

    return retVal;
}

Intersection Mesh::intersects(const Ray &ray) const {
    Intersection closestIntersect = Intersection();
    float closestContactSquared = INFINITY;

    for (int i = 0; i < (int)triangles.size(); i++) {
        Intersection intersect = triangles[i]->intersects(ray);

        if (intersect.didHit()) {
            // Check that it's the closest intersection so far.
            float distanceSquared = intersect.contact.subtract(ray.origin).lengthSquared();
            if (distanceSquared < closestContactSquared) {
                closestContactSquared = distanceSquared;
                closestIntersect = intersect;
            }
        }
    }

    return closestIntersect;
}
