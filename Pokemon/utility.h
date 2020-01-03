#pragma once
#ifndef UTILITY_H
#define UTILITY_H

class Utility
{
public:

    static bool IsChoice(const unsigned char input, const unsigned char UpperChoice);
    static bool KansBerekening(int kans);

    static int RandomNummer(int min, int max);
    static float RandomNummer(float min, float max);


};
#endif // UTILITY_H
