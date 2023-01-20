#pragma once

#include <iostream>

#include "Knight.h"

Knight::Knight(int row, int col, bool is_white)
{
	this->row = row;
	this->col = col;
	this->is_white = is_white;
	this->move_ability = true;
}

bool Knight::TryToMove(int row, int col)
{
	int t_row = this->row;
	int t_col = this->col;
	bool success = false;
	int i = 0;

	for (i; i < global::pieces.size(); i++)
		if (((global::pieces[i]->IsWhite() != this->IsWhite()) && (global::pieces[i]->GetRow()) == row) && (global::pieces[i]->GetColumn() == col))
		{
			global::pieces[i]->SetMoveAbility(false);
			success = true;
			break;
		}

	this->Move(row, col);

	if (King::Check(this->is_white, global::pieces))
	{
		this->Move(t_row, t_col);
		return false;
	}

	if (success)
		global::pieces[i]->SetMoveAbility(true);

	this->Move(t_row, t_col);

	return true;
}

bool Knight::IsAbleToMove(int row, int col)
{
	if (!this->GetMoveAbility())
		return false;

	for (int i = 1; i < 3; i++) 
	{
		if ((row == this->row + i && (col == this->col + (3 - i) || col == this->col - (3 - i))) || (row == this->row - i && (col == this->col + (3 - i) || col == this->col - (3 - i))))
		{
			if (!this->TryToMove(row, col))
				return false;
			return true;
		}
	}

	return false;

}

void Knight::Move(int row, int col)
{
	this->row = row;
	this->col = col;
}

string Knight::GetType()
{
	return "Knight";
}

Sprite Knight::GetSprite(Board& board)
{
	if (this->is_white == true)
	{
		this->t_white.loadFromFile("Textures/KnightWhite.png");
		this->sprite.setTexture(t_white);
	}
	else
	{
		this->t_black.loadFromFile("Textures/KnightBlack.png");
		this->sprite.setTexture(t_black);
	}

	this->sprite.setPosition(Vector2f(float(this->row) * board.GetHeight() + 20, float(this->col) * board.GetWidth() + 20));

	return this->sprite;
}
