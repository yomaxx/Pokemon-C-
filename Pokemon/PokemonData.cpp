#include <PokemonData.h>
#include <battle.h>
#include <PokemonType.h>
#include <utility.h>
#include <Trainer.h>

using namespace std;

//lookup table with pokemon information
const Pokemon::PokemonData Pokemon::lookup[AMOUNT_OF_TYPES] = {
    //Name, move, type, EffectiveType, WeakType MaxHealth, Health, attack, defense
    {"Bulbasaur","Razor leaf","GRASS","WATER","FIRE",46,46,22,26},
    {"Charmander","Flame wheel","FIRE","GRASS","WATER",49,49,23,22},
    {"Squirtle","WaterGun","WATER","FIRE","GRASS",52,52,18,26},
    {"Pidgey","Fly","Flying","Fighting","Electric",42,42,30,25},
    {"Pikachu","Thunder","Electric","Flying","NoSpecial",48,48,24,22},
    {"Mankey","Karate chop","Fighting","Normal","Flying",50,50,25,20},
    {"Dratini","Dragon rage","Dragon","Dragon","Dragon",41,41,27,22},
    {"Snorlax","body slam","Normal","NoSpecial","Fighting",70,70,14,26},
    {"MissingNo","Mystic power","BUG","NoSpecial","NoSpecial",250,250,1,5}
};

Pokemon::Pokemon(PokemonType Type)
    :
        Trainer
        (
            lookup[Type].name,
            lookup[Type].Move,
            lookup[Type].Family,
            lookup[Type].EffectiveFamily,
            lookup[Type].WeakFamily,
            lookup[Type].Health,
            lookup[Type].MaxHealth,
            lookup[Type].attack,
            lookup[Type].defense
        ), pokemontype(Type)
{
}

//Returns the pokemon that the player has chosen
Pokemon * Pokemon::ChoosePokemon(int Choice)
{
    return new Pokemon(static_cast<PokemonType>(Choice));
}

//Returns a randomly decided pokemon for the trainer
Pokemon * Pokemon::ChooseRandomPokemon()
{
    int num;
    num = Utility::RandomNummer(Bulbasaur,(AMOUNT_OF_TYPES - 2));
    return new Pokemon(static_cast<PokemonType>(num));
}

const Pokemon::PokemonData & Pokemon::getPokemonData( Pokemon::PokemonType type )
{
    return lookup[type];
}
