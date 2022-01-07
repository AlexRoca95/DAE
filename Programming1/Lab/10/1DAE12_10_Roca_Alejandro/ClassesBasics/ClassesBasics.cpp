// 1DAE12 - Roca, Alejandro

#include "pch.h"
#include "Square.h"
#include "Time.h"
#include <iostream>

void DoSquareTests();
void TestSquare(Square* pSquare);
void DoTimeTests();

int main()
{
    DoSquareTests();
    DoTimeTests();

}

void DoSquareTests()
{
    // Object of the class in the heap
    Square* p_Sq3 = new Square{10.f};
    Square* p_Sq4 = new Square{ 10.f, 20.f, 30.f };
   

    p_Sq4->Print();         // Print info from the square
    p_Sq4->Translate(10.f, 20.f);
    p_Sq4->SetSize(20.f);
    p_Sq4->Print();


    TestSquare(p_Sq4);

    delete p_Sq3;       // Deleting object from the heap
    p_Sq3 = nullptr;    // Point to nullptr because the old address doesn't contain anything
    delete p_Sq4;
    p_Sq4 = nullptr;

    
}

void TestSquare(Square* pSquare)
{

}


void DoTimeTests()
{
   
    Time* t = new Time{ 32.f, 23.f, 2.f };

    t->Print();

}


