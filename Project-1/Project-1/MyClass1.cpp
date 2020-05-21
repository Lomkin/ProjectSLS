#include"MyClass1.h"
#include <iostream>
#include<string>
#include <ctime>

using namespace std;

MyClass1::MyClass1()

{
	cout << "Consturctor" << endl;

  };

MyClass1::~MyClass1()
{
	cout << "Memory has been cleaned. Good bye." << endl;
}

void MyClass1::pArr(int num)
{

     // размер массива
    cout << "Enter integer value: ";
    cin >> num; // получение от пользовател€ размера массива

    int* p_darr = new int[num]; // ¬ыделение пам€ти дл€ массива
    for (int i = 0; i < num; i++) {
        // «аполнение массива и вывод значений его элементов
        p_darr[i] = i;
        cout << "Value of " << i << " element is " << p_darr[i] << endl;

    }

    delete[] p_darr; // очистка пам€ти



};

void MyClass1::ExGeme()
{
    srand(time(NULL));
    int secretNumber = rand() % 100 + 1;
    int guess = 0;
    int tries = 0;
    cout << "\tWelcome to Guess My Number\n\n";
    do {
        cout<<"Enter a guess:\t";
        cin >> guess;
        ++tries;
        if (guess > secretNumber)
        {
            cout << "Too high!\n\n";
        }
        else if (guess < secretNumber)
        {
            cout << "Too low!\n\n";
        }
        else

        {
            cout << "\nThat's it! You it in\t"<< tries <<"\nguess!\n";
        }

    } while (guess != secretNumber);




    for (size_t i = 0; i < length; i++)
    {

    }

}
void MyClass1::ExGame_2()
{






}
