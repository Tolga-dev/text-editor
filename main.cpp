#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //opening a window
    sf::Window window;
    window.create(sf::VideoMode(800, 600), "WIN");

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    }



    return 0;
}