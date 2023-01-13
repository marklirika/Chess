#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Piece.h"
#include <iostream>

using namespace sf;
using namespace std;

void LeftButtonClick(RenderWindow& window, Vector2i& MousePosition, Board& board, vector<shared_ptr<Piece>>& pieces, shared_ptr<Piece>& chosen)
{
	MousePosition = Mouse::getPosition(window);
	// Считаем клетку на которую произвелся клик
	int row = MousePosition.x / board.GetWidth();
	int col = MousePosition.y / board.GetHeight();
	cout << "mouse pos x : " << row;
	cout << "  mouse pos y : " << col << endl;

	// Если координаты клика соответствуют координатам фигуры из масива выбираем эту фигуру
	int index = -1;
	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces[i]->GetRow() == row && pieces[i]->GetColumn() == col)
			index = i;
	}
	if (chosen == NULL)
	{
		// Если клетка пустая и при этом никакая фигура не выбрана то ничего не делаем
		if (index == -1)
			cout << "Index : " << index << "return accomplished" << endl;
		else
		{
			// Если фигура не выбрана,то меняем ей параметр выбраности и общий параметр тоже
			if (pieces[index]->IsWhite() == board.GetTurn())
			chosen = pieces[index];
			cout << "Chosen Piece : " << index << endl;
		}
	}
	else
	{
		cout << "Piece is Already Chosen " << endl << "Chosen row is : " << chosen->GetRow() << " Col is : " << chosen->GetColumn() << endl;
		
		// Проверяем пустая ли клетка через index.

		if (index != -1)
		{
			//если клетка не пустая, и та м стоит фигура,то проверяем одного ли они цвета.
			if (pieces[index]->IsWhite() == chosen->IsWhite())
			{
				// Если их цвета одинаковый перевыбираем фигуру и выходим
				cout << "Similar Color of Pieces" << chosen->GetColumn();
				chosen = pieces[index];
				cout << "Chosen Changed" << endl;
			}
			else
				// Если цвет не одинаковый,то проверяем может ли фигура перейти на клетку
				if (chosen->IsAbleToMove(row, col) == true)
				{
					cout << "Color of Pieces is defferent." << endl;
					//Если фигура можетт перейти она переходит,удаляя вражескую фигуру.
					auto it = pieces.begin();
					advance(it, index);
					chosen->Move(row, col);
					pieces.erase(it);
					cout << "Piece " << index << " Deleted";
					cout << "Piece Moved to : " << chosen->GetRow() << " " << chosen->GetColumn();
					chosen = nullptr;
					board.EndOfTurn();

				}
		}
		else
			//Если клетка пустая, проверяем может ли туда перейти фигура,если да,двигаем ее,есои нет ничего не делаем
			if (chosen->IsAbleToMove(row, col) == true)
			{
				chosen->Move(row, col);
				cout << "Piece Moved to : " << chosen->GetRow() << " " << chosen->GetColumn();
				chosen = nullptr;
				board.EndOfTurn();
				cout << ", End Of Turn" << endl;
			}
	}
	std::cout << "\t END OF OPERATIONS " << endl;
}