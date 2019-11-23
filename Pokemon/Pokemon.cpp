#include <Pokemon.h>
#include <battle.h>
#include <PokemonType.h>



const Pokemon::PokemonData Pokemon::lookup[AMOUNT_OF_TYPES] = {
    {"Bulbasaur",Pokemon::GRASS,26,22,26},      //Health, attack, defense
    {"Charmander",Pokemon::FIRE,29,23,22},
    {"Squirtle",Pokemon::WATER,32,18,26},
    {"Bart",Pokemon::TEACHER,120,5,8}
};

Pokemon Pokemon::ChooseRandomPokemon
{

};

const Pokemon::PokemonData & Pokemon::getPokemonData( Pokemon::Type type )
{
    //if( type >= AMOUNT_OF_TYPES )
    return lookup[type];
}
