#ifndef MYCLASS_H
#define MYCLASS_H

 // !
/* ������ �� �������� ����������� ������������� ����� */

#include<string>
#include <iostream>
#include<vector>

using namespace std;
class MyClass1 {


public:
	MyClass1();

	~MyClass1();

	void GuessGeme();
	void ExepnsiveCalcul();
	void GameStats();
	void GameStats2_0();
	void GameStats3_0();
	void WordJumbleGame();
	void GameHero_is_inventory_2_0();
	void GameHero_is_inventory_3_0();
	void HighScores();
	void GameSnakeMainFun();
	void GameHangman();
	void Referencing();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////-------------��������� �������-----------------/////////////////////////////////////
	//class  ���� ����� ��� � typename

	template<class T1, class T2> T1  Summ(T1 a, T2 b)
	{

		return a + b;

	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////-------------��������� �������-----------------/////////////////////////////////////

	template<class T3, class T4> void Summ2(T3 a1, T4 b2)
	{

		cout << a1 + b2 << endl;

	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////-------------��������� �������-----------------/////////////////////////////////////

	template<class T5, class T6> void Summ3(T5 a1, T6 b2)
	{

		cout << (++a1) + (++b2) << endl;

	}
	///////////////////////////////////////////////////////////////////////////

	/////////////////////////���������� �������//////////////////////////////////////////////
	inline void fnFor(bool xSts, int iArr[], const int size);

	inline void fnFor(int iArr[], const int size);

	inline void fnFor1(int iArr[], const int size);


	void SwapReferece();



	void InventoryDisplayer();
	void InventoryReferencer();
private:

	void pArr(int num);
	int Foo(int myFact);
	void ExArr();

////������ � �������
	void badSwap(int x,int y);

	void goodSwap(int& x,int& y);

	void DisplayVectRef(const vector<string>& ConstVectRef);
	string& ReffToElement(vector<string>& VectReff, int i);

protected:
	;

};


#endif




