#include <Pokemon.h>
#include <battle.h>
#include <PokemonType.h>

using namespace std;

const Pokemon::PokemonData Pokemon::lookup[AMOUNT_OF_TYPES] = {
    {"Bulbasaur",Pokemon::GRASS,46,22,26},      //Health, attack, defense
    {"Charmander",Pokemon::FIRE,49,23,22},
    {"Squirtle",Pokemon::WATER,52,18,26},
    {"Bart",Pokemon::TEACHER,150,5,8}
};

Pokemon Pokemon::ChooseRandomPokemon
{

};

const Pokemon::PokemonData & Pokemon::getPokemonData( Pokemon::Type type )
{
    //if( type >= AMOUNT_OF_TYPES )
    return lookup[type];
}
