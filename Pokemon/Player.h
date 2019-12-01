#ifndef PLAYER_H
#define PLAYER_H
#include <Trainer.h>

class Player : public Pokemon
{
public:
    Player(const std::string &name);

    bool Won();
    bool Fainted();
    int GetHealth() const;

protected:
    int BattlesWon;
    int Health;

};

#endif // PLAYER_H
