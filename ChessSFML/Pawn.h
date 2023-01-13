#pragma once
#include "Piece.h"
#include "Download.h"
#include <iostream>
class Pawn :
    public Piece
{
public:
    Pawn(int row, int col, bool isWhite)
    {
        this->Row = row;
        this->Column = col;
        this->isWhite = isWhite;
        this->move_ability = true;
    }

    bool IsAbleToMove(int row, int  col) override;

    Sprite GetSprite(Board& board) override;

    void Move(int row, int col) override;

    bool IsWhite() override;

    int GetRow() override;

    int GetColumn() override;

    string GetType() override;

    bool Try(int row, int col) override;

    static bool white_en_passant;
    static bool black_en_passant;
    static int ep_row, ep_col;

    static void SetWhiteEP(bool en_passant);
    static void SetBlackEP(bool en_passant);
    static bool GetEP();
    static void SetEPSquare(int row, int col);
    static void DeleteEnPassantPawn(vector<shared_ptr<Piece>>& pieces, int row, int col);

private:

    bool first_move = true;
};

