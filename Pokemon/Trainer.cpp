#include <Trainer.h>
#include <Game.h>

Trainer::Trainer
(
    const std::string &name,
    char Family,
    int Health,
    int MaxHealth,
    int Attack,
    int Defense
)
    :
    t_name(name),
    t_family(Family),
    t_Health(Health),
    t_MaxHealth(MaxHealth),
    t_Attack(Attack),
    t_Defense(Defense)
{
}

int Trainer::GetHealth() const {return t_Health; }
bool Trainer::Fainted() const{return t_Health < 0; }
