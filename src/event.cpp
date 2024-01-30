#include "../include/event.hpp"


void listenForEvents(sf::RenderWindow &window) {
        sf::Event event;
        while (window.pollEvent(event)) {
        // close window and stop process
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();
        }
}