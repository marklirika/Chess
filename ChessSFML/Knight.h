#pragma once

#include "Global.h"
#include "Piece.h"

class Knight:
    public Piece
{
public:
    Knight(int row, int col, bool is_white);

    bool TryToMove(int row, int col) override;

    bool IsAbleToMove(int row, int col) override;

    void Move(int row, int col) override;

    string GetType() override;

    Sprite GetSprite(Board &board) override;
};

