#include "include/InputHandle.h"
#include "include/MajorKeys.h"


InputEvents::InputEvents() {

}

void InputEvents::Handle_Input(
        Editor &editor,
        sf::RenderWindow &window,
        DocumentHandle &document,
        sf::Event &event,sf::View& view, float UpDown) {
    // special chars
    HandleMajorKeyPress(editor, document, editor.cursor, event,view,UpDown);
    // typing chars
    Handle_text_entered(editor, event);
}

// enter, cursor movement
void InputEvents::HandleMajorKeyPress(Editor& editor, DocumentHandle& DocumentHandle, Cursor::Cursor& cursor, sf::Event& event,sf::View& view, float UpDown) {
    /// A key was pressed (data in event.key)
    bool LEFT_CONTROL_PRESSED = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code) {
            case ARROW_UP: editor.Handle_Cursor_Input(UP,view,UpDown); break;
            case ARROW_DOWN: editor.Handle_Cursor_Input(DOWN,view,UpDown); break;
            case ARROW_LEFT: editor.Handle_Cursor_Input(LEFT,view,UpDown); break;
            case ARROW_RIGHT: editor.Handle_Cursor_Input(RIGHT,view,UpDown); break;
            case DELETE: editor.Handle_Keyboard_Input(DELETE,view,UpDown,event); break;
            case BACK_SPACE: editor.Handle_Keyboard_Input(BACK_SPACE,view,UpDown,event); break;
            case ENTER: editor.Handle_Keyboard_Input(ENTER,view,UpDown,event); break;

            default:
                break;
        }

        if (LEFT_CONTROL_PRESSED && event.key.code == S)
        {
            std::ofstream output_file(DocumentHandle.p_file_name);
            for (auto & line : editor.lines) {
                for (int j = 0;j < line.size();++j) {
                    output_file << line[j];
                }
                output_file << std::endl;
            }
            output_file.close();
        }
    }
}


void InputEvents::Handle_text_entered(Editor &editor, sf::Event &event)
{
    // dont conflict with major keys
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) &&
    event.type == sf::Event::TextEntered) {
        editor.Add_to_vector((char)event.text.unicode);
    }

}

