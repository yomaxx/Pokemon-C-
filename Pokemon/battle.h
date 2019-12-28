#pragma once
#ifndef BATTLE_H
#define BATTLE_H
#include <Player.h>


class Battle
{
public:
    static void PokemonBattle();

    void PlayerAttacks(Player p, Pokemon t);
    void TrainerAttacks(Player p, Pokemon t);

private:
};
#endif // BATTLE_H
