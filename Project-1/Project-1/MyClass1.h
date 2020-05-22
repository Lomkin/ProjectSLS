#ifndef MYCLASS_H
#define MYCLASS_H

 // !
/* Защита от двойного подключения заголовочного файла */

#include<string>
#include <iostream>


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
private:
	void pArr(int num);
	
protected:
	;
};

#endif




