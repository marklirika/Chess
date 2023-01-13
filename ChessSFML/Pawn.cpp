#pragma once
#include "Pawn.h"

void Pawn::Move(int row, int col)
{
    if (Pawn::GetEP())
        if (Pawn::ep_row == row && Pawn::ep_col == col)
            if ((col + 1 == this->Column || col - 1 == this->Column) && (row - 1 == this->Row || row + 1 == this->Row))
                if (this->isWhite)
                    Pawn::DeleteEnPassantPawn(global::pieces, row, col - 1);
                else
                    Pawn::DeleteEnPassantPawn(global::pieces, row, col + 1);

    if (this->first_move)
    {
        this->first_move = false;
        if (this->isWhite == true && row == this->Row && col - 2 == this->Column)
        {
            Pawn::SetWhiteEP(true);
            Pawn::SetEPSquare(row, col - 1);
        }
        if (this->isWhite == false && row == this->Row && col + 2 == this->Column)
        {
            Pawn::SetBlackEP(true);
            Pawn::SetEPSquare(row, col + 1);
        }

        this->Row = row;
        this->Column = col;
        return;
    }

    this->Row = row;
    this->Column = col;

    //if (this->isWhite == true && this->Column == 7)
    //    global::Promote(global::pieces, this->Row, this->Column, this->isWhite);

    //if (this->isWhite == false && this->Column == 0)
    //    global::Promote(global::pieces, this->Row, this->Column, this->isWhite);
}




bool Pawn::IsAbleToMove(int row, int col)
{
    if (!this->GetMoveAbility())
        return false;

    bool temp_bool = false;
    if (this->isWhite == true)
    {
        if (Pawn::GetEP())
            if (Pawn::ep_row == row && Pawn::ep_col == col)
                if (col - 1 == this->Column && (row - 1 == this->Row || row + 1 == this->Row))
                    temp_bool = true;

        if (global::SquareIsFree(global::pieces, row, col))
        {
            if (this->first_move)
                if (row == this->Row && col - 2 == this->Column)
                    temp_bool = true;
            if (row == this->Row && col - 1 == this->Column)
                temp_bool = true;
        }
        else
        {
            if (col - 1 == this->Column && (row - 1 == this->Row || row + 1 == this->Row))
                temp_bool = true;
        }
    }
    else
    {
        if (Pawn::GetEP())
            if (Pawn::ep_row == row && Pawn::ep_col == col)
                if (col + 1 == this->Column && (row == this->Row + 1 || row == this->Row - 1))
                    temp_bool = true;

        if (global::SquareIsFree(global::pieces, row, col))
        {
            if (this->first_move)
                if (row == this->Row && col + 2 == this->Column)
                    temp_bool = true;
            if (row == this->Row && col + 1 == this->Column)
                temp_bool = true;
        }
        else
        {
            if (col + 1 == this->Column && (row == this->Row + 1 || row == this->Row - 1))
                temp_bool = true;
        }
    }

    if(temp_bool == true)
    {
			if (!this->Try(row, col))
				return false;
			return true;
		}
    return false;
}

Sprite Pawn::GetSprite(Board& board)
{
    if (this->isWhite == true)
    {
        this->t_white.loadFromFile("Z:\\Programing projects\\ChessSFML\\Textures\\PawnWhite.png");
        this->sprite.setTexture(t_white);
    }
    else
    {
        this->t_black.loadFromFile("Z:\\Programing projects\\ChessSFML\\Textures\\PawnBlack.png");
        this->sprite.setTexture(t_black);
    }

    this->sprite.setPosition(Vector2f(float(this->Row) * board.GetHeight() + 20, float(this->Column) * board.GetWidth() + 20));
    return this->sprite;
}

int Pawn::GetRow()
{
    return this->Row;
}

int Pawn::GetColumn()
{
    return this->Column;
}

bool Pawn::IsWhite()
{
    return this->isWhite;
}

string Pawn::GetType()
{
    return "Pawn";
}

void Pawn::SetWhiteEP(bool en_passant)
{
    Pawn::white_en_passant = en_passant;
}

void Pawn::SetBlackEP(bool en_passant)
{
    Pawn::black_en_passant = en_passant;
}

bool Pawn::GetEP()
{
    if (Pawn::white_en_passant == true || Pawn::black_en_passant == true)
        return true;
    return false;
}

void Pawn::SetEPSquare(int row, int col)
{
    Pawn::ep_row = row;
    Pawn::ep_col = col;
}

void Pawn::DeleteEnPassantPawn(vector<shared_ptr<Piece>>& pieces, int row, int col)
{
    for (int i = 0; i < pieces.size(); i++)
    {
        if (pieces[i]->GetRow() == row && pieces[i]->GetColumn() == col)
        {
            cout << i << endl;
            auto it = pieces.begin();
            advance(it, i);
            pieces.erase(it);
        }

    }
}

void Promote(vector<shared_ptr<Piece>>& pieces, int row, int col, bool isWhite)
{
    int code;
    bool selection = true;
    cout << "Plese input a number:\n1 - Queen\n2 - Rook\n3 - Knight,\n4 - Bishop,\n 5 - Pawn\n";
    while (selection)
        cin >> code;
    switch (code)
    {
    case 1:
        pieces.push_back(make_shared<Queen>(Queen(row, col, isWhite)));
        selection = false;
        break;
    case 2:
        pieces.push_back(make_shared<Rook>(Rook(row, col, isWhite, false)));
        selection = false;
        break;
    case 3:
        pieces.push_back(make_shared<Knight>(Knight(row, col, isWhite)));
        selection = false;
        break;
    case 4:
        pieces.push_back(make_shared<Bishop>(Bishop(row, col, isWhite)));
        selection = false;
        break;
    case 5:
        selection = false;
        break;
    default:
        cout << "erorr,please enter the right number:\n1 - Queen\n2 - Rook\n3 - Knight,\n4 - Bishop,\n 5 - Pawn\n";
        break;
    }
    return;
}

bool Pawn::Try(int row, int col)
{
    int t_row = this->Row;
    int t_col = this->Column;
    bool succes = false;
    int i = 0;
    for (i; i < global::pieces.size(); i++)
        if (((global::pieces[i]->IsWhite() != this->IsWhite()) && (global::pieces[i]->GetRow()) == row) && (global::pieces[i]->GetColumn() == col))
        {
            global::pieces[i]->SetMoveAbility(false);
            succes = true;
            break;
        }

    this->Move(row, col);

    if (King::Check(this->isWhite, global::pieces))
    {
        this->Move(t_row, t_col);
        return false;
    }

    if (succes)
        global::pieces[i]->SetMoveAbility(true);

    this->Move(t_row, t_col);

    return true;
}
