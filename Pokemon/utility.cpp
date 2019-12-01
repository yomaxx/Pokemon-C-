#include <utility.h>

//stuurt true terug als de input juist is (kleine als grote letter)
inline bool IsChoice(char input, char UpperChoice)      //inline(42)
{
    return (input == UpperChoice);
}


bool RandomNummer(int min, int max)
{

}


bool KansBerkening(int kans)
{
    return (RandomNummer(1, 100) <= kans);
}


