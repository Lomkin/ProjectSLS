#ifndef MYGAMEXO_H
#define MYGAMEXO_H

// !
/* Защита от двойного подключения заголовочного файла */

#include<string>
#include <iostream>
#include<vector>

using namespace std;

//глобальные константы константы
const char X = 'X';///отображение крестика
const char O = 'O';///отображение нолика
const char EMPTY = ' ';///пустая клетка
const char TIE = 'T';///ничья
const char NO_ONE = 'N';///в игре пока никто не победил

const int NUM_SQUARES = 3;//Определяет размерность поля



class xoGame
{



	xoGame()

	{
		cout << "+++++Constructor run!++++" << endl;
	}

	~xoGame()
	{
		cout << "++++++Constructor end!++++++" << endl;
	}



	void MainFn();




public:

private:

	void insructions();

	char askYesNo(string question);

	int askNumber(string question, int high, int low = 0);

	char humanPiece();

	char opponent(char piece);

	void dispayBoard(const vector<vector<char>>& board);

	char winner(const vector<vector<char>>& board);

	bool isLegal(const vector<vector<char>>& board, int move);

	int humanMove(const vector<vector<char>>& board, char human);

	int computerMove(const vector<vector<char>>& board, char computer);

	void announceWinner(char winner, char computer, char human);


protected:






};



#endif