#include"MyGameXO.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cctype>


using namespace std;

xoGame::xoGame()

{
	cout << "\n++CONSTRUCTOR:Run!+++\n" << endl;

}

xoGame::~xoGame()
{
	cout << "\n---------DESTRUCTOR:Memory has been cleaned. Good bye!---------\n" << endl;
}
////////////////////////////главная функция ////////////////////////////////////////
void xoGame::MainFn()
{
	//игра с использованием двумерного массива
	vector<vector<char>> board(NUM_SQUARES, vector<char>(NUM_SQUARES,EMPTY));//заполнил вектор размерностью 9 со значениями EMTY,т.е пустые клетки
	
	int move;

	//вывод инструкции
	insructions();
	char human = humanPiece();

	char computer = opponent(human);

	char turn = X;
	dispayBoard(board);

	while (winner(board)==NO_ONE)
	{  
		if (turn == human)
		{
			move = humanMove(board,human);
			board[move] = human;
		}

		else
		{
			move = humanMove(board, computer);
			board[move] = computer;
		}
			dispayBoard(board);
		turn = opponent(turn);
	}

	announceWinner(winner(board), computer, human);
}


///////////////////////////////функция для отображения инструкции/////////////////////////////////////
void xoGame::insructions()
{

	cout<<"\n**********Welcome to the ultimate man-machine showdown: TIC-TAC-TOE.**************** "<<endl;

	cout << "--where human brain is pit against silicon processor\n" << endl;


	cout << " Make your move known by entering a number. 0-8. The number" << endl;

	cout << "correspondes to the desired board position . as illustrated:\n\n " << endl;

	cout << "| 0 | 1 | 2 |" << endl;
	cout << "-------------" << endl;
	cout << "| 3 | 4 | 5 |" << endl;
	cout << "-------------" << endl;
	cout << "| 6 | 7 | 8 |\n\n";

	cout << "Prepare yourself. human. The battle is about to begin.\n\n";
}

//////////////////////////////функция задет вопрос пока не получит отвед Yes or NOT//////////////////////////////////////////////
char xoGame::askYesNo(string question)
{
	char response;
	do
	{
		cout << question << " (y/n):  ";
		cin >> response;

	} while (response != 'y' and response != 'n');

	return response;


}

//////////////////////////////////////////////////////////////////////////////
int xoGame::askNumber(string question, int high, int low = 0)
{

	int number;
	do
	{

		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;

	} while (number>high or number<low);

	return number;

}


////////////////////////////функция спрашивает пользователя чем играть и очередность хода следовательно///////////////////////////////////////////////////
char xoGame::humanPiece()
{
	srand(time(NULL));
	////рандомный выбор чем играть и очередность хода
	char Rnadomize = askYesNo("****Do you want randomize unit?****");
	if (Rnadomize == 'y')
	{
		
		int RandNumber = rand() % 1000;
		int StsDiv=RandNumber % 2;
		if (StsDiv==0)
		{
			return X;

		}
			else
			{
				return O;
			}

	}

	else
	{

		////ручной выбор чем играть  и очередность хода
		cout << "\n+++You may to choose whuch pieces to play++++++\n";

		char HowFirst = askYesNo("Do you require the first move?");
		if (HowFirst == 'y')

		{
			cout << "\nThen take the first move. You will need it. \n";
			return X;


		}
			else
			{
				cout << "\nYour bravery wil be your undoing... I will go first.\n";
				return O;

			}
		



	}


}

////////////////////на основании выбранной фигуре в пользователя программа выберет чем гирает противник//////////////////////////////////////////////////////////
char xoGame::opponent(char piece)
{

	if (piece==X)
	{
		return O;
	}
	else
	{
		return X;
	}
}
////////////////////////фун отображает переданное ей поле//////////////////////////////////////////////////////
void xoGame::dispayBoard(const vector<vector<char>>& board)
{
	vector<string>::const_iterator iter;



	cout << "\n\t" << "**********************GAME_BOARD*********************\n\n";

	/*
		for (iter = board.begin(); iter != board.end(); ++iter)
		{

			for (iter = board.begin(); iter != board.end(); ++iter)
			{


			}

		}



		*/
		for (int i = 0; i < board.size(); ++i)
		{

			for (int j = 0; j < board[i].size(); ++j)
			{

				cout <<"\n\t"<<board[i][j]<<" | ";


			}
			cout<<"\n\t-------------"<<endl;

		}







}

//////////////////////////////////////////////////////////////////////////////
char xoGame::winner(const vector<vector<char>>& board)
{

	if




		if (count()==)
		{


		}			



		return NO_ONE;

}

//////////////////////////////////////////////////////////////////////////////
bool xoGame::isLegal(const vector<vector<char>>& board, int move)
{



}

//////////////////////////////////////////////////////////////////////////////
int xoGame::humanMove(const vector<vector<char>>& board, char human)
{




}

//////////////////////////////////////////////////////////////////////////////
int xoGame::computerMove(const vector<vector<char>>& board, char computer)
{




}

//////////////////////////////////////////////////////////////////////////////

void xoGame::announceWinner(char winner, char computer, char human)
{





}
//////////////////////////////////////////////////////////////////////////////