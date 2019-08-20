#pragma once
 
#include <iostream>
#include <vector>
namespace nQueens
{
	class NQueensProblem
	{
		std::vector<std::vector<int>> chessTable;
		int numOfQueens = 0;

	public:
		NQueensProblem(int _numOfQueens) 
			: numOfQueens(_numOfQueens)
		{
			// create 2D array with as many rows and colums as the number of queens
			chessTable.resize(numOfQueens);
			for (auto &chessRow : chessTable)
			{
				chessRow.resize(numOfQueens);
			}
		}
		void solve()
		{
			// solve the problem starting with the first colum (0)
			if (setQueens(0))
			{
				printQueens();
			}
			else
			{
				std::cout << "There is no solution...\n" << std::endl;
			}
		}
	private:
		bool setQueens(int colIndex)
		{
			// if we have considered as many queens as the number of rows/cols then we done!
			// so we have found valid places for all the queens
			if (colIndex == numOfQueens)
			{
				return true;
			}

			// consider all the rows in a single col to check where to put the queen
			for (int rowIndex = 0; rowIndex < numOfQueens; ++rowIndex)
			{
				// check if the given location is valid (queen cannot be attacked by other queens)
				if (isPlaceValid(rowIndex, colIndex)) 
				{
					// valid place so put a queen to this location
					chessTable[rowIndex][colIndex] = 1;

					// check the next queen (next colum) (every col has one queen)
					// we manage to put a queen in the next col -> return ture
					if (setQueens(colIndex + 1))
					{
						return true;
					}

					// we define to put a given queen in a given col: BACKTRACKING !!!
					// 1: denotes a queen and 0: is an empty space so we re-initialize the location
					// what to do? keep iterating and consider the next row (maybe it's a valid place of the queen)
					chessTable[rowIndex][colIndex] = 0;
				}
			}

			// we have considered all the rows without any result which means there is no solution
			// we are not able to put the queens such that they cannot attack each other
			// so we backtrack -> maybe we have to change the position of previous queens
			return false;
		}

		bool isPlaceValid(int rowIndex, int colIndex) const
		{
			// there cannot be another queen in the same row
			for (int i = 0 ; i < colIndex; i++)
			{
				if (chessTable[rowIndex][i] == 1)
				{
					return false;
				}
			}

			// there is a queen in the diagonal
			// (top left to bottom right direction)
			for (int i = rowIndex, j = colIndex; i >= 0 && j >= 0; i--, j--)
			{
				if (chessTable[i][j] == 1)
				{
					return false;
				}
			}
			// (top right to bottom left direction)
			for (int i = rowIndex, j = colIndex; i < numOfQueens && j >= 0; i++, j--)
			{
				if (chessTable[i][j] == 1)
				{
					return false;
				}
			}

			return true;
		}

		void printQueens() const
		{
			// there is a queen where the table contains a 1 else there is no queens (0 value)
			// represents the queens and - is an empty state
			for (size_t i = 0; i < chessTable.size(); i++)
			{
				for (size_t j = 0; j < chessTable.size(); j++)
				{
					if (chessTable[i][j] == 1)
					{
						std::cout << " * ";
					}
					else
					{
						std::cout << " - ";
					}
				}
				std::cout << "\n";
			}
		}
	};
}

// [sample.cpp]
// nQueens::NQueensProblem problem(4);
// problem.solve();