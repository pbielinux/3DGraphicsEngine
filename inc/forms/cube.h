//
// Created by pbielinux on 01/06/22.
//

#ifndef INC_3DGRAPHICS_CUBE_H
# define INC_3DGRAPHICS_CUBE_H

# include <memory>
# include <vector>
# include "vectors/vectors.h"

class Cube {
public:
    void add(const Vec3<float>& point) {
        points.push_back(point);
    }
    std::vector<Vec3<float>> get() { return points; };

private:
    std::vector<Vec3<float>> points;
    int color;
};

#endif //INC_3DGRAPHICS_CUBE_H
