#pragma once
#include <Trainer.h>

class Player : public Pokemon
{
public:
    Player(const std::string &name);

    bool Won();
    int GetHealth() const;
    int ReduceHealth(int p_Health);
    int GetDamage() const;


};
