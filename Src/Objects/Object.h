#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "Ray.h"

class Object {
private:
    Object();

public:
    virtual bool intersects(const Ray& ray)=0;
};

#endif // OBJECT_H_INCLUDED