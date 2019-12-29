#include <Trainer.h>
#include <Player.h>
#include <time.h>
#include <iostream>
#include <Game.h>
#include <battle.h>
#include <thread>

void Game::StartGame()
{
    //seed halen voor random nummers later
    srand(static_cast<unsigned int>(time(nullptr)));

    //Naam speler opgeven

        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        std::cout << "Enter your name (no spaces): ";
        std::string PlayerName;     //string playername aanmaken
        std::cin >> PlayerName;     //naam uitlezen en opslaan in playername     //player p aanmaken met je naam

        std::cout << "Enter the name of your rival (no spaces): ";
        std::string TrainerName;
        std::cin >> TrainerName;


    //while je nog niet fainted of gewonnen hebt
    //while(!p.Fainted() && !p.Won())
    //{
        Battle::PokemonBattle(PlayerName, TrainerName);       //start battle en geef naam p mee

    /*
        if(p.Fainted())
        {
            std::cout << "Game over!" << std::endl;
            //break;
        }
        if(p.Won())
        {
            std::cout << "You won!" << std::endl;
            //break;
        }

        std::cout << std::endl << "Play again? (Y/N):";
        unsigned char choice;
        std::cin >> choice;
        std::cout << std::endl;
    */
    //}


}
