//
// Created by xamblot on 4/10/23.
//

#ifndef TEXTEDITOR_EDITOR_H
#define TEXTEDITOR_EDITOR_H

#include <iostream>
#include <vector>
#include "cursor.h"
#include "DocumentHandle.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include "MajorKeys.h"

using namespace std;
#define SIZE_CHAR 16

class Editor
{
public:


    Editor() = default;
    Editor(DocumentHandle& documentHandle, sf::Text& text);
    ~Editor() = default;
    Editor(Editor const& Editor) = delete;
    Editor(Editor&& Editor) = default;
    Editor& operator=(const Editor& Editor) = delete;
    Editor& operator=(Editor&& Editor) = default;


    void Add_to_vector(char ch);
    void Add_Enter();

    void Draw(sf::RenderWindow& window, sf::Text& text);
    void Handle_Cursor_Input(int key,sf::View& view,float UpDown);
    void CameraMovementForCursor(sf::View& view,float UpDown);
    void Handle_Keyboard_Input(sf::Keyboard::Key key,sf::View& view, float UpDown,sf::Event& event);

    vector<vector<char>> lines;
    vector<char> line;
    int line_number = 0;
    Cursor::Cursor cursor;


};



#endif //TEXTEDITOR_EDITOR_H
