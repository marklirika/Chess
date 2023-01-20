#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "Global.h"
#include "Board.h"
#include "Piece.h"
#include "ButtonOps.h"

using namespace sf;
using namespace std;


int Pawn::ep_col = -1;
int Pawn::ep_row = -1;

bool Pawn::white_en_passant = false;
bool Pawn::black_en_passant = false;

int King::wk_row = -1;
int King::wk_col = -1;
int King::bk_row = -1;
int King::bk_col = -1;

bool King::w_check = false;
bool King::b_check = false;

int main()
{
	Board board;

	board.SetupBoard();

	RenderWindow window(VideoMode(960, 960), "Chess");
	while (window.isOpen())
	{
		Event event;
		Vector2i MousePosition;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close(); 
			if (event.type == Event::MouseButtonPressed)
				LeftButtonClick(window, MousePosition, board, global::pieces, global::chosen);
		}
		window.clear(Color(0, 0, 0));

		for (int row = 0; row < board.GetRow(); row++)
			for (int col = 0; col < 8; col++)
			{
				window.draw(board.GetRectangle(row, col));
 			}

		if(global::pieces.empty() != true)
			for (int i = 0; i < global::pieces.size(); i++)
			{
				window.draw(global::pieces[i]->GetSprite(board));
			}
		this_thread::sleep_for(30ms);
		window.display();

	}

}