#include <battle.h>
#include <utility.h>
#include <PokemonData.h>
#include <Player.h>
#include <Trainer.h>
#include <iostream>
#include <thread>

int Battle::CalDamage(int Attack, int Defense, int Power, int effect = 0)
{
    float Damage, min = 0.8, max = 1.2;
    float Chance = Utility::RandomNummer(min, max);
    Damage = Power * Chance * (Attack/Defense) + effect;
    return Damage;
}

int Battle::CalEffect(char TypePl, char TypeTr)
{
    int effect = 0;

    return effect;
}

void Battle::PlayerTurn(Pokemon &p, Pokemon &t)
{
    int choice;
    do{
    std::cout << "What do want to do ?\n\n 1): Attack\n 2) Items\n" ;
    std::cin.clear();
    std::cin.sync();
    std::cin >> choice;
    }while(choice != 1 && choice != 2);

    if(choice == 1)
    {
        int attack;
        do{
        std::cout << "\n 1): Attack\n 2): Growl\n 3): Leer\n 4): " << p.GetMove() <<"\n" ;
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
                std::cout << Damage;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                break;
            }
            case 2:
            {
                std::cout << "\n" <<p.GetName() << "uses Growl\n";
                std::cout << t.GetName() <<"'s attack has been lowered";
                t.ReduceAttack(3);
                break;
            }
            case 3:
            {
                std::cout << "\n" <<p.GetName() << "uses leer\n";
                std::cout << t.GetName() <<"'s defense has been lowered";
                t.ReduceDefense(3);
                break;
            }
            case 4:
            {
                std::cout << "\n" <<p.GetName() << "uses " <<p.GetMove();
                int Damage = CalDamage(p.GetAttack(), t.GetDefense(), 40, CalEffect(p.GetType(),t.GetType()));
                t.ReduceHealth(Damage);
                break;
            }
        }
    }
    else if(choice == 2)
    {

    }
}

//Hier kan de trainer aanvallen
void Battle::TrainerTurn(Pokemon &p, Pokemon &t)
{

}

//De battle volgorde & escapen wordt hier bepaald
void Battle::PokemonBattle(std::string PlayerName, std::string TrainerName)
{
    int choice;
    do
    {
    std::cin.clear();
    std::cin.sync();
    std::cout << "\n---------------------------\n|     Battle Started      |\n---------------------------\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout << "You can choose from the following pokemon:\n 1): Bulbasaur\n 2): Charmander\n 3): Squirtle\n\n ";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
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

    //Hier kan de speler aanvallen


    //Zolang de battle nog bezig is
    while (!p->Fainted() && !t->Fainted())
    {
        system("CLS");
        std::cout << TrainerName << "'s " << t->GetName() << " Has: " << t->GetHealth() << "/" << t->GetMaxHealth() << "Health left." <<  std::endl;
        std::cout << "\n\n" << PlayerName << "'s " << p->GetName() << " Has: " << p->GetHealth() << "/" << p->GetMaxHealth() << "Health left.\n\n" <<  std::endl;

        std::cout << "What will you do ?: (R)un or (F)ight: ";

        //cin eerst clear maken, anders blijft de vorige input erin vast hangen
        unsigned char input;
        std::cin.clear();
        std::cin.sync();
        std::cin >> input;

        if (Utility::IsChoice(input, 'R'))
        {
            if(Utility::KansBerekening(40))
            {
                std::cout << "You fled the battle";
                return;
            }
            else
            {
                std::cout << "You failed to flee.";
                TrainerTurn(*p, *t);
            }
        }
        else if (Utility::IsChoice(input, 'F'))
        {

            PlayerTurn(*p, *t);
            TrainerTurn(*p, *t);
        }
        else
        {
            std::cout << "Wrong input, try r or f";
        }
    }
}



