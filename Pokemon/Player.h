#ifndef PLAYER_H
#define PLAYER_H
#include <Creature.h>
#include <iostream>


class Player : public creature
{
public:
    Player(const std::string &name);

    bool Won();

private:
    int m_level;

};


#endif // PLAYER_H
