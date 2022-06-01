#ifndef INC_3DGRAPHICS_VEC3_H
# define INC_3DGRAPHICS_VEC3_H

# include "Vec2.h"

template <typename T>
class Vec3 {
public:
    T x, y, z;

public:
    Vec3() : x(0), y(0), z(0) {};
    Vec3(T x, T y, T z) : x(x), y(y), z(z) {};
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {};

    operator Vec2<T>(){
        return Vec2<T>(x, y);
    };
};

#endif //INC_3DGRAPHICS_VEC3_H
