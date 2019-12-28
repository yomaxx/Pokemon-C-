#include <utility.h>
#include <battle.h>
#include <Pokemon.h>
#include <Player.h>
#include <Trainer.h>
#include <iostream>
#include <thread>

//De battle volgorde & escapen wordt hier bepaald
void Battle::PokemonBattle(Player p, Trainer t)
{
    std::cout << "\n--------------------------\n      Battle Started\n--------------------------\n\n";
    std::cout << "What Pokemon will you choose: ?";
    std::string PokemonPlayer;
    std::cin >> PokemonPlayer;
    Pokemon* P = Pokemon::ChoosePokemon(PokemonPlayer);
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    Pokemon* T = Pokemon::ChooseRandomPokemon();

    while (!P->Fainted() && !T->Fainted())
    {
        std::cout << std::endl << "Your health: "  << std::endl;

        std::cout << "What will you do ?: (R)un or (F)ight: ";

        unsigned char input;
        std::cin >> input;

        if (Utility::IsChoice(input, 'R'))
        {
            if(Utility::KansBerekening(50))
            {
                std::cout << "You fled the battle";
                return;
            }
            else
            {
                std::cout << "You failed to flee. Time for another round.";
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
void PlayerAttacks(Pokemon P, Pokemon T)
{
    std::cout << "Player valt Trainer aan";


}

//Hier kan de trainer aanvallen
void TrainerAttacks(Pokemon P, Pokemon T)
{

}
