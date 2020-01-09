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
        const std::string Family,
        const std::string effectiveFamily,
        const std::string WeakFamily,
        int Health,
        int MaxHealth,
        int Attack,
        int Defense
    );
    ~Trainer(){}

    std::string &GetName();
    std::string &GetMove();
    std::string &GetType();
    std::string &GetEffectiveType();
    std::string &GetWeakType();

    int GetMaxHealth() const;
    int GetHealth() const;
    int GetAttack() const;
    int GetDefense() const;

    bool Fainted() const;

    void ReduceHealth(int Damage);
    void UsePotion();
    void NegativeHealth();
    void ReduceAttack(int Reduce);
    void ReduceDefense(int Reduce);

private:
    std::string PokemonName;
    std::string PokemonMove;
    std::string PokemonFamily;
    std::string PokemonEffective;
    std::string PokemonWeak;
    int  PokemonHealth;
    int  PokemonMaxHealth;
    int  PokemonAttack;
    int PokemonDefense;

};


