#include "../include/core.hpp"
#include <iostream>
#include <stdlib.h>


int main() {
    sf::RenderWindow win(sf::VideoMode(1400, 1400), "Window");
    win.setFramerateLimit(200);

    double dt = 1.0/200.0;

    std::vector<Object> objs;
    std::vector<sf::CircleShape> circles;

    Object obj3;
    obj3.position_current  = {700.0, 700.0};
    obj3.position_previous = obj3.position_current;
    obj3.impulse = {0.0, 0.0};
    obj3.radius = 25.0;
    obj3.mass = 5000.0;
    obj3.moveable = false;

    for (int i = 0; i < 10; i++) {
        Object obj;
        obj.position_current  = {rand() % 100 + 700.0, rand() % 200 + 200.0};
        obj.position_previous = obj.position_current;
        obj.impulse = {rand() % 20 + 40.0, 0};
        obj.radius = rand() % 20 + 1.0;
        obj.mass = rand() % 10;
        obj.moveable = true;

        sf::CircleShape circle;
        circle.setOrigin({(float) obj.radius, (float) obj.radius});
        circle.setPosition((sf::Vector2f) obj.position_current);
        circle.setRadius((float) obj.radius);
        circle.setPointCount(200);
        circle.setFillColor(sf::Color::White);

        objs.push_back(obj);
        circles.push_back(circle);
    }

    sf::CircleShape circle3;
    circle3.setOrigin({(float) obj3.radius, (float) obj3.radius});
    circle3.setPosition((sf::Vector2f) obj3.position_current);
    circle3.setRadius((float) obj3.radius);
    circle3.setPointCount(200);
    circle3.setFillColor(sf::Color::Red);

    
    objs.push_back(obj3);
    circles.push_back(circle3);

    while (win.isOpen()) {
        listenForEvents(win);
        substepPhysics(dt, objs);
        
        win.clear(sf::Color::Black);

        for (int i = 0; i < objs.size(); i++) {
            sf::Vertex line[] = {
                sf::Vertex((sf::Vector2f) objs[i].position_current),
                sf::Vertex((sf::Vector2f) (objs[i].position_current + objs[i].getVelocity(dt/8))),
            };

            win.draw(line, 2, sf::Lines);

            circles[i].setPosition((sf::Vector2f) objs[i].position_current);
            win.draw(circles[i]);
        }
        win.display();
    }

    return 0;
}
