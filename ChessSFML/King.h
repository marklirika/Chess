#pragma once
#include "Piece.h"
#include "Download.h"
class King :
    public Piece
{
public:
    King(int row, int col, bool isWhite)
    {
        this->Row = row;
        this->Column = col;
        this->isWhite = isWhite;
        if (isWhite)
        {
            King::wk_row = row;
            King::wk_col = col;
        }
        else
        {
            King::bk_row = row;
            King::bk_col = col;
        }
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

    static bool Check(bool turn, vector<shared_ptr<Piece>> pieces);

    bool Try(int row, int col);

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

