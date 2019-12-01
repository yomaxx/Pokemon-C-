#pragma once
#include <string>
#include <iostream>
#include <map>

class Pokemon
{
public:

    enum Family
    {
        GRASS,
        FIRE,
        WATER,
        TEACHER
    };
    struct PokemonData
    {
      std::string name;
      enum Family family;
      int MaxHealth;
      int attack;
      int defense;
    };
    enum Type
    {
        Bulbasaur = 0,
        Charmander,
        Squirtle,
        Bart,
        AMOUNT_OF_TYPES     //elke enum krijgt een nummer, dus als je deze oproept weet je hoeveel in dit enum zitten
    };

    static const PokemonData& getPokemonData( enum Type type );

    static Pokemon ChooseRandomPokemon;

    Pokemon();
    ~Pokemon();

private:
    //static std::map<Type,PokemonData> lookup;
    static const PokemonData lookup[AMOUNT_OF_TYPES];

};
