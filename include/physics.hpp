#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <vector>
#include <iostream>
#include "math.hpp"

using Vec2 = sf::Vector2<double>;

class Object {
    public:
        Vec2 position_current;
        Vec2 position_previous;
        Vec2 impulse;

        double radius;
        double mass;

        bool moveable;
    public:
        Object();
        ~Object();

        void updatePosition(double dt);

        Vec2 getVelocity(double dt);
    
};

void applyGravity(double dt, Object &obj_1, Object &obj_2);

void substepPhysics(double dt, std::vector<Object>& objs);