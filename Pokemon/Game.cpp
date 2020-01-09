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
        std::cin >> PlayerName;     //naam uitlezen en opslaan in playername
        PlayerName.resize(20);      //lengte naam maximaal 20

        std::cout << "Enter the name of your rival (no spaces): ";
        std::string TrainerName;
        std::cin >> TrainerName;
        TrainerName.resize(20);

        if(Battle::PokemonBattle(PlayerName, TrainerName))       //start battle en geef namen spelers mee
        {
            std::cout << TrainerName << " blacked out...\n You won";
        }
        else
        {
            std::cout << PlayerName << " blacked out...\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
}
