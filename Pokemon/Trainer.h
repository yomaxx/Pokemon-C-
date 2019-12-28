#pragma once
#include <iostream>
#include <string>

class Trainer
{
public:

    Trainer
    (
        const std::string &name,
        char Family,
        int Health,
        int MaxHealth,
        int Attack,
        int Defense
    );
    ~Trainer(){}

    int GetHealth() const;
    bool Fainted() const;

protected:
    std::string t_name;
    char t_family;
    int t_Health;
    int t_MaxHealth;
    int t_Attack;
    int t_Defense;
};


