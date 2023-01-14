#include "Global.h"

namespace global {
    vector<shared_ptr<Piece>> pieces =
    {
        make_shared<Rook>(Rook(0,0,true,false)),
        make_shared<Knight>(Knight(1,0,true)),
        make_shared<Bishop>(Bishop(2,0,true)),
        make_shared<Queen>(Queen(3,0,true)),
        make_shared<King>(King(4,0,true)),
        make_shared<Bishop>(Bishop(5,0,true)),
        make_shared<Knight>(Knight(6,0,true)),
        make_shared<Rook>(Rook(7,0,true,true)),

        make_shared<Pawn>(Pawn(0,1,true)),
        make_shared<Pawn>(Pawn(1,1,true)),
        make_shared<Pawn>(Pawn(2,1,true)),
        make_shared<Pawn>(Pawn(3,1,true)),
        make_shared<Pawn>(Pawn(4,1,true)),
        make_shared<Pawn>(Pawn(5,1,true)),
        make_shared<Pawn>(Pawn(6,1,true)),
        make_shared<Pawn>(Pawn(7,1,true)),

        make_shared<Rook>(Rook(0,7,false,false)),
        make_shared<Knight>(Knight(1,7,false)),
        make_shared<Bishop>(Bishop(2,7,false)),
        make_shared<Queen>(Queen(3,7,false)),
        make_shared<King>(King(4,7,false)),
        make_shared<Bishop>(Bishop(5,7,false)),
        make_shared<Knight>(Knight(6,7,false)),
        make_shared<Rook>(Rook(7,7,false,true)),

        make_shared<Pawn>(Pawn(0,6,false)),
        make_shared<Pawn>(Pawn(1,6,false)),
        make_shared<Pawn>(Pawn(2,6,false)),
        make_shared<Pawn>(Pawn(3,6,false)),
        make_shared<Pawn>(Pawn(4,6,false)),
        make_shared<Pawn>(Pawn(5,6,false)),
        make_shared<Pawn>(Pawn(6,6,false)),
        make_shared<Pawn>(Pawn(7,6,false)),
    };

    shared_ptr<Piece> chosen = nullptr;

    bool SquareIsFree(vector<shared_ptr<Piece>> pieces, int row, int col)
    {
        for (int i = 0; i < pieces.size(); i++)
        {
            if (pieces[i]->GetRow() == row && pieces[i]->GetColumn() == col)
                return false;
        }
        return true;
    }

	bool Castling(King* king, std::vector<std::shared_ptr<Piece>>& pieces, int row, int col)
	{
		if ((col == 0 || col == 7) && row == 6)
		{
			bool sqrfree = true;
			for (int i = row - 1; i < row + 1; i++)
				if (!global::SquareIsFree(pieces, i, col))
					sqrfree = false;
			if (sqrfree)
			{
				if (king->IsWhite())
				{
					for (auto& el : pieces)
					{
						cout << el->GetType();
						if (el->GetType() == "Rook")
						{
							if (el->IsWhite() == true && el->GetFirstMove() == true && el->GetSide() == true)
							{
								el->Move(5, 0);
								return true;
							}
						}	
					}
				}
				else
				{
					for (auto& el : pieces)
					{
						cout << el->GetType();
						if (el->GetType() == "Rook")
						{
							if (el->IsWhite() == false && el->GetFirstMove() == true && el->GetSide() == true)
							{
								el->Move(5, 7);
								return true;
							}
						}
					}
				}
			}
		}
		if (col == 0 || col == 7 && row == 2)
		{
			bool sqrfree = true;
			for (int i = col; i > col - 2; i--)
				if (!global::SquareIsFree(pieces, row, i))
					sqrfree = false;
			if (sqrfree)
			{
				if (king->IsWhite())
				{
					for (auto& el : pieces)
					{
						cout << el->GetType();
						if (el->GetType() == "Rook")
						{
							if (el->IsWhite() == true && el->GetFirstMove() == true && el->GetSide() == false)
							{
								el->Move(3, 0);
								return true;
							}
						}
					}
				}
				else
				{
					for (auto& el : pieces)
					{
						cout << el->GetType();
						if (el->GetType() == "Rook")
						{
							if (el->IsWhite() == false && el->GetFirstMove() == true && el->GetSide() == false)
							{
								el->Move(3, 7);
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}

	void Promote(vector<shared_ptr<Piece>>& pieces, int row, int col, bool isWhite)
	{
		int code;
		bool selection = true;
		cout << "Plese input a number:\n1 - Queen\n2 - Rook\n3 - Knight,\n4 - Bishop,\n 5 - Pawn\n";
		while (selection)
			cin >> code;
		switch (code)
		{
		case 1:
			pieces.push_back(make_shared<Queen>(Queen(row, col, isWhite)));
			selection = false;
			break;
		case 2:
			pieces.push_back(make_shared<Rook>(Rook(row, col, isWhite, false)));
			selection = false;
			break;
		case 3:
			pieces.push_back(make_shared<Knight>(Knight(row, col, isWhite)));
			selection = false;
			break;
		case 4:
			pieces.push_back(make_shared<Bishop>(Bishop(row, col, isWhite)));
			selection = false;
			break;
		case 5:
			selection = false;
			break;
		default:
			cout << "erorr,please enter the right number:\n1 - Queen\n2 - Rook\n3 - Knight,\n4 - Bishop,\n 5 - Pawn\n";
			break;
		}
		return;
	}
}