// TheoryDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Person.h"
#include "DAEStudent.h"
#include <iostream>


int main()
{

    Person* pPerson{ new Person{"Dan", "Ackroyd"} };
    pPerson->Identify();
    delete pPerson;

    std::cout << std::endl;

    DAEStudent* pStudent{ new DAEStudent{"Roca", "Alejandro", DAEStudent::Major::GD} };
    pStudent->Identify();   // Public inheritance --> All public methods remain public
    delete pStudent;
}
