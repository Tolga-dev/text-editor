#include "window.h"


void Window::GeneralWindow()
{
    // Create a graphical text to display
    sf::Font font;
    sf::Text a("ANAN", font, 500);
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(a);

        window.clear();
        window.display();
    }

}
