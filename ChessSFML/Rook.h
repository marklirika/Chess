#pragma once
#include "Piece.h"
#include "Download.h"

class Rook :
    public Piece
{
public:
    
    Rook() {
        
    }

    Rook(int row, int col, bool isWhite, bool king_side)
    {
        this->Row = row;
        this->Column = col;
        this->isWhite = isWhite;
        this->king_side = king_side;
        this->move_ability = true;
    }

public:

    bool IsAbleToMove(int row, int col) override;

    Sprite GetSprite(Board &board) override;

    void Move(int row, int col) override;

    bool IsWhite() override;

    int GetRow() override;

    int GetColumn() override;

    bool IsBlocked(int row, int col);

    bool GetSide() override;

    bool GetFirstMove() override;

    string GetType() override;

    bool Try(int row, int col) override;

private:
    
    bool king_side;

    bool first_move = true;
};
