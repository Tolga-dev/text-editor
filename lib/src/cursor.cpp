#include "include/cursor.h"
#include <iostream>
using namespace std;
Cursor::Cursor::Cursor() : row(0),col(0) {

}
Cursor::Cursor::Cursor(int line, int char_nums) {}

void Cursor::Cursor::MoveCursorUpdate(int col_u, int row_u){
    this->col = col_u;
    this->row = row_u;
}

void Cursor::Cursor::Set_Offsets(float x, float y) {
    x_off_set = x;
    y_off_set = y;
}

int Cursor::Cursor::Get_Col() const {
    return this->col;
}

int Cursor::Cursor::Get_Row() const {
    return this->row;
}

float Cursor::Cursor::Get_x_offset() const {
    return x_off_set;
}

float Cursor::Cursor::Get_y_offset() const {
    return y_off_set;
}
int Cursor::Cursor::GetMoveUpPos()
{
    return Get_Row() - 1;
}

void Cursor::Cursor::MoveUp(const std::vector<std::vector<char>>& lines) {

    this->curr_line--;
    if (lines[this->GetMoveUpPos()].size() < this->Get_Col())
        this->MoveCursorUpdate(lines[this->GetMoveUpPos()].size(), this->GetMoveUpPos());
    else
        this->MoveCursorUpdate(this->Get_Col(), this->GetMoveUpPos());

}

int Cursor::Cursor::GetMoveDownPos() const {
    return Get_Row() + 1;
}

void Cursor::Cursor::MoveDown(const std::vector<std::vector<char>> &lines) {
    this->curr_line++;

    if (lines[this->GetMoveDownPos()].size() < this->Get_Col())
        this->MoveCursorUpdate(lines[this->GetMoveDownPos()].size(), this->GetMoveDownPos());
    else
        this->MoveCursorUpdate(this->Get_Col(), this->GetMoveDownPos());
}


int Cursor::Cursor::GetMoveLeftPos() const {
    return this->Get_Col() - 1;
}

void Cursor::Cursor::MoveLeft(const std::vector<std::vector<char>> &lines) {
    cout << this->GetMoveUpPos() << endl;
    if(this->Get_Col() == 0) // when ure at 0 go up!
    {
        if(this->GetMoveUpPos() >= 0) // at max up
            this->MoveUp(lines);
    }
    else
        this->MoveCursorUpdate(this->Get_Col() - 1, this->Get_Row());
}

void Cursor::Cursor::MoveRight(const std::vector<std::vector<char>> &lines) {
    if(this->Get_Col() == lines[this->Get_Row()].size())
        this->MoveDown(lines);
    else
        this->MoveCursorUpdate(this->Get_Col() + 1 , this->Get_Row());
}

















