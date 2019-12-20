#include <utility.h>
#include <battle.h>
#include <Pokemon.h>
#include <Player.h>
#include <Trainer.h>
#include <iostream>
#include <thread>


void Battle::PokemonBattle(Player p, Trainer t)    //Hier wordt de battle gesimuleerd
{
    std::cout << "--------------------------\n      Battle Started\n--------------------------\n";
    std::cout << "What Pokemon will you choose: ?";
    std::string PokemonPlayer;
    std::cin >> PokemonPlayer;
    Pokemon* P = Pokemon::ChoosePokemon(PokemonPlayer);
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    Pokemon* T = Pokemon::ChooseRandomPokemon();

    while (!p.Fainted() && !t.Fainted())
    {
        std::cout << std::endl << "Your health: " << p.GetHealth() << std::endl;

        std::cout << "What will you do ?: (R)un or (F)ight: ";

        char input;
        std::cin >> input;

        if (Utility::IsChoice(input, 'R'))
        {
            if(Utility::KansBerekening(50))
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
        else if (Utility::IsChoice(input, 'F'))
        {
            void PlayerAttacks(Player p, Trainer t);
            void TrainerAttacks(Player p, Trainer t);
        }
        else
        {
            std::cout << "Wrong input, try r or f";
        }
    }
}


//Hier kan de speler aanvallen
void PlayerAttacks(Player p, Trainer t)
{
    std::cout << "Player valt Trainer aan";

    //t.ReduceHealth(p.GetDamage());
}

//Hier kan de trainer aanvallen
void TrainerAttacks(Player p, Trainer t)
{

}
