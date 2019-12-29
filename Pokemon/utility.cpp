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

//Kijkt of de waarde in kans grotr of gelijk is aan het random nummer
bool Utility::KansBerekening(int kans)
{
    int test = RandomNummer(1, 100);
    return (kans <= test);
}

//Geeft een random nummer tussen de meegegeven min & max waarde in int
int Utility::RandomNummer(int min, int max)
{
    int num = min + rand() % max;
    return num;
}

//Geeft een random nummer tussen de meegegeven min & max waarde in float
float Utility::RandomNummer(float min, float max)
{
    float num = min + (float(rand())) / max;
    return num;
}

