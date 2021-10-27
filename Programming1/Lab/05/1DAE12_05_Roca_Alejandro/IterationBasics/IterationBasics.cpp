// IterationBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>       // std::string
#include <iomanip>      // std::setw
#include <math.h>
#include <iostream>

#define _USE_MATH_DEFINE

void EvenNumbers();
void ExamScores();
void RandomGuess();
void Trigonometry();
void AsciiTable();

int main()
{
    srand(unsigned int(time(nullptr)));
    EvenNumbers();
   // ExamScores();
   // RandomGuess();
    //Trigonometry();
    AsciiTable();


}


void EvenNumbers()
{
    std::cout << "-- Even Numbers --" << std::endl;
    for (int i = 2; i <= 24; i = i + 2)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    int i = 2;
    while (i <= 24)
    {
        std::cout << i << " ";
        i = i + 2;
    }

    std::cout << std::endl;

    int i2 = 2;
    do {

        std::cout << i2 << " ";
        i2 = i2 + 2;

    }while(i2<=24);
    std::cout << std::endl;
    

}

void ExamScores()
{
    int score{}, aPlus{}, a{}, b{}, c{}, d{}, e{}, fx{}, f{}, total{};

    std::string enteredScores{ "Entered Scores: "};

    std::cout << enteredScores;

    std::cout << "-- Exam Scores --" << std::endl;
    do {

        std::cout << "Score [0, 20] ? ";
        std::cin >> score;

        if (score>=0 &&  score <=20)
        {
            // Only valid scores
            total = total + score;

            switch (score) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                f++;
                break;
            case 8:
            case 9:
                fx++;
                break;
            case 10:
                e++;
                break;
            case 11:
            case 12:
                d++;
                break;
            case 13:
            case 14:
                c++;
                break;
            case 15:
                b++;
                break;
            case 16:
            case 17:
                a++;
                break;
            case 18:
            case 19:
            case 20:
                aPlus++;
                break;
            }

            enteredScores += std::to_string(score) + ", ";
        }
        else
        {
            // Wrong score
            if(score!= -1)
            std::cout << "Wrong score" << std::endl;
        }
    } while (score !=-1);       // Loop until user introduces -1

    std::cout << "A+: " << aPlus << std::endl;
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl;
    std::cout << "D: " << d << std::endl;
    std::cout << "E: " << e << std::endl;
    std::cout << "FX: " << fx << std::endl;
    std::cout << "F: " << f << std::endl;
    std::cout << "Total score: " << total << std::endl;
    std::cout << enteredScores << std::endl;


}


void RandomGuess()
{
    int number{}, guess{}, count{};
    std::cout << "-- Guess Number --" << std::endl;
    
    std::cout << "Number to guess? ";
    std::cin >> number;
    do {
        if (number>=0 && number <=RAND_MAX)
        {
            // Number between correct values

            guess = std::rand() % RAND_MAX;
            count++;
            
        }
        else
        {
            std::cout << "This is a wrong number, number to guess? ";
            std::cin >> number;
        }
    } while (guess != number);


    std::cout << "Number found after " << count << " guesses" << std::endl;
    

}

void Trigonometry()
{
    float radians{}, cosine{}, sine{};
    std::cout << "-- Trigonometry -- " << std::endl;
    std::cout << std::setw(10);
    std::cout << "Degrees";
    std::cout << std::setw(10);
    std::cout << "Radians";
    std::cout << std::setw(10);
    std::cout << "Cos";
    std::cout << std::setw(10);
    std::cout << "Sin" << std::endl;

    for (int degree = 0; degree <= 180; degree = degree + 10)
    {
        std::cout << std::setw(10);
        std::cout << degree;
        std::cout << std::setw(10);
        radians = degree * (3.141516 / 180);
        std::cout << std::setprecision(2) << radians;
        std::cout << std::setw(10);
        cosine = cos(radians);
        std::cout << std::setprecision(2) << cosine;
        std::cout << std::setw(10);
        sine = sin(radians);
        std::cout << std::setprecision(2) << sine;

        std::cout << std::endl;
    }
}

void AsciiTable()
{
    std::cout << "-- ASCII Table --" << std::endl;
    for (char letter = 'a'; int(letter) <= 'm'; letter++)
    {
        std::cout << std::setw(2) << letter;
        std::cout << std::setw(8) << int(letter);

        std::cout << std::setw(5) << char(letter + 13);
        std::cout << std::setw(8) << int(letter + 13);
        std::cout << std::endl;
    }
}


