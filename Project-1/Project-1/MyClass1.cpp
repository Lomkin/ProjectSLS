#include"MyClass1.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

MyClass1::MyClass1()

{
	cout << "Consturctor" << endl;

  };

MyClass1::~MyClass1()
{
	cout << "Memory has been cleaned. Good bye." << endl;
}

/////////***********************garbage collector************************////////////////
/*


#define STACK_MAX_SIZE 256
#define IGCT 8

typedef enum {
    INT,
    TWIN
} ObjectType;

typedef struct sObject {
    ObjectType type;
    unsigned char marked;

    struct sObject* next;

    union {
        int value;

        struct {
            struct sObject* head;
            struct sObject* tail;
        };
    };
} Object;

typedef struct {
    Object* stack[STACK_MAX_SIZE];
    int stackSize;

    Object* firstObject;

    int numObjects;

    int maxObjects;
} VM;


void push(VM* vm, Object* value) {
    vm->stack[vm->stackSize++] = value;
}


Object* pop(VM* vm) {
    return vm->stack[--vm->stackSize];
}



VM* newVM() {
    VM* vm = (VM*)malloc(sizeof(VM));
    vm->stackSize = 0;
    vm->firstObject = NULL;
    vm->numObjects = 0;
    vm->maxObjects = IGCT;
    return vm;
}


void mark(Object* object) {
    if (object->marked) return;

    object->marked = 1;

    if (object->type == TWIN) {
        mark(object->head);
        mark(object->tail);
    }
}

void markAll(VM* vm)
{
    for (int i = 0; i < vm->stackSize; i++) {
        mark(vm->stack[i]);
    }
}

void markspeep(VM* vm)
{
    Object** object = &vm->firstObject;
    while (*object) {
        if (!(*object)->marked) {
            Object* unreached = *object;

            *object = unreached->next;
            free(unreached);

            vm->numObjects--;
        }
        else {
            (*object)->marked = 0;
            object = &(*object)->next;
        }
    }
}


void gc(VM* vm) {
    int numObjects = vm->numObjects;

    markAll(vm);
    markspeep(vm);

    vm->maxObjects = vm->numObjects * 2;

    printf("Collected %d objects, %d left.\n", numObjects - vm->numObjects, vm->numObjects);
}

Object* newObject(VM* vm, ObjectType type) {
    if (vm->numObjects == vm->maxObjects) gc(vm);

    Object* object = (Object*)malloc(sizeof(Object));
    object->type = type;
    object->next = vm->firstObject;
    vm->firstObject = object;
    object->marked = 0;

    vm->numObjects++;

    return object;
}

void pushInt(VM* vm, int intValue) {
    Object* object = newObject(vm, INT);
    object->value = intValue;

    push(vm, object);
}

Object* pushPair(VM* vm) {
    Object* object = newObject(vm, TWIN);
    object->tail = pop(vm);
    object->head = pop(vm);

    push(vm, object);
    return object;
}

void objectPrint(Object* object) {
    switch (object->type) {
    case INT:
        printf("%d", object->value);
        break;

    case TWIN:
        printf("(");
        objectPrint(object->head);
        printf(", ");
        objectPrint(object->tail);
        printf(")");
        break;
    }
}

void freeVM(VM* vm) {
    vm->stackSize = 0;
    gc(vm);
    free(vm);
}

void first_test() {
    printf("1: Objects on the stack are preserved.\n");
    VM* vm = newVM();
    pushInt(vm, 1);
    pushInt(vm, 2);

    gc(vm);
    freeVM(vm);
}

void second_test() {
    printf("2: Unreached objects are collected.\n");
    VM* vm = newVM();
    pushInt(vm, 1);
    pushInt(vm, 2);
    pop(vm);
    pop(vm);

    gc(vm);
    freeVM(vm);
}

void third_test() {
    printf("3: Reach the nested objects.\n");
    VM* vm = newVM();
    pushInt(vm, 1);
    pushInt(vm, 2);
    pushPair(vm);
    pushInt(vm, 3);
    pushInt(vm, 4);
    pushPair(vm);
    pushPair(vm);

    gc(vm);
    freeVM(vm);
}

void another_test() {
    printf("4: Cycles.\n");
    VM* vm = newVM();
    pushInt(vm, 1);
    pushInt(vm, 2);
    Object* a = pushPair(vm);
    pushInt(vm, 3);
    pushInt(vm, 4);
    Object* b = pushPair(vm);

    a->tail = b;
    b->tail = a;

    gc(vm);
    freeVM(vm);
}

void performance() {
    printf("Performance of GC.\n");
    VM* vm = newVM();

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 20; j++) {
            pushInt(vm, i);
        }

        for (int k = 0; k < 20; k++) {
            pop(vm);
        }
    }
    freeVM(vm);
}
*/



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////-------------Шаблонные функции-----------------/////////////////////////////////////
//class  тоже самое что и typename
template<class T1, class T2>
T1  MyClass1::Summ(T1 a, T2 b)
{

    return a + b;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////-------------Шаблонные функции-----------------/////////////////////////////////////
template<class T1, class T2>
void  MyClass1::Summ(T1 a1, T2 b2)
{

    cout << a1 + b2 << endl;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////-------------Шаблонные функции-----------------/////////////////////////////////////
template<class T1, class T2>
void  MyClass1::Summ(T1 a1, T2 b2)
{

    cout << (++a1) + (++b2) << endl;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Перегрузка функции///////////////////////////////////////////
//////////////////////Рандом заполнение массива/////////////////////////////////////////////
inline void MyClass1::fnFor(bool xSts, int iArr[], const int size)
{
    for (int i = 0; i < size; )
    {

        xSts = false;
        int xRnd;

        xRnd = rand() % 1000;

        for (int j = 0; j < i; j++)
        {
            if (iArr[j] == xRnd)
            {
                xSts = true;
                break;
            }
        }

        if (!xSts)
        {
            iArr[i] = xRnd;
            i++;
        };




    }




}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Перегрузка функции///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
inline void  MyClass1::fnFor(int iArr[], const int size)

{
    for (int i = 0; i < size; i++)
    {

        cout << "Massiv i \t" << iArr[i] << endl;
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Перегрузка функции///////////////////////////////////////////
//////////////////////////////////////////////////////////////////
inline void  MyClass1::fnFor1(int iArr[], const int size)

{
    int iMinValue = iArr[0];
    for (int i = 0; i < size; i++)
    {

        if (iArr[i] < iMinValue)
        {

            iMinValue = iArr[i];

        }


    }
    cout << "Наименьшее чило в массиве \t" << iMinValue << endl;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////рекурсия расчет факториала////////////////////////////////////
int  MyClass1::Foo(int myFact)
{

    if (myFact == 1)
        return 1;
    if (myFact == 0)
        return 0;


    return myFact * Foo(myFact - 1);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////Динамичесоке выделение памяти///////////////////////////////////
void MyClass1::ExArr()
{
    int num;


    int* ptrArr = new int[num];




    //////
    //////
    //////


    

    delete[] ptrArr;

}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////пример указателя на кучу ( динамич выделение)/////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////simple calulator
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////отображение состояния
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////Работа с STL библиотекой и бъектом  vector////////////////
void MyClass1::GameHero_is_inventory_2_0()
{
    vector<string> inventory;

    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    /*-------------------------------------------------------*/
    cout<<"You have "<< inventory.size()<< "items.\n";
    /*-------------------------------------------------------*/
//вывод массива
    cout << "\nYour items:\n";
        for (int i = 0; i < inventory.size(); ++i)
    {
        cout <<"Number of massiv:----> " <<inventory[i] << endl;
    }
    /*-------------------------------------------------------*/
    cout << "\nYou trade your sword for a battle axe.";
    inventory[0] = "battle axe";
    cout << "\nYour items:\n";

    //вывод массива
    for (int i = 0; i < inventory.size(); ++i)
    {
        cout << "Number of massiv:----> "<< inventory[i] << endl;
    }  
    /*-------------------------------------------------------*/
    cout << "\nThe item name '" <<inventory[0]<<"' has";
    cout << inventory[0].size() << " letters in .\n";
    cout <<"\nYour shield is destroued in a firece battle.";
    inventory.pop_back();
    cout << "\nYour items:\n";
    for (int i = 0; i <inventory.size(); ++i)
    {
        cout << inventory[i]<<endl;
    }
    cout << "\nYou were rodded of all of your possessions by a thief";
    inventory.clear();
    if (inventory.empty())
    {
        cout << "\nYou have nothing.\n";
    }
    else
    {
        printf( "\n You nave at least one item\n");
    }


}






///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////STL библиотека,vector, использвоание контейнеров //////////
void MyClass1::GameHero_is_inventory_3_0()
{
   
    vector<string> inventory;
    //определение контейнеров
    vector<string>::iterator myIterator;
    vector<string>::const_iterator myConstIterator;

    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");




    printf("You items:\n");

    for (myConstIterator = inventory.begin(); myConstIterator != inventory.end(); ++myConstIterator)
    {


        cout<<*myConstIterator<<endl;

    }

 printf("\nYou trade your sword for a battle axe.");
 myIterator = inventory.begin();
 *myIterator = "battle axe";
 printf("Your items:\n");

 for (myConstIterator = inventory.begin(); myConstIterator != inventory.end(); ++myConstIterator)
 {


      cout << *myConstIterator << endl;

 }
 ///два способа отбражения 
 ///(*myIterator).size()(снчала разименовали а потом взяли размер эл
 /////myIterator->size() оператор '->'   применияется года работаем с указателм 
 cout << "\nThe item name '" << *myIterator << "has";
 cout << (*myIterator).size() << " letters in it.\n";

 cout << "\nThe item name '" <<*myIterator<< "has";
 cout << myIterator->size() << " letters in it.\n";



 cout << "\nYou recover a crossdw form a slain enemy.";
 inventory.insert(inventory.begin(), "crossbow");
 cout << "\nYour items: \n";

 for (myConstIterator = inventory.begin(); myConstIterator != inventory.end(); ++myConstIterator)
 {


     cout << *myConstIterator << endl;

 }



 cout << "\nYou armor is destroyed in a fiece battle.";
 inventory.erase((inventory.begin() + 2));
 printf("You items:\n");

 for (myConstIterator = inventory.begin(); myConstIterator != inventory.end(); ++myConstIterator)
 {


     cout << *myConstIterator << endl;

 }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////таблица векторов////////////////////////////////
void MyClass1::HighScores()
{
    vector<int>::const_iterator iter;
    cout << "/*******************Creatinf a list of scores******************\\n";
    vector<int> VectorScores;

    VectorScores.push_back(1500);
    VectorScores.push_back(3500);
    VectorScores.push_back(7500);
    cout << "\n\t***************High Sores******************\t\n";
    cout << "\nVIEW SCORES:";
    for (iter = VectorScores.begin(); iter != VectorScores.end(); ++iter)
    {
        cout << "_____" << *iter << "_____" << endl;
    }

    cout << "\n\n\n++++++++++Fining a score.++++++++++++";
    int score;

    cout << "\nEnter a score to find: ";
    cin >> score;
    iter = find(VectorScores.begin(), VectorScores.end(), score);

    if (iter != VectorScores.end())
    {

        cout << "Score found. \n";


    }
    else
    {
        cout << "Score not found. \n";
    }


    cout << "\++++++++++Randomizing scores.++++++++++++++++";


    srand(time(NULL));
    random_shuffle(VectorScores.begin(), VectorScores.end() );
    cout << "\High Sores: \n";
    for (iter = VectorScores.begin(); iter != VectorScores.end(); ++iter)
    {

        cout << *iter << endl;


    }

    sort(VectorScores.begin(), VectorScores.end());

    for (iter = VectorScores.begin(); iter != VectorScores.end(); ++iter)
    {

        cout << *iter << endl;


    }



}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


