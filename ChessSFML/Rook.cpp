#pragma once
#include "Rook.h"
#include <iostream>



bool Rook::IsAbleToMove(int row, int col)
{
	if (!this->GetMoveAbility())
		return false;

		if (!(row != this->Row && col != this->Column))
			if (!IsBlocked(row, col))
			{
				if (!this->Try(row, col))
					return false;
				return true;
			}
	return false;
}


Sprite Rook::GetSprite(Board &board)
{
	if (this->isWhite == true)
	{
		this->t_white.loadFromFile("Z:\\Programing projects\\ChessSFML\\Textures\\RookWhite.png");
		this->sprite.setTexture(t_white);
	}
	else
	{
		this->t_black.loadFromFile("Z:\\Programing projects\\ChessSFML\\Textures\\RookBlack.png");
		this->sprite.setTexture(t_black);
	}

	this->sprite.setPosition(Vector2f(float(this->Row) * board.GetHeight() + 20, float(this->Column) * board.GetWidth() + 20));
	return this->sprite;
}


int Rook::GetRow()
{
	return this->Row;
}

int Rook::GetColumn()
{
	return this->Column;
}

bool Rook::IsWhite()
{
	return this->isWhite;
}


void Rook::Move(int row, int col)
{
	if (first_move)
		first_move = false;
	this->Row = row;
	this->Column = col;
}



bool Rook::IsBlocked(int row, int col)
{
	if (row < this->Row)
		for (int i = row + 1; i < this->Row; i++)
			if (!global::SquareIsFree(global::pieces, i, col))
				return true;

	if (row > this->Row)
		for (int i = this->Row + 1; i < row; i++)
			if (!global::SquareIsFree(global::pieces, i, col))
				return true;

	if (col < this->Column)
		for (int i = col + 1; i < this->Column; i++)
			if (!global::SquareIsFree(global::pieces, row, i))
				return true;
		
	if (col > this->Column)
		for (int i = this->Column + 1; i < col; i++)
			if (!global::SquareIsFree(global::pieces, row, i))
				return true;
	return false;
}

bool Rook::GetSide()
{
	return this->king_side;
}

bool Rook::GetFirstMove()
{
	return this->first_move;
}

string Rook::GetType()
{
	return "Rook";
}

bool Rook::Try(int row, int col)
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