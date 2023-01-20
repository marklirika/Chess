#pragma once

#include <iostream>
#include <string>

#include "Board.h"

using namespace sf;
using namespace std;	

class Board;

class Piece
{
public:
	virtual bool TryToMove(int row, int col) = 0;

	virtual bool IsAbleToMove(int row, int col) = 0;
		
	virtual void Move(int row, int col) = 0;
	
	virtual string GetType() = 0;
	
	virtual Sprite GetSprite(Board &board) = 0;

	virtual int GetRow();

	virtual int GetColumn();

	virtual bool IsWhite();

	virtual bool GetFirstMove();

	virtual bool GetSide();

	virtual bool GetMoveAbility();

	virtual void SetMoveAbility(bool condition);

protected:
	int row, col;

	bool move_ability;
	bool is_white;

	Texture t_white;
	Texture t_black;
	
	Sprite sprite;
};


