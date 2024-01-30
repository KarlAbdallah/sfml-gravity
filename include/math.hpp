#pragma once

#include <cmath>
#include <SFML/System/Vector2.hpp>

using Vec2 = sf::Vector2<double>;

namespace Math {
    double norm(Vec2 vec);

    double norm2(Vec2 vec);
    
    Vec2 normalize(Vec2 vec);

    double dot(Vec2 a, Vec2 b);
    
};

