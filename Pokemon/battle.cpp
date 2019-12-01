#include <battle.h>
#include <Pokemon.h>
#include <Player.h>
#include <Trainer.h>
#include <iostream>
#include <utility.h>
#include <thread>


void PokemonBattle(Player p, Trainer t)    //Hier wordt de battle gesimuleerd
{
    std::cout << "What Pokemon will you choose: ?";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    //Pokemon E = Pokemon::ChooseRandomPokemon;

    while (!p.Fainted() && !t.Fainted())
    {
        std::cout << std::endl << "Your health: " << p.GetHealth() << std::endl;

        std::cout << "What will you do ?: (R)un or (F)ight: ";

        char input;
        std::cin >> input;
        if (IsChoice(input, 'R'))
        {
            if(KansBerekening(50))
            {
                std::cout << std::endl << "You fled the battle" << std::endl;
                return;
            }
            else
            {
                std::cout << std::endl << "You failed to flee. Time for another round." << std::endl;
                void TrainerAttacks();
            }
        }
        else if (IsChoice(input, 'F'))
        {
            void PlayerAttacks();
            void TrainerAttacks();
        }
    }
}


//Hier kan de speler aanvallen
void PlayerAttacks()
{
    std::cout << "Player valt Trainer aan";
}

//Hier kan de trainer aanvallen
void TrainerAttacks()
{

}
