#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Piece.h"

class Piece;
class King;

class Board
{
public:
	Board();
	~Board();

	sf::RectangleShape GetRectangle(int row, int col);

	void CreateBoard();

	void SetupBoard();

	void DeleteBoard();

	int GetColumn() const { return Column; }

	int GetRow() const { return Row; }

	int GetWidth() const { return Width; }

	int GetHeight() const { return Height; }

	void EndOfTurn();

	bool GetTurn();

private:
	int Row, Column;
	int Height, Width;

	sf::Color clr[3];
	sf::RectangleShape** rect;

	bool Turn;
};