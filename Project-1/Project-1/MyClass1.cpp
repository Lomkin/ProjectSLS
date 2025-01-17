#include"MyClass1.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cctype>


using namespace std;

MyClass1::MyClass1()

{
	cout << "CONSTRUCTOR:Run!" << endl;

  };

MyClass1::~MyClass1()
{
	cout << "DESTRUCTOR:Memory has been cleaned. Good bye!" << endl;
}


//////////////********************garbage collector*******************////////////////
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


////////////////////////////////////////////////////////////////////////////////////////////
/////////////���������� �������///////////////////////////////////////////
//////////////////////������ ���������� �������/////////////////////////////////////////////
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
/////////////���������� �������///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
inline void  MyClass1::fnFor(int iArr[], const int size)

{
    for (int i = 0; i < size; i++)
    {

        cout << "Massiv i \t" << iArr[i] << endl;
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////���������� �������///////////////////////////////////////////
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
    cout << "���������� ���� � ������� \t" << iMinValue << endl;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////�������� ������ ����������////////////////////////////////////
int  MyClass1::Foo(int myFact)
{

    if (myFact == 1)
        return 1;
    if (myFact == 0)
        return 0;


    return myFact * Foo(myFact - 1);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////������������ ��������� ������///////////////////////////////////
void MyClass1::ExArr()
{
    int num=0;

    int* ptrArr = new int[num];




    //////
    //////
    //////


    

    delete[] ptrArr;

}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////������ ��������� �� ���� ( ������� ���������)/////////////////
void MyClass1::pArr(int num)
{

    // ������ �������
    cout << "Enter integer value: ";
    cin >> num; // ��������� �� ������������ ������� �������

    int* p_darr = new int[num]; // ��������� ������ ��� �������
    for (int i = 0; i < num; i++) {
        // ���������� ������� � ����� �������� ��� ���������
        p_darr[i] = i;
        cout << "Value of " << i << " element is " << p_darr[i] << endl;

    }

    delete[] p_darr; // ������� ������



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
/////////////����������� ���������
void MyClass1::GameStats()
{
    typedef unsigned short int ushort;//������� ����������� �������� ���
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

   



    score = 42342345;

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
//�������� �����
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
    string theWord = WORDS[secretWords][WORD];//�����
    string theHint = WORDS[secretWords][HINT];//���������

    string jumble = theWord;// ������� �����
    int length = jumble.size();//��������� �����������
    
    for (int i = 0; i < length; ++i)///������������ ����� � �����
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

    //���� ����� ������ ���� ����� �� �������� �����
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
///////������ � STL ����������� � �������  vector////////////////
void MyClass1::GameHero_is_inventory_2_0()
{
    vector<string> inventory;

    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    /*-------------------------------------------------------*/
    cout<<"You have "<< inventory.size()<< "items.\n";
    /*-------------------------------------------------------*/
//����� �������
    cout << "\nYour items:\n";
        for (int i = 0; i < inventory.size(); ++i)
    {
        cout <<"Number of massiv:----> " <<inventory[i] << endl;
    }
    /*-------------------------------------------------------*/
    cout << "\nYou trade your sword for a battle axe.";
    inventory[0] = "battle axe";
    cout << "\nYour items:\n";

    //����� �������
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
///////STL ����������,vector, ������������� ����������� //////////
void MyClass1::GameHero_is_inventory_3_0()
{
   
    vector<string> inventory;
    //����������� �����������
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
 ///��� ������� ���������� 
 ///(*myIterator).size()(������ ������������ � ����� ����� ������ ��
 /////myIterator->size() �������� '->'   ������������ ���� �������� � ��������� 
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
/////////////������� ��������////////////////////////////////
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

    cout << "\n\n\n++++++++++Fining a score.++++++++++++\n";
    int score;

    cout << "\n Enter a score to find: ";
    cin >> score;
    iter = find(VectorScores.begin(), VectorScores.end(), score);

    if (iter != VectorScores.end())
    {

        cout << "Score found. \n";
        cout << "+++++ '"<<*iter <<"' +++++"<< endl;

    }
    else
    {
        cout << "\nScore not found. \n";
    }


    cout << "\n++++++++++Randomizing scores.++++++++++++++++\n";


    srand(time(NULL));
    random_shuffle(VectorScores.begin(), VectorScores.end() );
    cout << "\n High Sores: \n";
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


///////////////////////////////////////////////++++++++++++++++++++++++++++++++++++++���������� ������+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++/////////////////////////////////////////////


void MyClass1::GameSnakeMainFun()
{





}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////���� ������� �����/////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyClass1::GameHangman()
{
    const int MAX_WRONG = 10;//������������ ���������� ������

    vector<string> VectWords; //������ ���� ��� �����������

    vector<string>::const_iterator iter;// ������������� ���������

    string StopEnter;//���������� ��� ������ ����� ���� ��� �������

 //���������� ������� �������� ���� ��� ����������� 
    string EntrWord;

    do
    {

        cout << "\n+++++++++Setting for new game+++++++++++++++++++\n ";
        cout << "\n*****Enter new word for puzzel: ";

        cin >> EntrWord;

        //�������� ����� � ������� �������
        int lengthStr = EntrWord.size();

        for (int i = 0; i < lengthStr; i++)
        {
            EntrWord[i] = toupper(EntrWord[i]);
        }
        

        VectWords.push_back(EntrWord);//����� � ������


        cout << "\n \n Do you want enter word? (Y/N) \n ";
        cin >> StopEnter;

    } while ("N"!=StopEnter and "n" != StopEnter);
   
    ////���������� ������ ���� ��� ����������� 
    for (iter = VectWords.begin(); iter != VectWords.end(); ++iter)

    {
        cout <<"\n----' "<< *iter <<" '-----"<< endl;
    }
//***********************************************************************
    ///����� �����
    srand(time(NULL));

    random_shuffle(VectWords.begin(), VectWords.end());//����������� ������������������ ���� � ��������� ������� 
    cout << "\n\n\n\n+++Randomized list words+++:\n" << endl;

        ////���������� ������ ���� ��� ����������� 
    for (iter = VectWords.begin(); iter != VectWords.end(); ++iter)

    {
        cout << "\n----' " << *iter << " '-----" << endl;
    }
    
    const string THE_WORD = VectWords[0];//����� ������� ����� ���������� ������� ������� �������

    int CurrWrong = 0;/// ��� ��� ������

    string PartWord(THE_WORD.size(), '-');//����� ����� �������� �� ������ ������

    string LetterWord = "";//��� ���������� �����


    cout << "\n--------Welcome to Hangman. Good luck!!!-----------" << endl;


    while ((CurrWrong<MAX_WRONG)&&(PartWord != THE_WORD))
     

    {

        cout<<"\n --You have (wrongs) ->   '"<< (MAX_WRONG - CurrWrong)<< "'  incorrect guesses left.\n";

        cout << "\n ---You have used the following letters:  " << LetterWord << endl;

        cout << "\n ----So far. The word is:   " << PartWord << endl;

        char guess;

        cout << "\n\nEnter your guess: ";

        cin >> guess;

        guess = toupper(guess); //������� � ������� ������� �� �� ���� ��� ����� ��������� � ������� ��������

        while (LetterWord.find(guess)!=string::npos) //find ������ ������ � ����� LetterWord �� �� ��������� 'nops' � while ���������
        {


            cout << "\nYou have already guessed  '" << guess << "' " << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);

        }
        LetterWord += guess;

        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That is right! " << guess << "is in the word. \n";
            //�������� ���������� PartWord ������� � ��� ����� ��������� �����

            for (int i = 0; i < THE_WORD.length(); i++)
            {
                if (THE_WORD[i] == guess)
                {
                    PartWord[i] = guess;
                }
            }
        }

        else
        {
            cout << "Sorry.  '"<<guess<<"' is not in the word.\n";
            ++CurrWrong;
        }      
    }


    if (CurrWrong==MAX_WRONG)

    {
        cout << "\n You have been hange!\n";
    }

    else

    {
        cout << "\nYou guessed it!";
    }

    cout << "\n+++++++++++++++++The word was----->: " << THE_WORD << endl;


}


//////////////////////////////������ ������/////////////////////////////////////////////////////////////////////


void MyClass1::Referencing()
{
    int entr{0};
    int Myscore{ 1000 };
    int& ExReference = Myscore;//������ ������
    cout << "\n*****My_Score_is: "<< Myscore <<endl;
    cout << "\n*****My_Reference_is: " << ExReference << endl;
    ///  
    cout << "\n\n\n\n*********Adding_500_to_My_Score************" << endl;
    cin >> entr;
    Myscore += entr;

    ////
    cout << "\n+++++>My_Score_is: " << Myscore << endl;
    cout << "\n\n\n\n------>My_Reference_is: " << ExReference << endl;


    cout << "\n\n\n\n*****************Adding_500_to_My_Reference**************" << endl;
    cin >> entr;
    ExReference += entr;


    ////
    cout << "\n+++++>My_Score_is: " << Myscore << endl;
    cout << "\n\n\n\n------>My_Reference_is: " << ExReference << endl;


}
///////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////������ //////////////////
void MyClass1::badSwap(int x ,int y)
{

    x = 9999;
    y = 11111111;
}

void MyClass1::goodSwap(int& x,int& y)
{

    x = 9999;
    y = 11111111;


}

////////////////////////////////������ //////////////////////////////////////////////////////
void MyClass1::SwapReferece()
{
    int MyScore = 150;
    int YourScore = 1500;
    cout << "******Original var*********" << endl;
//////////
    cout << ".....\nMyScore var:   " << MyScore << endl;
    cout << ".....\nYourScore var:   " << YourScore << endl;
///////////////
    cout << "\n******Call fn badSwap*********" << endl;
    badSwap(MyScore, YourScore);
    cout << ".....\nMyScore var:   " << MyScore << endl;
    cout << ".....\nYourScore var:   " << YourScore << endl;
//////////////

    cout << "\n******Call fn goodSwap*********" << endl;
    goodSwap(MyScore, YourScore);
    cout << ".....\nMyScore var:   " << MyScore << endl;
    cout << ".....\nYourScore var:   " << YourScore << endl;


    


}
////////////////////////////////////////////////////////////////////////////////////////////////////

/////////���������� ������ ������������ ������ �� �� ���� ��� ��������� ��� �� ������� � ��������� � �������� ��������

void MyClass1::DisplayVectRef(const vector<string>& ConstVectRef)

{
    
    cout<< "+++++Your items++++ : \n";

    for (vector<string>::const_iterator iter = ConstVectRef.begin(); iter!= ConstVectRef.end(); ++iter)
    {
        cout << "Look itertor point to var:" << "\t*iter"<<*iter << endl;
    }

   
}

void MyClass1::InventoryDisplayer()
{

    vector<string> Myinventiry;

    Myinventiry.push_back( "IN1" );

    Myinventiry.push_back( "IN2" );

    Myinventiry.push_back( "IN3");

    DisplayVectRef( Myinventiry );

  
}


///////////////////////////////������ �� ������������ ���������� ��������/////////////////////////////////////////////////////////////////////////////////////
string& MyClass1::ReffToElement(vector<string>& VectReff,int i)//������ �� � ������� ����� ���������� ������� ����� �������� � ����� ������������

{


    //���������� i-� �������� �������
    return VectReff[i];


}


void MyClass1::InventoryReferencer()
{


    vector<string>::const_iterator iter;

    vector<string> Myinventiry;

    string EntrWord;
        
    string StopEnter;

    int i = 0;


   //�������� ������ Myinventiry 
    do
    {

        cout << "\n+++++++++Setting for new game+++++++++++++++++++\n ";
        cout << "\n*****Enter new word for puzzel: ";

        cin >> EntrWord;

        //�������� ����� � ������� �������
        int lengthStr = EntrWord.size();

        for (int i = 0; i < lengthStr; i++)
        {
            EntrWord[i] = toupper(EntrWord[i]);
        }


        Myinventiry.push_back(EntrWord);//����� � ������


        cout << "\n \n Do you want enter word? (Y/N) \n ";
        cin >> StopEnter;

    } while ("N" != StopEnter and "n" != StopEnter);
    

    ////���������� ������ ���� ��� ����������� 
    for (iter = Myinventiry.begin(); iter != Myinventiry.end(); ++iter)

    {
        cout << "\n----' " << *iter << " '-----" << endl;
    }
    //***********************************************************************




    ///������� ���������� ������ ������� �������

    cout << "\n\n****Sending the returned reference to cout: " << endl;
    cout << "Enter position: ";
    cin >> i;
    cout << "\ni-MyInventory:" << ReffToElement(Myinventiry, i) << endl;


    //��� ������� ������ ������������ ������ ������ ������ -��� ������������� ������� ������������
    cout << "\n\n******(string& RefStringTemp = ReffToElement(Myinventiry, i);)Assigning the returned reference to another reference****** "<<endl;
    string& RefStringTemp = ReffToElement(Myinventiry, i);
    cout << "\n\n******View new temp var refference:  " << RefStringTemp << endl;

    //������� ��������� ������ -��� ��������� ������� ������������
    cout << "\n\n******(string RefStringTemp2 = ReffToElement(Myinventiry, i);)Assigning the returned reference to string object****** " << endl;
    string RefStringTemp2 = ReffToElement(Myinventiry, i);
    cout << "\n\n******View new temp var refference:  " << RefStringTemp << endl;



    //��������� ���������� ������� ����������� ������������ ������
    cout << "\n\n******(string RefStringTemp2 = ReffToElement(Myinventiry, i);)Assigning the returned reference to string object****** " << endl;
    RefStringTemp="++ZiZiTop++ ";
    cout << "\n\n\n******NEW var in object ReffToElement():  " << Myinventiry[i] << endl;

}


//////�������� ������////////////////
/////////////////////��������� ������ � ���������� ������////////////////////




