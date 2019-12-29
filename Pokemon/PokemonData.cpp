#include <PokemonData.h>
#include <battle.h>
#include <PokemonType.h>
#include <utility.h>
#include <Trainer.h>

using namespace std;

const Pokemon::PokemonData Pokemon::lookup[AMOUNT_OF_TYPES] = {
    //Name, move, type, MaxHealth, Health, attack, defense
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

//The player can choose a pokemon
Pokemon * Pokemon::ChoosePokemon(int Choice)
{
    return new Pokemon(static_cast<PokemonType>(Choice));
    //return new Pokemon("Bulbasaur");
}

//the trainer randomly gets a pokemon
Pokemon * Pokemon::ChooseRandomPokemon()
{
    int num;
    num = Utility::RandomNummer(Bulbasaur,Squirtle);
    return new Pokemon(static_cast<PokemonType>(num));
    //return new Pokemon("Charmander");
}

const Pokemon::PokemonData & Pokemon::getPokemonData( Pokemon::PokemonType type )
{
    //if( type >= AMOUNT_OF_TYPES )
    return lookup[type];
}

bool Pokemon::Fainted(){return (PokemonHealth <= 0);}
