#include <utility.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>

//stuurt true terug als de input juist is (kleine als grote letter)
//Zet de hoofdleter om naar kleine letter als deze niet klein ingegeven is
bool Utility::IsChoice(const unsigned  char input, const unsigned char UpperChoice)
{
    return (input == UpperChoice || input == static_cast<char>(tolower(UpperChoice)));
}

//Geeft een random nummer tussen de meegegeven min & max waarde
bool Utility::RandomNummer(int min, int max)
{
    static const double Number = 1.0 / (static_cast<double> (RAND_MAX) + 1.0);

    return static_cast<int>(rand() * Number * (max - min + 1) + min);
}

//Kijkt of de waarde in kans grotr of gelijk is aan het random nummer
bool Utility::KansBerekening(int kans)
{
    int test = RandomNummer(1,100);
    std::cout << test;
    return (RandomNummer(1, 100) <= kans);
}


