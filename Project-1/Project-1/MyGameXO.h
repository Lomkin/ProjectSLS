#ifndef MYGAMEXO_H
#define MYGAMEXO_H

// !
/* ������ �� �������� ����������� ������������� ����� */

#include<string>
#include <iostream>
#include<vector>

using namespace std;

//���������� ��������� ���������
const char X = 'X';///����������� ��������
const char O = 'O';///����������� ������
const char EMPTY = ' ';///������ ������
const char TIE = 'T';///�����
const char NO_ONE = 'N';///� ���� ���� ����� �� �������

const int NUM_SQUARES = 3;//���������� ����������� ����



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