#ifndef PLAYER_H
#define PLAYER_H
#include <Trainer.h>
#include <iostream>


class Player
{
public:
    Player(const std::string &name);

    bool Won();
    bool p_Fainted();

private:
    int p_BattlesWon;
    int p_Health;

};

#endif // PLAYER_H
