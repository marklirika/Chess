#pragma once

#include "Global.h"
#include "Piece.h"

class Rook :
    public Piece
{
public:
    
    Rook() {}

    Rook(int row, int col, bool is_white, bool king_side);

    bool IsBlocked(int row, int col);
    
    bool TryToMove(int row, int col) override;
    
    bool IsAbleToMove(int row, int col) override;

    void Move(int row, int col) override;
   
    string GetType() override;

    Sprite GetSprite(Board &board) override;

private:
    
    bool king_side;

    bool first_move = true;
};
