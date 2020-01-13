#include <battle.h>
#include <utility.h>
#include <PokemonData.h>
#include <Player.h>
#include <Trainer.h>
#include <iostream>
#include <thread>
#include <QMediaPlayer>
#include <QApplication>
#include <QTimer>

int Battle::choiceClear()
{
    int choice = 0;
    do
    {
        std::cin.clear();
        std::cin.sync();
        std::cin >> choice;
    }while(std::cin.fail());    //Check if the input is correct

    return choice;
}

//Damage dealth gets calculated here, chance is used to slighlty differ damage dealth every time.
//Also 10% chance of missing.
float Battle::CalDamage(float Attack, float Defense, int Power, int effect = 0)
{
    float Damage, min = 0.8, max = 1.2;
    float Chance = Utility::RandomNummer(min, max);
    int critical = 0;
    if(Utility::KansBerekening(10))
    {
        return 0;
    }
    if(Utility::KansBerekening(10))
    {
        std::cout << "\n Critical HIT\n";
        critical = 10;
    }
    Damage = Power * Chance *(Attack/(Defense*2)) + effect * critical;
    return Damage;
}

//This function returns if the move was not effective, effective or super effective.
//not effective means -10 damage, while super effective adds 10 damage.
float Battle::CalEffect(std::string FamilyAttacker, std::string WeakAttacker, std::string WeakDefender, std::string FamilyDefender)
{
    float effect = 0;
    if(FamilyAttacker == WeakDefender)
    {
        std::cout << " It's super effective\n";
        effect = 2;
    }
    else if(FamilyDefender == WeakAttacker)
    {
        std::cout << " It's not very effective\n";
        effect = 0.5;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return effect;
}

void Battle::PlayerTurn(Pokemon &p, Pokemon &t, std::string PlayerName, int choice)
{

    if(choice == 1)
    {
        int attack;
        do{
        std::cout << "\n 1): Attack\n 2): Growl\n 3): Leer\n 4): " << p.GetMove() <<"\n" ;
        std::cout << "What attack will you use ?: ";
        std::cin.clear();
        std::cin.sync();
        std::cin >> attack;
        std::cout << "\n";
        }while(choice < 1 || choice > 4);

        std::cout << PlayerName << "'s ";

        switch(attack)
        {
            case 1:
            {
                std::cout <<p.GetName() << " uses attack\n";
                int Damage = CalDamage(p.GetAttack(), t.GetDefense(), 40);
                t.ReduceHealth(Damage);
                break;
            }
            case 2:
            {
                std::cout << p.GetName() << " uses Growl\n";
                std::cout << t.GetName() <<"'s attack has been lowered\n";
                t.ReduceAttack(3);
                break;
            }
            case 3:
            {
                std::cout << p.GetName() << " uses leer\n";
                std::cout << t.GetName() <<"'s defense has been lowered\n";
                t.ReduceDefense(3);
                break;
            }
            case 4:
            {
                std::cout <<p.GetName() << " uses " <<p.GetMove() << "\n";
                int Damage = CalDamage(p.GetAttack(), t.GetDefense(), 50, CalEffect(p.GetType(),p.GetWeakType(),t.GetWeakType(), t.GetType()));
                t.ReduceHealth(Damage);
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

    else if(choice == 2)
    {
        p.UsePotion();
        std::cout <<"\n" <<PlayerName << " used a potion on " << p.GetName() << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}


//the trainer can attack here
void Battle::TrainerTurn(Pokemon &p, Pokemon &t, std::string TrainerName)
{
    if(t.GetHealth() < 15 && Utility::KansBerekening(20))
    {
        std::cout << TrainerName << "used a potion\n" << t.GetName() << "'s health has been restored";
        t.UsePotion();
    }
    else if(Utility::KansBerekening(50))
    {
        std::cout << TrainerName << "'s ";
        std::cout <<t.GetName() << " uses " <<t.GetMove();
        int Damage = CalDamage(t.GetAttack(), p.GetDefense(), 40, CalEffect(t.GetType(),t.GetWeakType(), p.GetWeakType(),p.GetType()));
        p.ReduceHealth(Damage);
    }
    else
    {
        std::cout << TrainerName << "'s ";
        std::cout <<t.GetName() << " uses attack\n";
        int Damage = CalDamage(t.GetAttack(), p.GetDefense(), 50);
        p.ReduceHealth(Damage);
    }
std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}


//Battle sequence is being emulated here
bool Battle::PokemonBattle(std::string PlayerName, std::string TrainerName)
{
    //Play Battle music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Music/Pokemon-Battle-trainer.mp3"));
    music->setVolume(50);
    music->play();

    //start of battle text
    int choice, choice2, choice3;
    std::cout << "\n---------------------------\n|     Battle Started      |\n---------------------------\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "You can choose 3 pokemon for this battle, The available pokemon are:\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << " 1): Bulbasaur\n 2): Charmander\n 3): Squirtle\n 4): Pidgey\n 5): Pikachu\n 6): Mankey\n";
    std::cout << " 7): Dratini\n 8): Snorlax\n\n";

    std::cout << "Choose begin pokemon: ";
    choice = choiceClear() -1;
    std::cout << "Choose second pokemon: ";
    choice2 = choiceClear() -1;
    std::cout << "Choose third pokemon: ";
    choice3 = choiceClear() -1;

    //If the player enters a wrong number the player gets a "special" pokemon
    if(choice < 0 || choice > 8 || choice2 < 0 || choice2 > 8 || choice3 < 0 || choice3 > 8)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        std::cout << "\n\n -----MissingNo appeared----- \n\n" ;
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        if(choice < 0 || choice >= 8)
        {
          choice = 8;
        }
        if(choice2 < 0 || choice2 >= 8)
        {
            choice2 = 8;
        }
        if(choice3 < 0 || choice3 >= 8)
        {
            choice3 = 8;
        }

    }

    //The pokemons for the player are created here
    Pokemon* p = Pokemon::ChoosePokemon(choice);
    Pokemon* p2 = Pokemon::ChoosePokemon(choice2);
    Pokemon* p3 = Pokemon::ChoosePokemon(choice3);

    //The trainer gets 3 random pokemon
    Pokemon* t = Pokemon::ChooseRandomPokemon();
    Pokemon* t2 = Pokemon::ChooseRandomPokemon();
    Pokemon* t3 = Pokemon::ChooseRandomPokemon();

    //Temporary pokemon for switching
    Pokemon* z;

    //print welke pokemons gekozen zijn
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    system("CLS");
    std::cout << std::endl << TrainerName <<" chooses: "  << t->GetName() <<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << std::endl << "\n\n\n" << PlayerName <<" chooses: "  << p->GetName() <<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    system("CLS");

    //Zolang de battle nog bezig is
    while (1)
    {
        //check if health player is > 0, if yes set health to 0
        p->NegativeHealth();

        std::cout << "\n" << TrainerName << "'s " << t->GetName() << " Has: " << t->GetHealth() << "/" << t->GetMaxHealth() << " Health left." <<  std::endl;
        std::cout << "\n\n\n" << PlayerName << "'s " << p->GetName() << " Has: " << p->GetHealth() << "/" << p->GetMaxHealth() << " Health left.\n\n" <<  std::endl;

        int choice = 3;
        if(!p->Fainted())
        {
            do{
            std::cout << "\n\n 1): Attack\n 2): Potions\n 3): Pokemon\n 4): Run\n What do you want to do? : " ;
            std::cin.clear();
            std::cin.sync();
            std::cin >> choice;
            }while(choice < 1 || choice > 4);
        }
            if(choice == 4 && Utility::KansBerekening(40))  //Flee the battle
            {
                std::cout << "You fled the battle\n";
                return false;
            }
            else if(choice == 3)    //Change pokemon
            {
                int choice = 0;
                do
                {
                std::cout << "\n 1): ";
                std::cout << p2->GetName() << " With " << p2->GetHealth() << "/" << p2->GetMaxHealth() << " HP\n 2): ";
                std::cout << p3->GetName() << " With " << p3->GetHealth() << "/" << p3->GetMaxHealth() << " HP";
                std::cout << "\nChoose a pokemon to use: ";
                std::cin.clear();
                std::cin.sync();
                std::cin >> choice;
                }while(!(choice ==1) && !(choice == 2));
                std::cout << p->GetName() << " Come back\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                switch (choice)
                {
                case 1:
                {
                    std::cout << p2->GetName() << " I choose you\n";
                    z = p;
                    p = p2;
                    p2 = z;
                    break;
                }
                case 2:
                {
                    std::cout << p3->GetName() << " I choose you\n";
                    z = p;
                    p = p3;
                    p3 = z;
                    break;
                }
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
            else if(choice != 4)    //attack or use item
            {
                PlayerTurn(*p, *t, PlayerName, choice);
            }
            else                    //Failed to flee
            {
                std::cout << "You failed to flee.";
            }

        if(!t->Fainted())
        {
            TrainerTurn(*p, *t, TrainerName);
        }

        //Check if the pokemons of the player or trainer are all fainted.
        if(p->Fainted() && p2->Fainted() && p3->Fainted())
        {
            delete p;       //Deleting used Pokemons.
            delete p2;
            delete p3;
            delete t;
            delete t2;
            delete t3;
            return false;
        }
        else if(t->Fainted() && t2->Fainted() && t3->Fainted())
        {
            delete p;       //Deleting used Pokemons.
            delete p2;
            delete p3;
            delete t;
            delete t2;
            delete t3;
            return true;
        }

        //Trainer swaps pokemon when primary one is fainted
        if(t->Fainted() && t2->Fainted())
        {
            std::cout << t->GetName() << " Fainted\n Go " << t3->GetName();
            z = t;
            t = t3;
            t3 = z;
        }
        if(t->Fainted())
        {
            std::cout << t->GetName() << " Fainted\n Go " << t2->GetName();
            z = t;
            t = t2;
            t2 = t;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("CLS");

    }
}
