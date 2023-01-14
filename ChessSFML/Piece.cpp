#pragma once

#include <iostream>

#include "Piece.h"

int Piece::GetRow()
{
	return this->row;
}

int Piece::GetColumn()
{
	return this->col;
}

bool Piece::IsWhite()
{
	return this->is_white;
}

bool Piece::GetSide()
{
	return true;
}

bool Piece::GetFirstMove()
{
	return true;
}

void Piece::SetMoveAbility(bool condition)
{
	this->move_ability = condition;
}

bool Piece::GetMoveAbility()
{
	return move_ability;
}
