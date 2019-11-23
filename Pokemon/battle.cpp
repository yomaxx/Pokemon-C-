#include <battle.h>
#include <Pokemon.h>
#include <Player.h>
#include <Trainer.h>
#include <iostream>
#include <utility.h>


void PokemonBattle(Player p)    //Hier wordt de battle gesimuleerd
{
    
    Pokemon E = Pokemon::ChooseRandomPokemon;

    while (!p.Fainted() && !t_Fainted())
    {
        std::cout << std::endl << "Your health: " << p.Health() << std::endl;

        std::cout << "What will you do ?: (R)un or (F)ight: ";

        char input;
        std::cin >> input;
        if (IsChoice(input, 'R'))
        {
            if(KansBerekening(50))
            {

            }
            else
            {
                std::cout << std::endl << "You failed to flee. Time for another round." << std::endl;
                TrainerAttacks();
            }
        }
        else if (IsChoice(input, 'F'))
        {
            PlayerAttacks();
            TrainerAttacks();
        }
    }
}


//Hier kan de speler aanvallen
void PlayerAttacks()
{

}

//Hier kan de trainer aanvallen
void TrainerAttacks()
{

}
