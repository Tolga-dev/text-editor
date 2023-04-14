//
// Created by xamblot on 4/10/23.
//

#ifndef TEXTEDITOR_CURSOR_H
#define TEXTEDITOR_CURSOR_H

/// General Cursor Movement
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#include <SFML/Graphics.hpp>
#include <vector>
namespace Cursor
{
    class Cursor
    {
    public:
        Cursor();
        Cursor(int lineN, int charN);

//////////////////////////////////////> set
        void MoveCursorUpdate(int col_u, int row_u);
        void Set_Offsets(float x, float y);

//////////////////////////////////////> set
        int Get_Col() const;
        int Get_Row() const;
        float Get_x_offset() const;
        float Get_y_offset() const;
/////////////////////////////////////> CUrsor Change Pos
        int GetMoveUpPos();
        void MoveUp(const std::vector<std::vector<char>>& lines);

        int GetMoveDownPos() const;
        void MoveDown(const std::vector<std::vector<char>>& lines);

        int GetMoveLeftPos() const;
        void MoveLeft(const std::vector<std::vector<char>>& lines);

        void MoveRight(const std::vector<std::vector<char>>& lines);
/////////////////////////////////////> Camera Change Pos

        // for camera pos, used 2 pointer, if they re same and 0, camera go up, if it gets over the max number between these
        //numbers, camera go down, max_number will be 29 for now
        int begin_line=0;
        int curr_line=0;
        int maxDrawnLine = 28;
    private:
        float x_off_set{}, y_off_set{};
        int col{},row{};
        int MaxCharSizeLeft=0,MaxCharSizeDown =0;
    };

}
#endif //TEXTEDITOR_CURSOR_H
