#include <sstream>
#include "include/Editor.h"

Editor::Editor(DocumentHandle& documentHandle, sf::Text& text)
{
    cursor.Set_Offsets(text.getLocalBounds().width, text.getCharacterSize());

    std::string get_line;

    while(documentHandle.p_file_ptr)
    {
        getline(documentHandle.p_file_ptr, get_line);
        lines.push_back(line);
        for (auto ch: get_line) {
            lines[line_number].push_back(ch);
        }
        line_number++;
    }
    documentHandle.p_file_ptr.close();

}


void Editor::Add_Enter() {
    std::vector<char> temp_line;

    if (cursor.Get_Row() < lines.size()) { // if ure in the middle of line
        if (cursor.Get_Col() == lines[cursor.Get_Row()].size()) {
            lines.insert(lines.begin() + cursor.Get_Row() + 1, temp_line);
        }
        else if (cursor.Get_Col() < lines[cursor.Get_Row()].size()) {
            for (int i = cursor.Get_Col();i < lines[cursor.Get_Row()].size(); ++i) {
                temp_line.push_back(lines[cursor.Get_Row()][i]);
            }
            lines[cursor.Get_Row()].erase(lines[cursor.Get_Row()].begin() + cursor.Get_Col(), lines[cursor.Get_Row()].end());
            lines.insert(lines.begin() + cursor.Get_Row() + 1, temp_line);
        }
    }
    else {
        lines.push_back(temp_line);
    }
}

void Editor::Add_to_vector(char ch) {
    lines[cursor.Get_Row()].insert(lines[cursor.Get_Row()].begin() + cursor.Get_Col(), ch);
    cursor.MoveCursorUpdate(cursor.Get_Col() + 1, cursor.Get_Row());
}


void Editor::Handle_Cursor_Input(int key,sf::View& view, float UpDown) {

    switch (key) {
        case UP:
            if (cursor.GetMoveUpPos() >= 0)
            {
                cursor.MoveUp(lines);
            }
            break;
        case DOWN:
            if (cursor.Get_Row() < lines.size())
            {
                cursor.MoveDown(lines);
            }
            break;
        case LEFT:
        /// -1 because when ure in 0 as col, it should start at up
            if (cursor.GetMoveLeftPos() >= -1)
            {
                cursor.MoveLeft(lines);
            }
            break;
        case RIGHT:
            if (cursor.Get_Col() <= lines[cursor.Get_Row()].size() && cursor.Get_Row() < line_number)
            {
                cursor.MoveRight(lines);
            }
            break;

        default:
            break;
    }

    CameraMovementForCursor(view,UpDown);

}

void Editor::Handle_Keyboard_Input(sf::Keyboard::Key key,sf::View& view, float UpDown,sf::Event& event)
{
    switch (key) {
        case DELETE:
            if (cursor.Get_Col() == this->lines[cursor.Get_Row()].size()) { // if there is no char, one down line go up line
                if (cursor.Get_Row() + 1 < this->lines.size()) {
                    for (int i = 0;i < this->lines[cursor.Get_Row() + 1].size();++i) {
                        this->lines[cursor.Get_Row()].push_back(this->lines[cursor.Get_Row() + 1][i]);
                    }
                    this->lines.erase(this->lines.begin() + (cursor.Get_Row() + 1), this->lines.begin() + (cursor.Get_Row() + 2));
                }
            }
            else {
                //delete until no chars there
                this->lines[cursor.Get_Row()].erase(this->lines[cursor.Get_Row()].begin() + cursor.Get_Col(), this->lines[cursor.Get_Row()].begin() + cursor.Get_Col() + 1);
            }
            break;
        case BACK_SPACE:
            if (cursor.Get_Row() == 0 && cursor.Get_Col() == 0)
                return;
            // if ure in at the beginning of the line, go up line
            if (cursor.Get_Col() == 0) {
                int temp_loc = this->lines[cursor.Get_Row() - 1].size();
                for (int i = 0;i < this->lines[cursor.Get_Row()].size();++i) {
                    this->lines[cursor.Get_Row() - 1].push_back(this->lines[cursor.Get_Row()][i]);
                }
                this->lines.erase(this->lines.begin() + cursor.Get_Row(), this->lines.begin() + cursor.Get_Row() + 1);
                cursor.MoveCursorUpdate(temp_loc, cursor.Get_Row() - 1);
                cursor.curr_line--;
            }
            else {
                this->lines[cursor.Get_Row()].erase(this->lines[cursor.Get_Row()].begin() + cursor.Get_Col() - 1, this->lines[cursor.Get_Row()].begin() + cursor.Get_Col());
                cursor.MoveCursorUpdate(cursor.Get_Col() - 1, cursor.Get_Row());
            }

            this->CameraMovementForCursor(view,UpDown);
            break;
        case ENTER:
            if (event.key.code == sf::Keyboard::Enter) {
                this->Add_Enter();
                cursor.curr_line++;
                cursor.MoveCursorUpdate(0, cursor.Get_Row() + 1);
            }
            break;
        default:
            break;

    }
    this->CameraMovementForCursor(view,UpDown);

    cursor.MoveCursorUpdate(cursor.Get_Col(), cursor.Get_Row());

}

void Editor::CameraMovementForCursor(sf::View &view, float UpDown) {

    int diff = (cursor.curr_line - cursor.begin_line);
    if(diff == 0 && cursor.curr_line != 0) // ikisinin de 0 oldugu durumda yukari demeye gerek yok
    {
        cursor.begin_line--;
        UpDown -= 20;
        view.move(0,UpDown);
    }
    else if(diff > cursor.maxDrawnLine)
    {
        cursor.begin_line++;
        UpDown += 20;
        view.move(0,UpDown);
    }
}

void Editor::Draw(sf::RenderWindow &window, sf::Text &text) {
    float offsetx = 0;

    for (int i = 0; i < lines.size();++i) {
        offsetx = 0;
        for (int j = 0;j < lines[i].size();++j) {
            text.setString(lines[i][j]);
            text.setCharacterSize(16);
            text.setPosition(offsetx, i * 20);
            window.draw(text);
            offsetx += cursor.Get_x_offset() + 1;
        }
        if (lines[i].size() == 0) {
            text.setString(" ");
            text.setCharacterSize(16);
            text.setPosition(offsetx, i * 20);
        }
    }

    // Sidebar
    for (int i = 0; i < lines.size();++i) {
        offsetx = 0;
        text.setString(std::to_string(i + 1));
        text.setCharacterSize(14);
        text.setPosition(-35.f, i * 20 + 3);
        window.draw(text);

        // sf::RectangleShape marginRect(sf::Vector2f(40, 20));
        // marginRect.setFillColor(sf::Color(ONE_DARK_MARGIN_BACKGROUND));
        // marginRect.setPosition(-45.f, i * 20);
        // window.draw(marginRect);
    }

    // Cursor
    sf::RectangleShape cursorRect(sf::Vector2f(2, cursor.Get_y_offset() + 2));
    cursorRect.setFillColor(sf::Color::White);

    cursorRect.setPosition(
            (cursor.Get_Col()) * (cursor.Get_x_offset() + 1) + 1.f,
            (cursor.Get_Row() * (cursor.Get_y_offset() + 4)) + 1.f);

    window.draw(cursorRect);
}
