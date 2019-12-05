#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <Trainer.h>

class Player : public Pokemon
{
public:
    Player(const std::string &name);

    bool Won();
    bool Fainted();
    int GetHealth() const;
    int ReduceHealth(int p_Health);
    int GetDamage() const;

protected:
    int BattlesWon;
    int p_Health;

};

#endif // PLAYER_H
