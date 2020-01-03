#include <Trainer.h>
#include <Game.h>

Trainer::Trainer
(
    const std::string &name,
    const std::string &Move,
    char Family,
    int Health,
    int MaxHealth,
    int Attack,
    int Defense
)
    :
    PokemonName(name),
    PokemonMove(Move),
    PokemonFamily(Family),
    PokemonHealth(Health),
    PokemonMaxHealth(MaxHealth),
    PokemonAttack(Attack),
    PokemonDefense(Defense)
{
}
std::string & Trainer::GetName() {return PokemonName; }
std::string & Trainer::GetMove() {return PokemonMove; }

int Trainer::GetMaxHealth() const {return PokemonMaxHealth; }
int Trainer::GetHealth() const {return PokemonHealth; }
int Trainer::GetAttack() const {return PokemonAttack; }
int Trainer::GetDefense() const {return PokemonDefense; }

char Trainer::GetType() const {return PokemonFamily;}

bool Trainer::Fainted() const{return PokemonHealth <= 0; }

void Trainer::ReduceHealth(int Damage){PokemonHealth -= Damage;}
void Trainer::ReduceAttack(int Reduce){PokemonAttack -= Reduce;}
void Trainer::ReduceDefense(int Reduce){PokemonDefense -= Reduce;}
