#pragma once

#include "Global.h"
#include "Piece.h"

class King :
    public Piece
{
public:
    King(int row, int col, bool isWhite);

    bool IsAbleToMove(int row, int col) override;

    Sprite GetSprite(Board &board) override;

    void Move(int row, int col) override;

    //bool IsWhite() override;

    //int GetRow() override;

    //int GetColumn() override;

    string GetType() override;

    static bool Check(bool turn, vector<shared_ptr<Piece>> pieces);

    bool TryToMove(int row, int col);

    static bool CheckMate();

    static bool GetWhiteCheck();
    static bool GetBlackCheck();

    static bool SetWhiteCheck(bool condition);
    static bool SetBlackCheck(bool condition);

    static bool w_check;
    static bool b_check;
    static int wk_row, wk_col;
    static int bk_row, bk_col;

private:
    
    bool first_move = true;

};

