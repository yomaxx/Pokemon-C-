#include <iostream>
#include <Game.h>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout <<"\nWelcome to bootleg pokemon edition\n\n";

    Game::StartGame();
    return 0;
}
