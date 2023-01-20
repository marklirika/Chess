#pragma once

#include "Piece.h"

class Bishop
    : public Piece
{
public:

    Bishop(int row, int col, bool isWhite);

    bool IsBlocked(int row, int col);

    bool TryToMove(int row, int col) override;

    void Move(int row, int col) override;

    bool IsAbleToMove(int row, int col) override;

    string GetType() override;

    Sprite GetSprite(Board &board) override;
};