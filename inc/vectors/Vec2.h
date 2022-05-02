#ifndef INC_3DGRAPHICS_VEC2_H
# define INC_3DGRAPHICS_VEC2_H

# include <vector>

template <typename T>
class Vec2 {
public:
    T x, y;

public:
    Vec2() : x(0), y(0) {};
    Vec2(T x, T y) : x(x), y(y) {};
    Vec2(const Vec2& v) : x(v.x), y(v.y) {};
};

#endif //INC_3DGRAPHICS_VEC2_H
