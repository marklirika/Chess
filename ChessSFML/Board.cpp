#pragma once

#include "Global.h"

#include "Board.h"

using namespace sf;

class Pawn;

Board::Board() :
	rect(nullptr), Column(8), Row(8), Height(120), Width(120), Turn(true)
{
	clr[0] = sf::Color(250, 253, 210);
	clr[1] = sf::Color(23, 114, 70);
	clr[2] = sf::Color(0, 0, 0);
	
}

Board::~Board() {
	DeleteBoard();
}

void Board::CreateBoard() {
	if (rect != nullptr)
		DeleteBoard();
	rect = new RectangleShape * [Row];

	for (int row = 0; row < Row; row++)
	{
		rect[row] = new RectangleShape[Column];
	}
}

void Board::SetupBoard() {
	if (rect == nullptr)
		CreateBoard();

	for (int row = 0; row < Row; row++)
		for (int col = 0; col < Column; col++)
		{
			rect[row][col].setSize(Vector2f(float(this->GetWidth()), float(this->GetHeight())));
			rect[row][col].move(float(row * GetWidth()), float(col * GetHeight()));
			if ((row + col) % 2 == 0)
			{
				rect[row][col].setFillColor(clr[0]);
			}
			else
			{
				rect[row][col].setFillColor(clr[1]);
			}
		}
}

void Board::DeleteBoard() {
	if (rect != nullptr) {
		for (int row = 0; row < Row; row++)
			if (rect[row] != nullptr)
			{
				delete[] rect[row];
				rect[row] = nullptr;
			}
	}
}

RectangleShape Board::GetRectangle(int row, int col)
{
	if(rect != nullptr)
		return rect[row][col];
}

bool Board::GetTurn()
{
	return this->Turn;
}

void Board::EndOfTurn()
{
	if (this->Turn)
	{
		if (King::Check(!this->Turn, global::pieces))
			cout <<endl << endl<< "Check to black Was commited" << endl << endl;
		King::SetWhiteCheck(false);
		Pawn::SetBlackEP(false);
		this->Turn = false;
		std::cout << "\tWHITE TURN ENDS";
	}
	else
	{
		if (King::Check(!this->Turn, global::pieces))
			cout << endl << endl << "Check to white Was commited" << endl << endl;

		King::SetBlackCheck(false);
		Pawn::SetWhiteEP(false);
		this->Turn = true;
		std::cout << "\tBLACK TURN ENDS";
	}
}