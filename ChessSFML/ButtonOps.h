#pragma once
#define DEBUG

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Board.h"
#include "Piece.h"

using namespace sf;
using namespace std;

void LeftButtonClick(RenderWindow& window, Vector2i& MousePosition, Board& board, vector<shared_ptr<Piece>>& pieces, shared_ptr<Piece>& chosen)
{
	// Caclucate coordinates of a click
	MousePosition = Mouse::getPosition(window);
	int row = MousePosition.x / board.GetWidth();
	int col = MousePosition.y / board.GetHeight();

#ifdef DEBUG
	cout << "mouse pos x : " << row;
	cout << "  mouse pos y : " << col << endl;
#endif
	// Chosing a piece with an appropriate coordinates
	int index = -1;
	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces[i]->GetRow() == row && pieces[i]->GetColumn() == col)
			index = i;
	}
	if (chosen == NULL)
	{
		// if square that was clicked is empty and piece isn't selected, do nothing
		if (index == -1)
#ifdef DEBUG
			cout << "Squere is empty and piece is not chosen yet, index : " << index << "\nOperation accomplished\n" << endl;
#endif
		else
		{
			// if square isn't empty select it's piece and save it
			if (pieces[index]->IsWhite() == board.GetTurn())
			chosen = pieces[index];
#ifdef DEBUG
			cout << "Chosen Piece : " << index << endl;
#endif
		}
	}
	else
	{
		cout << "Piece is Already Chosen " << endl << "Chosen row is : " << chosen->GetRow() << " Col is : " << chosen->GetColumn() << endl;
		
		// Check is square is free with index.

		if (index != -1)
		{
			//if square isn't free and there is a piece, compairing it's color to a color of a chosen one
			if (pieces[index]->IsWhite() == chosen->IsWhite())
			{
				// if color is similar, reselect a piece and leave
				chosen = pieces[index];
#ifdef DEBUG
				cout << "Similar Color of Pieces" << chosen->GetColumn();
				cout << "Chosen Changed" << endl;
#endif
			}
			else
				// if color of compared pieces is not similar try checking an ability of a chosen piece to move to a square
				if (chosen->IsAbleToMove(row, col) == true)
				{
					//if selected piece is able to move remove piece on coordinates of click and move selected piece to this square
					auto it = pieces.begin();
					advance(it, index);
					chosen->Move(row, col);
					pieces.erase(it);
					chosen = nullptr;
#ifdef DEBUG
					cout << "Colors of Pieces are different." << endl;
					cout << "Piece " << index << " Deleted";
					cout << "Piece Moved to : " << chosen->GetRow() << " " << chosen->GetColumn() << endl<< endl;
#endif
					board.EndOfTurn();

				}
		}
		else
			//if square is free just checking for piece ability to move there, provided that it can, move it to square
			if (chosen->IsAbleToMove(row, col) == true)
			{
				chosen->Move(row, col);
				chosen = nullptr;
#ifdef DEBUG
				cout << "Piece Moved to : " << chosen->GetRow() << " " << chosen->GetColumn();
				cout << ", End Of Turn" << endl;
#endif
				board.EndOfTurn();
			}
	}
#ifdef DEBUG
	std::cout << "\t END OF OPERATIONS " << endl;
#endif
}