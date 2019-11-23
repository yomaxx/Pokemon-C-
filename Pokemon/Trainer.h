#include <Pokemon.h>

class Trainer : public Pokemon
{
public:

    bool t_Fainted() const;

private:
    int t_Health;
};


