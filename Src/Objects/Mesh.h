#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

#include "Object.h"

class Triangle;

class Mesh : public Object {
private:
    std::vector<Vector3f> vertices;
    std::vector<Triangle*> triangles;

    Mesh(const std::vector<Vector3f> vertices, const std::vector<int> indices, const Vector3f& pos, const float scaleFactor, const Vector3f& diff, const Vector3f& spec, const Vector3f& amb, float shininessCoe);

public:
    static std::vector<Mesh*> loadOBJ(const char* path, const Vector3f& pos, const float scaleFactor, const Vector3f& diff, const Vector3f& spec, const Vector3f& amb, float shininessCoe);

    Intersection intersects(const Ray& ray) const override;
};

#endif // MESH_H_INCLUDED
