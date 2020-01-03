#include <battle.h>
#include <utility.h>
#include <PokemonData.h>
#include <Player.h>
#include <Trainer.h>
#include <iostream>
#include <thread>
#include <QtMultimedia>

//Damage dealth gets calculated here, chance is used to slighlty differ damage dealth every time.
float Battle::CalDamage(float Attack, float Defense, int Power, int effect = 0)
{
    float Damage, min = 0.8, max = 1.2;
    float Chance = Utility::RandomNummer(min, max);
    int critical = 0;
    if(Utility::KansBerekening(10))
    {
        std::cout << "\n Critical HIT";
        critical = 10;
    }
    Damage = Power * Chance *(Attack/(Defense*2)) + effect + critical;
    return Damage;
}

//This function returns if the move was not effective, effective or super effective.
//not effective means -10 damage, while super effective adds 10 damage.
int Battle::CalEffect(char TypePl, char TypeTr)
{
    int effect = 0;

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
        }while(!(choice >= 1) && !(choice <= 4));

        switch(attack)
        {
            case 1:
            {
                std::cout << "\n" <<p.GetName() << " uses attack\n";
                int Damage = CalDamage(p.GetAttack(), t.GetDefense(), 40);
                t.ReduceHealth(Damage);
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                break;
            }
            case 2:
            {
                std::cout << "\n" <<p.GetName() << "uses Growl\n";
                std::cout << t.GetName() <<"'s attack has been lowered";
                t.ReduceAttack(3);
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                break;
            }
            case 3:
            {
                std::cout << "\n" <<p.GetName() << "uses leer\n";
                std::cout << t.GetName() <<"'s defense has been lowered";
                t.ReduceDefense(3);
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                break;
            }
            case 4:
            {
                std::cout << "\n" <<p.GetName() << "uses " <<p.GetMove();
                int Damage = CalDamage(p.GetAttack(), t.GetDefense(), 40, CalEffect(p.GetType(),t.GetType()));
                t.ReduceHealth(Damage);
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                break;
            }
        }
    }
    else if(choice == 2)
    {
        std::cout << "What item do you want to use ?";
    }
}

//Hier kan de trainer aanvallen
void Battle::TrainerTurn(Pokemon &p, Pokemon &t, std::string TrainerName)
{
    if(t.GetHealth() > 15 && Utility::KansBerekening(20))
    {
        std::cout << TrainerName << "used a potion";
    }
    else
    {
        std::cout << "\n" <<t.GetName() << " uses attack\n";
        int Damage = CalDamage(t.GetAttack(), p.GetDefense(), 40);
        p.ReduceHealth(Damage);
    }

}

//Battle sequence is being emulated here
void Battle::PokemonBattle(std::string PlayerName, std::string TrainerName)
{
    //Play Battle music


    int choice;
    do
    {
    std::cin.clear();
    std::cin.sync();
    std::cout << "\n---------------------------\n|     Battle Started      |\n---------------------------\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "You can choose from the following pokemon:\n 1): Bulbasaur\n 2): Charmander\n 3): Squirtle\n\n ";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "What Pokemon will you choose(number): ";
    std::cin >> choice;
    choice = choice - 1;
    }while(std::cin.fail());    //checkt of de input wel goed is (geen letters)


    //Bij "foute" ingave "speciale" pokemon geven
    if(choice < 0 || choice >= 3)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        std::cout << "\n\n -----YOU HAVE SUMMONED BART----- \n\n" ;
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        choice = 3;
    }

    //Pokemons worden gemaakt
    Pokemon* p = Pokemon::ChoosePokemon(choice);
    Pokemon* t = Pokemon::ChooseRandomPokemon();

    //print welke pokemons gekozen zijn
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    system("CLS");
    std::cout << std::endl << TrainerName <<" chooses: "  << t->GetName() <<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << std::endl << "\n\n\n" << PlayerName <<" chooses: "  << p->GetName() <<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    system("CLS");

    //Zolang de battle nog bezig is
    while (!p->Fainted() && !t->Fainted())
    {
        std::cout << TrainerName << "'s " << t->GetName() << " Has: " << t->GetHealth() << "/" << t->GetMaxHealth() << "Health left." <<  std::endl;
        std::cout << "\n\n" << PlayerName << "'s " << p->GetName() << " Has: " << p->GetHealth() << "/" << p->GetMaxHealth() << "Health left.\n\n" <<  std::endl;

        //cin eerst clear maken, anders blijft de vorige input erin vast hangen
        int choice;
        do{
        std::cout << "\n\n 1): Attack\n 2): Items\n 3): Run\n What do want to do: " ;
        std::cin.clear();
        std::cin.sync();
        std::cin >> choice;
        }while(!(choice != 1) && !(choice != 2) && choice != 3);

            if(choice == 3 && Utility::KansBerekening(40))
            {
                std::cout << "You fled the battle";
                return;
            }
            else if(choice != 3)
            {
                PlayerTurn(*p, *t, PlayerName, choice);
                TrainerTurn(*p, *t, TrainerName);
            }
            else
            {
                std::cout << "You failed to flee.";
                TrainerTurn(*p, *t, TrainerName);
            }

        system("CLS");
    }
}
