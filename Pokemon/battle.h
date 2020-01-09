#pragma once
#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include <Player.h>

class Battle
{
public:
    static bool PokemonBattle(std::string, std::string);

    static void PlayerTurn(Pokemon &p, Pokemon &t, std::string, int choice);
    static void TrainerTurn(Pokemon &p, Pokemon &t, std::string);

    static float CalDamage(float Attack, float Defense, int Power, int effect);
    static float CalEffect(std::string FamilyAttacker, std::string WeakAttacker, std::string WeakDefender, std::string FamilyDefender);

    static int choiceClear();

private:
};
#endif // BATTLE_H
