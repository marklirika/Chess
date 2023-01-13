#pragma once
#include <vector>
#include "Piece.h"
#include "Queen.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include "King.h"
#include "Rook.h"
using namespace std;

namespace global {
	extern vector<shared_ptr<Piece>> pieces;

	extern shared_ptr<Piece> chosen;	

	extern bool SquareIsFree(vector<shared_ptr<Piece>> pieces, int row, int col);

	extern bool Castling(King* king, std::vector<std::shared_ptr<Piece>>& pieces, int row, int col);

	extern void Promote(vector<shared_ptr<Piece>>& pieces, int row, int col, bool isWhite);
}

