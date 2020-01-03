#include <PokemonData.h>
#include <battle.h>
#include <PokemonType.h>
#include <utility.h>
#include <Trainer.h>

using namespace std;

//lookup table with pokemon information
const Pokemon::PokemonData Pokemon::lookup[AMOUNT_OF_TYPES] = {
    //Name, move, type, Not effective, very effective, MaxHealth, Health, attack, defense
    {"Bulbasaur","Razor leaf",'G',46,46,22,26},
    {"Charmander","Flame wheel",'F',49,49,23,22},
    {"Squirtle","WatergGun",'W',52,52,18,26},
    {"Bart","Meme",'t',150,150,5,5}
};

Pokemon::Pokemon(PokemonType Type)
    :
        Trainer
        (
            lookup[Type].name,
            lookup[Type].Move,
            lookup[Type].Family,
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
    num = Utility::RandomNummer(Bulbasaur,Squirtle);
    return new Pokemon(static_cast<PokemonType>(num));
}

const Pokemon::PokemonData & Pokemon::getPokemonData( Pokemon::PokemonType type )
{
    return lookup[type];
}
