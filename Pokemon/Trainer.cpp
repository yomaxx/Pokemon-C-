#include <Trainer.h>
#include <Game.h>

Trainer::Trainer
(
    const std::string &name,
    const std::string &Move,
    const std::string Family,
    const std::string EffectiveFamily,
    const std::string WeakFamily,
    int Health,
    int MaxHealth,
    int Attack,
    int Defense
)
    :
    PokemonName(name),
    PokemonMove(Move),
    PokemonFamily(Family),
    PokemonEffective(EffectiveFamily),
    PokemonWeak(WeakFamily),
    PokemonHealth(Health),
    PokemonMaxHealth(MaxHealth),
    PokemonAttack(Attack),
    PokemonDefense(Defense)
{
}
std::string & Trainer::GetName() {return PokemonName; }
std::string & Trainer::GetMove() {return PokemonMove; }
std::string & Trainer::GetType() {return PokemonFamily;}
std::string & Trainer::GetEffectiveType() {return PokemonEffective;}
std::string & Trainer::GetWeakType() {return PokemonWeak;}

int Trainer::GetMaxHealth() const {return PokemonMaxHealth; }
int Trainer::GetHealth() const {return PokemonHealth; }
int Trainer::GetAttack() const {return PokemonAttack; }
int Trainer::GetDefense() const {return PokemonDefense; }

bool Trainer::Fainted() const{return PokemonHealth <= 0;}

void Trainer::ReduceHealth(int Damage){PokemonHealth -= Damage;}
void Trainer::UsePotion(){PokemonHealth += 20; if(PokemonHealth >= PokemonMaxHealth) {PokemonMaxHealth = PokemonHealth;}}
void Trainer::NegativeHealth(){if(PokemonHealth < 0){PokemonHealth = 0;}}
void Trainer::ReduceAttack(int Reduce){PokemonAttack -= Reduce;}
void Trainer::ReduceDefense(int Reduce){PokemonDefense -= Reduce;}
