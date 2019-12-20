#include <Player.h>
#include <Game.h>

using namespace std;

Player::Player(const std::string &name) : Pokemon(name)
{
}


bool Player::Fainted(){return (p_Health);}
bool Player::Won(){return (BattlesWon);}

int Player::GetHealth() const { return p_Health; }
