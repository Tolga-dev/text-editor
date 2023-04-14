//
// Created by xamblot on 4/10/23.
//

#ifndef TEXTEDITOR_INPUTHANDLE_H
#define TEXTEDITOR_INPUTHANDLE_H

#include <SFML/Graphics.hpp>
#include "Editor.h"

class InputEvents
{
public:

    InputEvents();
    ~InputEvents() = default;
    InputEvents(InputEvents const& InputEvents) = delete;
    InputEvents(InputEvents&& InputEvents) = default;
    InputEvents& operator=(const InputEvents& InputEvents) = delete;
    InputEvents& operator=(InputEvents&& InputEvents) = default;


    void Handle_Input(Editor& editor, sf::RenderWindow& window, DocumentHandle& document, sf::Event& event,sf::View& view, float UpDown);

    void HandleMajorKeyPress(Editor& editor, DocumentHandle& document, Cursor::Cursor& cursor, sf::Event& event,sf::View& view, float UpDown);
    void Handle_text_entered(Editor& editor, sf::Event& event);

};



#endif //TEXTEDITOR_INPUTHANDLE_H
