/* Copyright (c) 2019 Juan Pablo Arce

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

This notice may not be removed or altered from any source distribution. */

#include <cmath>

#include "Vector.h"

const Vector3f Vector3f::zero = Vector3f(0.f,0.f,0.f);
const Vector3f Vector3f::one = Vector3f(1.f,1.f,1.f);

Vector3f::Vector3f() {
    x=0.f; y=0.f; z=0.f;
}

Vector3f::Vector3f(float s) {
    x = s; y = s; z = s;
}

Vector3f::Vector3f(float ix,float iy,float iz) {
    x=ix; y=iy; z=iz;
}

float Vector3f::lengthSquared() const {
    return x*x+y*y+z*z;
}

float Vector3f::length() const {
    return (float)sqrt(x*x+y*y+z*z);
}

float Vector3f::distanceSquared(const Vector3f& b) const {
    return subtract(b).lengthSquared();
}

float Vector3f::distance(const Vector3f& b) const {
    return subtract(b).length();
}

Vector3f Vector3f::add(const Vector3f& b) const {
    return Vector3f(x+b.x,y+b.y,z+b.z);
}

Vector3f Vector3f::subtract(const Vector3f& b) const {
    return Vector3f(x-b.x,y-b.y,z-b.z);
}

Vector3f Vector3f::multiply(float s) const {
    return Vector3f(x*s,y*s,z*s);
}

Vector3f Vector3f::normalize() const {
    float length = this->length();
    if (length == 0) {
        return 0;
    }
    return multiply(1.f/this->length());
}

Vector3f Vector3f::reflect(const Vector3f& n) const {
    Vector3f reflectedVector = normalize();
    reflectedVector = n.multiply(2.f*reflectedVector.dotProduct(n)).subtract(reflectedVector);
    return reflectedVector.normalize();
}

Vector3f Vector3f::invert() const {
    return Vector3f(-x, -y, -z);
}

float Vector3f::dotProduct(const Vector3f& b) const {
    return x*b.x+y*b.y+z*b.z;
}

Vector3f Vector3f::crossProduct(const Vector3f& b) const {
    return Vector3f(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
}
