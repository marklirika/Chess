#pragma once
#include "Bishop.h"
#include <iostream>
#include "Download.h"

void Bishop::Move(int row, int col)
{
	this->Row = row;
	this->Column = col;
}

bool Bishop::IsAbleToMove(int row, int col)
{
	if (!this->GetMoveAbility())
		return false;

	if ((row + col == this->Row + this->Column) || (row - col == (this->Row - this->Column)))
		if(!this->IsBlocked(row, col))
		{
			if (!this->Try(row, col))
				return false;
			return true;
		}
	return false;
}
	
string Bishop::GetType()
{
	return "Bishop";
}

int Bishop::GetRow()
{
	return this->Row;
}

int Bishop::GetColumn()
{
	return this->Column;
}

bool Bishop::IsWhite()
{
	return this->isWhite;
}



Sprite Bishop::GetSprite(Board &board)
{
	if (this->isWhite == true)
	{
		this->t_white.loadFromFile("Z:\\Programing projects\\ChessSFML\\Textures\\BishopWhite.png");
		this->sprite.setTexture(t_white);
	}
	else
	{
		this->t_black.loadFromFile("Z:\\Programing projects\\ChessSFML\\Textures\\BishopBlack.png");
		this->sprite.setTexture(t_black);
	}

	this->sprite.setPosition(Vector2f(float(this->Row) * board.GetHeight() + 20, float(this->Column) * board.GetWidth() + 20));

	return this->sprite;	
}	



bool Bishop::IsBlocked(int row, int col)
{
	if (row < this->Row && col < this->Column)
		for (int i = row + 1, j = col + 1; i < this->Row; i++, j++)
			if (!global::SquareIsFree(global::pieces, i, j))
				return true;

	if (row > this->Row && col < this->Column)
		for (int i = row - 1, j = col + 1; i > this->Row; i--, j++)
			if (!global::SquareIsFree(global::pieces, i, j))
				return true;

	if (row < this->Row && col > this->Column)		
		for (int i = row + 1, j = col - 1; i < this->Row; i++, j--)
			if (!global::SquareIsFree(global::pieces, i, j))
				return true;

	if (row > this->Row && col > this->Column)
		for (int i = row - 1, j = col - 1; i > this->Row; i--, j--)
			if (!global::SquareIsFree(global::pieces, i, j))
				return true;

	return false;
}

bool Bishop::Try(int row, int col)
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