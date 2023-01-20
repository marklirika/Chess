#pragma once

#include <iostream>

#include "Global.h"
#include "Bishop.h"

Bishop::Bishop(int row, int col, bool isWhite)
{
	this->row = row;
	this->col = col;
	this->is_white = isWhite;
	this->move_ability = true;
}

bool Bishop::IsBlocked(int row, int col)
{
	if (row < this->row&& col < this->col)
		for (int i = row + 1, j = col + 1; i < this->row; i++, j++)
			if (!global::SquareIsFree(global::pieces, i, j))
				return true;

	if (row > this->row && col < this->col)
		for (int i = row - 1, j = col + 1; i > this->row; i--, j++)
			if (!global::SquareIsFree(global::pieces, i, j))
				return true;

	if (row < this->row && col > this->col)
		for (int i = row + 1, j = col - 1; i < this->row; i++, j--)
			if (!global::SquareIsFree(global::pieces, i, j))
				return true;

	if (row > this->row && col > this->col)
		for (int i = row - 1, j = col - 1; i > this->row; i--, j--)
			if (!global::SquareIsFree(global::pieces, i, j))
				return true;

	return false;
}

bool Bishop::TryToMove(int row, int col)
{
	int t_row = this->row;
	int t_col = this->col;
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

	if (King::Check(this->is_white, global::pieces))
	{
		this->Move(t_row, t_col);
		return false;
	}

	if (succes)
		global::pieces[i]->SetMoveAbility(true);

	this->Move(t_row, t_col);

	return true;
}

void Bishop::Move(int row, int col)
{
	this->row = row;
	this->col = col;
}

bool Bishop::IsAbleToMove(int row, int col)
{
	if (!this->GetMoveAbility())
		return false;

	if ((row + col == this->row + this->col) || (row - col == (this->row - this->col)))
		if(!this->IsBlocked(row, col))
		{
			if (!this->TryToMove(row, col))
				return false;
			return true;
		}
	return false;
}
	
string Bishop::GetType()
{
	return "Bishop";
}

Sprite Bishop::GetSprite(Board &board)
{
	if (this->is_white == true)
	{
		this->t_white.loadFromFile("Textures/BishopWhite.png");
		this->sprite.setTexture(t_white);
	}
	else
	{
		this->t_black.loadFromFile("Textures/BishopBlack.png");
		this->sprite.setTexture(t_black);
	}

	this->sprite.setPosition(Vector2f(float(this->row) * board.GetHeight() + 20, float(this->col) * board.GetWidth() + 20));

	return this->sprite;	
}	