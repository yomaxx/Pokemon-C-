#include <iostream>
#include <battle.h>
#include <Pokemon.h>
#include <time.h>
#include <Player.h>
#include <Trainer.h>
#include <battle.h>

using namespace std;

int main()
{
    //seed halen voor random nummers later
    srand(static_cast<unsigned int>(time(NULL)));

    //Naam speler opgeven
    std::cout << "Enter your name (no spaces): ";
    std::string playerName;     //string playername aanmaken
    std::cin >> playerName;     //naam uitlezen en opslaan in playername
    Player p(playerName);       //player p aanmaken met je naam

    std::cout << "Enter the name of your rival (no spaces): ";
    std::string TrainerName;
    std::cin >> TrainerName;
    Trainer t(TrainerName);

    //while je nog niet fainted of gewonnen hebt
    while(!p.Fainted() && !p.Won())
    {
        void PokemonBattle(p,t);       //start battle en geef naam p mee

        if(p.Fainted())
        {
            std::cout << "Game over!" << std::endl;
            break;
        }
        if(p.Won())
        {
            std::cout << "You won!" << std::endl;
            break;
        }
    }
    return 0;
}
