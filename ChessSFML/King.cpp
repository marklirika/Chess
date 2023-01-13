#include "King.h"
#include "Board.h"
//
//bool CheckMate()
//{
//	if(this->Check() == true)
//		if (this->IsAbleToMove(int row, int col) == false)
//
//}

bool King::IsAbleToMove(int row, int col)
{
	if (this->first_move == true) 
	{
		if (this->isWhite)
			cout << "FIRST MOVE IS TRUE";
		else
			cout << "SUCK";
		if (this->isWhite == true && (col == 0 && (row == 2 || row == 6)))
		{
			cout << "Catling tapped, starting..." << endl;
			return global::Castling(this, global::pieces, row, col);
		}
		if (this->isWhite == false && (col == 7 && (row == 2 || row == 6)))
		{
			cout << "Catling tapped, starting..." << endl;
			return global::Castling(this, global::pieces, row, col);
		}
	}
	
	for (int j = 1; j < 3; j++)
	{
		if (this->isWhite)
		{
			if (abs(King::bk_row - row) <= 1 && abs(King::bk_col - col) <= 1)
				return false;
		}
		else
			if (abs(King::wk_row - row) <= 1 && abs(King::wk_col - col) <= 1)
				return false;

		if (abs(this->Row - row) <= 1 && abs(this->Column - col) <= 1)
		{
			for (int i = 0; i < global::pieces.size(); i++)
				if (global::pieces[i]->IsWhite() != this->IsWhite())
					if (!(global::pieces[i]->GetType() == "King"))
					{
						if(global::pieces[i]->GetType() == "Pawn")
							if (global::pieces[i]->IsWhite())
							{
								if (col == global::pieces[i]->GetColumn() + 1 && (row == global::pieces[i]->GetRow() + 1 || row == global::pieces[i]->GetRow() - 1))
									return false;
							}
							else
							{
								if (col == global::pieces[i]->GetColumn() - 1 && (row == global::pieces[i]->GetRow() + 1 || row == global::pieces[i]->GetRow() - 1))
									return false;
							}
						if(global::pieces[i]->IsAbleToMove(row, col))
							return false;
					}
			return true;
		}
	}
	return false;
}


Sprite King::GetSprite(Board &board)
{
	if (this->isWhite == true)
	{
		this->t_white.loadFromFile("Z:\\Programing projects\\ChessSFML\\Textures\\KingWhite.png");
		this->sprite.setTexture(t_white);
	}
	else
	{
		this->t_black.loadFromFile("Z:\\Programing projects\\ChessSFML\\Textures\\KingBlack.png");
		this->sprite.setTexture(t_black);
	}

	this->sprite.setPosition(Vector2f(float(this->Row) * board.GetHeight() + 20, float(this->Column) * board.GetWidth() + 20));

	return this->sprite;
}

int King::GetRow()
{
	return this->Row;
}

int King::GetColumn()
{
	return this->Column;
}

bool King::IsWhite()
{
	return this->isWhite;
}


void King::Move(int row, int col)
{
	if (this->first_move)
		first_move = false;
	if (this->isWhite)
	{
		King::wk_row = row;
		King::wk_col = col;
	}
	else
	{
		King::bk_row = row;
		King::bk_col = col;
	}
	this->Row = row;
	this->Column = col;
}

string King::GetType()
{
	return "King";
}

bool King::Check(bool is_king_white, vector<shared_ptr<Piece>> pieces)
{
	for (int i = 0; i < pieces.size(); i++)
	{
		if (is_king_white == true)
			if ((pieces[i]->IsWhite() != is_king_white && pieces[i]->IsAbleToMove(King::wk_row, King::wk_col)))
			{
				cout << "\t\tCheck onto white King" << endl;
				return King::w_check = true;
			}
		if (is_king_white == false)
			if ((pieces[i]->IsWhite() != is_king_white && pieces[i]->IsAbleToMove(King::bk_row, King::bk_col)))
			{
				cout << "\t\tCheck onto black King" << endl;
				return King::b_check = true;
			}
	}
	return false;
}

bool King::GetWhiteCheck()
{
	return King::w_check;
}

bool King::GetBlackCheck()
{
	return King::b_check;
}

bool King::SetWhiteCheck(bool condition)
{
	return King::w_check = condition;
}

bool King::SetBlackCheck(bool condition)
{
	return King::b_check = condition;
}

bool King::Try(int row, int col)
{
	return true;
}