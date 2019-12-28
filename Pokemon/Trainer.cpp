#include <Trainer.h>
#include <Player.h>
#include <Game.h>

Trainer::Trainer(const std::string &name) : Pokemon (name)
{

}

bool Trainer::Fainted() const{return t_Health < 0;}
