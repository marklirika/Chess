#pragma once
#include "Knight.h"
#include <iostream>

bool Knight::IsAbleToMove(int row, int col)
{
	if (!this->GetMoveAbility())
		return false;

	for (int i = 1; i < 3; i++) 
	{
		if ((row == this->Row + i && (col == this->Column + (3 - i) || col == this->Column - (3 - i))) || (row == this->Row - i && (col == this->Column + (3 - i) || col == this->Column - (3 - i))))
		{
			if (!this->Try(row, col))
				return false;
			return true;
		}
	}

	return false;

}

string Knight::GetType()
{
	return "Knight";
}

Sprite Knight::GetSprite(Board &board)
{
	if (this->isWhite == true) 
	{
		this->t_white.loadFromFile("Z:\\Programing projects\\ChessSFML\\Textures\\KnightWhite.png");
		this->sprite.setTexture(t_white);
	}
	else 
	{
		this->t_black.loadFromFile("Z:\\Programing projects\\ChessSFML\\Textures\\KnightBlack.png");
		this->sprite.setTexture(t_black);
	}

	this->sprite.setPosition(Vector2f(float(this->Row) * board.GetHeight() + 20, float(this->Column) * board.GetWidth() + 20));

	return this->sprite;
}

int Knight::GetRow()
{
	return this->Row;
}

int Knight::GetColumn()
{
	return this->Column;
}

bool Knight::IsWhite()
{
	return this->isWhite;
}

void Knight::Move(int row, int col)
{
	this->Row = row;
	this->Column = col;
}

bool Knight::Try(int row, int col)
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