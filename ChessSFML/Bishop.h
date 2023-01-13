#pragma once
#include "Piece.h"

class Bishop
    : public Piece
{
public:
    Bishop(int row, int col, bool isWhite)
    {
        this->Row = row;
        this->Column = col;
        this->isWhite = isWhite;
        this->move_ability = true;
    }

public:

    void Move(int row, int col) override;

    bool IsAbleToMove(int row, int col) override;

    int GetRow() override;

    int GetColumn() override;

    bool IsWhite() override;

    string GetType() override;

    Sprite GetSprite(Board &board) override;

    bool IsBlocked(int row, int col);

    bool Try(int row, int col) override;
};