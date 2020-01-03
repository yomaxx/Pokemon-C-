#pragma once
#include <string>
#include <iostream>
#include <map>
#include <Trainer.h>


class Pokemon : public Trainer
{
public:

    struct PokemonData
    {
      std::string name;
      std::string Move;
      const char Family;
      int Health;
      int MaxHealth;
      int attack;
      int defense;
    };
    enum PokemonType
    {
        Bulbasaur = 0,
        Charmander,
        Squirtle,
        Bart,
        AMOUNT_OF_TYPES     //elke enum krijgt een nummer, dus als je deze oproept weet je hoeveel in dit enum zitten
    };

    static const PokemonData& getPokemonData( enum PokemonType type );

    static Pokemon * ChoosePokemon(int Choice);
    static Pokemon * ChooseRandomPokemon();

    //Pokemon(const std::string &name) : name(name) {}
    Pokemon (PokemonType);

    ~Pokemon() {}

private:
    //static std::map<Type,PokemonData> lookup;
    static const PokemonData lookup[AMOUNT_OF_TYPES];
    const std::string name;

    PokemonType pokemontype;

protected:

    int Health;
};
