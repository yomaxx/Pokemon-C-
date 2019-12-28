#pragma once
#ifndef UTILITY_H
#define UTILITY_H

class Utility
{
public:
static bool IsChoice(const unsigned char input, const unsigned char UpperChoice);

static bool RandomNummer(int min, int max);

static bool KansBerekening(int kans);
};
#endif // UTILITY_H
