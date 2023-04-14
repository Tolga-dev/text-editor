#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "include/InputHandle.h"
#include "include/DocumentHandle.h"
#include "include/Editor.h"
#include "include/Colors.h"


int main()
{
    // window
    float CameraViewLeftRight = -45.f;
    float CameraViewDownUp = 0.f; // 5 row for every 100
    sf::RenderWindow window(sf::VideoMode(800, 600), "Editor Window");
    window.setVerticalSyncEnabled(true);
    sf::View view(sf::FloatRect(CameraViewLeftRight, CameraViewDownUp, 800.f, 600.f));
    // For Font
    sf::Font font;
    if(!font.loadFromFile("/home/xamblot/CLionProjects/textEditor/fonts/ARIAL.TTF"))
    {
        fprintf(stderr, " font file does not fount! \n");
        exit(0);
    }

    // Text
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(SIZE_CHAR);
    text.setFillColor(sf::Color(green)); // TEXT COLOR
    text.setString("W");

    // Document class
    std::string file_name = "/home/xamblot/CLionProjects/textEditor/file.txt";
    DocumentHandle document;
    document.Init(file_name);

    // Editor class
    Editor editor(document, text);

    // Input Events class
    InputEvents input_events;


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                document.p_file_ptr.close();
                window.close();
            }

            input_events.Handle_Input(editor, window, document, event,view,CameraViewDownUp);

        }

        window.clear(sf::Color(DARK_BACKGROUND));

        window.setView(view);

        editor.Draw(window, text);

        window.display();
    }


/*

    sf::Font font;
    sf::Text text;

    if(!font.loadFromFile("/home/xamblot/CLionProjects/textEditor/fonts/ArialCEItalic.ttf"))
    {
        fprintf(stderr, " font file does not fount! \n");
        exit(0);
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::View view(sf::FloatRect(-10.f, 0.f, 800.f, 600.f));

    std::string input_text = "";
    sf::Clock myClock; // starts the clock
    bool showCursor = false;
    char cursor = '_';

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }


            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    input_text += static_cast<char>(event.text.unicode);
                    text.setString(input_text);
                }
            }

        }

        // Clear the window
        window.clear();

        // Draw the text
        window.draw(text);
        window.setView(view);

        if(myClock.getElapsedTime() >= sf::milliseconds(500))
        {
            myClock.restart();
            showCursor = !showCursor;
            if(showCursor)
                text.setString(input_text + cursor);
            else
                text.setString(input_text);
        }

        // Display the window
        window.display();
    }
*/


    return 0;
}

