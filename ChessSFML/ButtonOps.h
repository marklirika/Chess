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
	// ������� ������ �� ������� ���������� ����
	int row = MousePosition.x / board.GetWidth();
	int col = MousePosition.y / board.GetHeight();
	cout << "mouse pos x : " << row;
	cout << "  mouse pos y : " << col << endl;

	// ���� ���������� ����� ������������� ����������� ������ �� ������ �������� ��� ������
	int index = -1;
	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces[i]->GetRow() == row && pieces[i]->GetColumn() == col)
			index = i;
	}
	if (chosen == NULL)
	{
		// ���� ������ ������ � ��� ���� ������� ������ �� ������� �� ������ �� ������
		if (index == -1)
			cout << "Index : " << index << "return accomplished" << endl;
		else
		{
			// ���� ������ �� �������,�� ������ �� �������� ���������� � ����� �������� ����
			if (pieces[index]->IsWhite() == board.GetTurn())
			chosen = pieces[index];
			cout << "Chosen Piece : " << index << endl;
		}
	}
	else
	{
		cout << "Piece is Already Chosen " << endl << "Chosen row is : " << chosen->GetRow() << " Col is : " << chosen->GetColumn() << endl;
		
		// ��������� ������ �� ������ ����� index.

		if (index != -1)
		{
			//���� ������ �� ������, � �� � ����� ������,�� ��������� ������ �� ��� �����.
			if (pieces[index]->IsWhite() == chosen->IsWhite())
			{
				// ���� �� ����� ���������� ������������ ������ � �������
				cout << "Similar Color of Pieces" << chosen->GetColumn();
				chosen = pieces[index];
				cout << "Chosen Changed" << endl;
			}
			else
				// ���� ���� �� ����������,�� ��������� ����� �� ������ ������� �� ������
				if (chosen->IsAbleToMove(row, col) == true)
				{
					cout << "Color of Pieces is defferent." << endl;
					//���� ������ ������ ������� ��� ���������,������ ��������� ������.
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
			//���� ������ ������, ��������� ����� �� ���� ������� ������,���� ��,������� ��,���� ��� ������ �� ������
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