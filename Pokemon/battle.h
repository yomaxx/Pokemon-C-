#pragma once
#ifndef BATTLE_H
#define BATTLE_H
#include <player.h>


class Battle
{
public:
    void PokemonBattle(Player p);

    void PlayerAttacks(Player p, Trainer E );
    void TrainerAttacks(Player P, Trainer E);

private:
};
#endif // BATTLE_H
