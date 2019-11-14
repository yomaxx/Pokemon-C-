#ifndef POKEMON_H
#define POKEMON_H
#include <Trainer.h>

class Pokemon
{
public:

    struct PokemonData
    {
      char name;
      char type;
      int Health;
      int MaxHealth;
      int attack;
      int defense;
    };

    static Pokemon ChooseRandomPokemon;

private:
    


};
        


#endif // POKEMON_H
