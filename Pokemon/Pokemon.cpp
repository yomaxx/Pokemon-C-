#include <Pokemon.h>
#include <battle.h>
#include <PokemonType.h>
#include <utility.h>

using namespace std;

const Pokemon::PokemonData Pokemon::lookup[AMOUNT_OF_TYPES] = {
    {"Bulbasaur",Pokemon::GRASS,46,22,26},      //Health, attack, defense
    {"Charmander",Pokemon::FIRE,49,23,22},
    {"Squirtle",Pokemon::WATER,52,18,26}
};

//The player can choose a pokemon
Pokemon * Pokemon::ChoosePokemon(std::string)
{
    return new Pokemon("Bulbasaur");
}

//the trainer randomly gets a pokemon
Pokemon * Pokemon::ChooseRandomPokemon()
{
    int num;
    num = Utility::RandomNummer(Bulbasaur,Squirtle);
    //return new Pokemon(static_cast<PokemonType>(num));
    return new Pokemon("Charmander");
}

const Pokemon::PokemonData & Pokemon::getPokemonData( Pokemon::PokemonType type )
{
    //if( type >= AMOUNT_OF_TYPES )
    return lookup[type];
}

bool Pokemon::Fainted(){return (Health < 0);}
