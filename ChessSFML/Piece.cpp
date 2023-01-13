#pragma once
#include "Piece.h"
#include <iostream>
//
//int Piece::Init(int row, int col, bool isWhite)
//{
//	this->Row = row;
//	this->Column = col;
//	this->isWhite = isWhite;
//	return 0;
//}
//
//void Piece::Move(int row, int col)
//{
//	this->Row = row;
//	this->Column = col;
//}
//
//bool Piece::IsAbleToMove(int row, int col)
//{
//	return true;
//}
//
//int Piece::GetRow()
//{
//	return this->Row;
//}
//
//int Piece::GetColumn()
//{
//	return this->Column;
//}
////
//bool Piece::IsWhite()
//{
//	return this->isWhite;
//}
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
