#pragma once
#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include <Player.h>

class Battle
{
public:
    static void PokemonBattle(std::string, std::string);

    static void PlayerTurn(Pokemon &p, Pokemon &t);
    static void TrainerTurn(Pokemon &p, Pokemon &t);

    static int CalDamage(int Attack, int Defense, int Power, int effect);
    static int CalEffect(char TypePl, char TypeTr);

private:
};
#endif // BATTLE_H
