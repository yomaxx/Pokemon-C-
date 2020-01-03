#pragma once
#include <iostream>
#include <string>

class Trainer
{
public:

    Trainer
    (
        const std::string &name,
        const std::string &Move,
        char Family,
        int Health,
        int MaxHealth,
        int Attack,
        int Defense
    );
    ~Trainer(){}

    std::string &GetName();
    std::string &GetMove();

    int GetMaxHealth() const;
    int GetHealth() const;
    int GetAttack() const;
    int GetDefense() const;

    char GetType() const;

    bool Fainted() const;

    void ReduceHealth(int Damage);
    void ReduceAttack(int Reduce);
    void ReduceDefense(int Reduce);

private:
    std::string PokemonName;
    std::string PokemonMove;
    char PokemonFamily;
    int  PokemonHealth;
    int  PokemonMaxHealth;
    int  PokemonAttack;
    int PokemonDefense;

};


