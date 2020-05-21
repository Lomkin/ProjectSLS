#include"MyClass1.h"
#include <iostream>
#include<string>
#include <ctime>
#include <vector>
using namespace std;

MyClass1::MyClass1()

{
	cout << "Consturctor" << endl;

  };

MyClass1::~MyClass1()
{
	cout << "Memory has been cleaned. Good bye." << endl;
}


//пример указателя
void MyClass1::pArr(int num)
{

    // размер массива
    cout << "Enter integer value: ";
    cin >> num; // получение от пользователя размера массива

    int* p_darr = new int[num]; // Выделение памяти для массива
    for (int i = 0; i < num; i++) {
        // Заполнение массива и вывод значений его элементов
        p_darr[i] = i;
        cout << "Value of " << i << " element is " << p_darr[i] << endl;

    }

    delete[] p_darr; // очистка памяти



};

//simple calulator
void MyClass1::ExepnsiveCalcul()
{
    cout << "7 + 3=" << 7 + 3 << endl;
    cout << "7 - 3=" << 7 - 3 << endl;
    cout << "7 * 3=" << 7 * 3 << endl;
    cout << "7 / 3=" << 7 / 3 << endl;
    cout << "7.0 / 3.0=" << 7.0 / 3.0 << endl;
    cout << "7 % 3=" << 7 % 3 << endl;
    cout << "7 + 3 * 5=" << 7 + 3 * 5 << endl;
    cout << "(7+3)*5=" << (7 + 3)*5 << endl;





}

///отображение состояния
void MyClass1::GameStats()
{
    typedef unsigned short int ushort;//задефил беззнаковую короткую инт
    int score{0};
    double distance{0.0};
    char playAgain{0};
    bool shieldsUp;
    short lives{0}, aliensKilled{0};

    score = 0;
    distance = 1200.76;
    playAgain = 'y';
    shieldsUp = true;
    lives = 3;
    aliensKilled = 10;

    double engineTemp = 6572.89;
    cout << "\scaore: "<<score << endl;
    cout << "distance: " << distance << endl;
    cout << "playAgain: " << playAgain << endl;
    
    if(shieldsUp)
    {
        cout << "shieldsUp!!! " << endl;
    }
    else
    {
        cout << "shieldsDown!!! " << endl;
    }
    
    cout << "lives: " << lives << endl;
    cout << "aliensKilled: " << aliensKilled << endl;
    cout << "engineTemp: " << engineTemp << endl;
    int fuel;
    cout << "\nHow much fuel? " <<  endl;
    cin >> fuel;
    cout << "fuel: "<< fuel << endl;


    ushort bonus = 10;

    cout << "\nbonus " << endl;

}


void MyClass1::GameStats2_0()
{
    unsigned int score = 5000;
    cout << "score: " << score << "\n\n\n\n\n\n" << endl;
    
    score = score + 100;

    cout << "score: " << score << "\n\n\n\n\n\n" << endl;

    score += 100;


    cout << "score: " << score << "\n\n\n\n\n\n" << endl;;

    int lives = 3;

    ++lives;

    cout << "lives: " << lives << "\n\n\n\n\n\n" << endl;


     lives = 3;

    lives++;

    cout << "lives: " << lives << "\n\n\n\n\n\n" << endl;


    lives = 3;

    int bonus =++lives*10;

    cout << "lives, bonus " << lives<<" , "<< bonus <<"\n\n\n\n\n\n"<< endl;


    lives = 3;

    bonus = lives++ * 10;

    cout << "lives, bonus " << lives << "___" << bonus << "\n\n\n\n\n\n" << endl;

   



    score = 42342345435;

    cout << "\nscore: " << score << "\n\n\n\n\n\n" << endl;

    ++score;

    cout << "\nscore: " << score << "\n\n\n\n\n\n" << endl;








}

void MyClass1::GameStats3_0()
{
    

    const  int ALIEN_POINTS = 150;
    int aliensKilled{10};
    int score = aliensKilled + ALIEN_POINTS;
    cout << "score: " << score << endl;

    enum diffeculty{NIVICE,EASY,NORMAL,HARD,UNBEATABLE};
    diffeculty MYenumDiff = EASY;

    enum shipcost { FIGHTER_COST=25,BOMBER_COST, CRUISER_COST=50};
    shipcost myShipCost = BOMBER_COST;
    cout << "\nTo upgrade my ship to a Cruiser will cost" << (CRUISER_COST - myShipCost) << "Resource Points.\n";
   







}

void MyClass1::GuessGeme()
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

  


}

void GameReady()
{
    char again{ 0 };


    do
    {

        cout << "\n**Played an exciting game**";
        cout << "\nDo you want to play again (y/n): ";
        cin >> again;
    } while (again=='y');
    cout << "\nOkey.Bye.";



}
//отгадать слово
void MyClass1::WordJumbleGame()
{

    enum fields{WORD,HINT,NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"wall"," Do you feel you are banging your head against something?"},
        {"glasses"," These might help you see the answer"},
        {"labored", "Going slowly. is it?"},
        {"persistent"," Keep at it"},
        {"jumble","it is what the game is all about"}
    
    
    };
    enum difficulty{EASY,MEDIUM,HARD,NUM_DIFF_LEVELS};
    cout << "There are " << NUM_DIFF_LEVELS <<" difficulty levels.";

    srand(time(NULL));
    int secretWords = rand() % NUM_WORDS;
    string theWord = WORDS[secretWords][WORD];//слово
    string theHint = WORDS[secretWords][HINT];//подсказка

    string jumble = theWord;// копирую слово
    int length = jumble.size();//определяю размерность
    
    for (int i = 0; i < length; ++i)///перемешиваем буквы в слове
    {
        int index1 = (rand()%length);
        int index2 = (rand() % length);

        char tempVar = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = tempVar;


    }
   
    cout << "\t\tWelcome to Word Jumble!\n\n ";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'Hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game. \n\n";
    cout<<"The jumble is: "<<jumble;
    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;
    //цикл будет работь пока игрок не отгадает слово
    while ((guess !=theWord)&&(guess!="quit"))
    {
        if (guess == "hint")
        {
            cout << theHint;
        }
        else
        {
            cout <<"Sorry. That is not it." ;
        }
        cout << "\n\nYour guess: ";
        cin >> guess;


        if (guess==theWord)
        {
            cout << "\nThat is it! You guessrd it!\n";
        }
        cout << "\nThanks for playing.\n";






    }





























}

void MyClass1::GameHero_is_inventory_2_0()
{
    vector<string> inventory;

    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    cout<<"You have "<< inventory.size()<< "items.\n";
    cout << "\nYour items:\n";
    //вывод массива
    for (int i = 0; i < inventory.size(); ++i)
    {
        cout <<"Number of massiv:----> " <<inventory[i] << endl;
    }


    cout << "\nYou trade your sword for a battle axe.";
    inventory[0] = "battle axe";
    cout << "\nYour items:\n";
    //вывод массива
    for (int i = 0; i < inventory.size(); ++i)
    {
        cout << "Number of massiv:----> "<< inventory[i] << endl;
    }
     



}