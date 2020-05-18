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

	void ExGeme();
private:
	void pArr(int num);
	
protected:
	;
};

#endif




