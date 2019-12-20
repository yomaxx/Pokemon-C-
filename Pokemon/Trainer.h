#pragma once
#include <Pokemon.h>

class Trainer : public Pokemon
{
public:
    Trainer(const std::string &name);

    bool Fainted() const;



private:
    int t_Health;
};


