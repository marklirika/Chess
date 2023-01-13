#pragma once
#include "Board.h"
#include <iostream>
#include <string>
using namespace sf;
using namespace std;	
class Board;

class Piece
{
public:

	virtual bool IsWhite() = 0;

	virtual  bool IsAbleToMove(int row, int col) = 0;

	virtual void Move(int row, int col) = 0;

	virtual Sprite GetSprite(Board &board) = 0;

	virtual int GetRow() = 0;

	virtual int GetColumn() = 0;

	virtual bool GetFirstMove();

	virtual bool GetSide();

	virtual string GetType() = 0;

	virtual bool Try(int row, int col) = 0;

	virtual void SetMoveAbility(bool condition);

	virtual bool GetMoveAbility();
protected:
	std::vector<Piece> pieces;

	int Row, Column;

	bool move_ability;
	bool isWhite;
	
	Texture t_white;
	Texture t_black;

	Sprite sprite;
};


