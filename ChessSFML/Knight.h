#pragma once
#include "Piece.h"
#include "Download.h"
class Knight:
    public Piece
{
public:
    Knight(int row, int col, bool isWhite)
    {
        this->Row = row;
        this->Column = col;
        this->isWhite = isWhite;
        this->move_ability = true;
    }

public:
    bool IsAbleToMove(int row, int col) override;

    Sprite GetSprite(Board &board) override;

    void Move(int row, int col) override;

    bool IsWhite() override;

    int GetRow() override;

    int GetColumn() override;

    string GetType() override;

    bool Try(int row, int col) override;

};

