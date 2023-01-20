#pragma once

#include <iostream>

#include "Global.h"
#include "Piece.h"

class Pawn :
    public Piece
{
public:
    Pawn(int row, int col, bool is_white);

    bool TryToMove(int row, int col) override;

    bool IsAbleToMove(int row, int  col) override;

    void Move(int row, int col) override;

    string GetType() override;

    Sprite GetSprite(Board& board) override;

    static bool GetEP();
    static void SetWhiteEP(bool en_passant);
    static void SetBlackEP(bool en_passant);
    static void SetEPSquare(int row, int col);
    static void DeleteEnPassantPawn(vector<shared_ptr<Piece>>& pieces, int row, int col);

    static bool white_en_passant;
    static bool black_en_passant;
    static int ep_row, ep_col;

private:

    bool first_move = true;
};

