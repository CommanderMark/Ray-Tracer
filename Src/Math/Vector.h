/* Copyright (c) 2019 Juan Pablo Arce

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

This notice may not be removed or altered from any source distribution. */

#ifndef PGE_VECTOR_H_INCLUDED
#define PGE_VECTOR_H_INCLUDED

class Vector2f; class Vector3f; class Vector2i;

class Vector2f {
public:
    float x; float y;

    Vector2f();
    Vector2f(float s);
    Vector2f(float ix,float iy);
    Vector2f(const Vector2i& vi);

    float lengthSquared() const;
    float length() const;

    float distanceSquared(const Vector2f& b) const;
    float distance(const Vector2f& b) const;

    bool equals(const Vector2f& b,float epsilon=0.002f) const;

    Vector2f add(const Vector2f& b) const;
    Vector2f subtract(const Vector2f& b) const;

    Vector2f multiply(float s) const;
    Vector2f normalize() const;

    Vector2f reflect(const Vector2f& n) const;
    float dotProduct(const Vector2f& b) const;

    static const Vector2f zero;
    static const Vector2f one;
};

class Vector3f {
public:
    float x; float y; float z;

    Vector3f();
    Vector3f(float s);
    Vector3f(float ix,float iy,float iz);

    float lengthSquared() const;
    float length() const;

    float distanceSquared(const Vector3f& b) const;
    float distance(const Vector3f& b) const;

    Vector3f add(const Vector3f& b) const;
    Vector3f subtract(const Vector3f& b) const;

    Vector3f multiply(float s) const;
    Vector3f normalize() const;

    Vector3f reflect(const Vector3f& n) const;
    float dotProduct(const Vector3f& b) const;
    Vector3f crossProduct(const Vector3f& b) const;

    static const Vector3f zero;
    static const Vector3f one;
};

class Vector4f {
public:
    float x; float y; float z; float w;

    Vector4f();
    Vector4f(float s);
    Vector4f(float ix,float iy,float iz,float iw);

    static const Vector4f zero;
    static const Vector4f one;
};

class Vector2i {
public:
    int x; int y;

    Vector2i();
    Vector2i(int s);
    Vector2i(int ix,int iy);
    Vector2i(const Vector2f& vf);

    int lengthSquared() const;
    float length() const;

    int distanceSquared(const Vector2i& b) const;
    float distance(const Vector2i& b) const;

    Vector2i add(const Vector2i& b) const;
    Vector2i subtract(const Vector2i& b) const;

    Vector2i multiply(int s) const;

    static const Vector2i zero;
    static const Vector2i one;
};

#endif
