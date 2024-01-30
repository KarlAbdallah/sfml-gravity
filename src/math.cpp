#include "../include/math.hpp"


double Math::norm(Vec2 vec) {
    return sqrt(vec.x*vec.x + vec.y*vec.y);
}

double Math::norm2(Vec2 vec) {
    return (vec.x*vec.x + vec.y*vec.y);
}

Vec2 Math::normalize(Vec2 vec) {
    return vec / norm(vec);
}

double Math::dot(Vec2 a, Vec2 b) {
    return a.x*b.x + a.y*b.y;
}

// Vec2 cross(Vec2 a, Vec2 b) {
//     return {a.x*b.y, -b.x*a.y};
// }
