#include "../include/physics.hpp"


Object::Object() {

}

Object::~Object() {

}

void Object::updatePosition(double dt) {
    if (moveable == false) {
        impulse = {};
        return;
    }

    Vec2 dx = position_current - position_previous;
    // Vec2 velocity = getVelocity(dt);

    position_previous = position_current;
    position_current += dx + impulse*dt;
    impulse = {};
}

Vec2 Object::getVelocity(double dt) {
    return (position_current - position_previous) / dt;
}

void applyGravity(double dt, Object &obj_1, Object &obj_2) {
    const double G = 500.0;
    Vec2 dist_between_objs = obj_1.position_current - obj_2.position_current;
    double dist2 = Math::norm2(dist_between_objs);
    Vec2 normal_direction  = dist_between_objs / std::sqrt(dist2);
    obj_1.impulse -= G * obj_1.mass * obj_2.mass / dist2 * normal_direction * dt;
    obj_2.impulse += G * obj_1.mass * obj_2.mass / dist2 * normal_direction * dt;
}

void substepPhysics(double dt, std::vector<Object>& objs) {
    const int substeps = 8;
    dt /= substeps;
    for (int _ = 0; _ < substeps; _++) {
        for (int i = 0; i < objs.size(); i++) {
            for (int j = i+1; j < objs.size(); j++) {
                applyGravity(dt, objs[i], objs[j]);
            }
            objs[i].updatePosition(dt);
        }
    }
}
