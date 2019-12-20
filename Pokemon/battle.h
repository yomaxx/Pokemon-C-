#pragma once
#ifndef BATTLE_H
#define BATTLE_H
#include <Player.h>


class Battle
{
public:
    static void PokemonBattle(Player p, Trainer t);

    void PlayerAttacks(Player p, Trainer t);
    void TrainerAttacks(Player p, Trainer t);

private:
};
#endif // BATTLE_H
