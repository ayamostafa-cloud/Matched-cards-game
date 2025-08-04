#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED




#include "Deck.h"
#include "Player.h"
using namespace std;
class Game {
private:
    Player* player1;
    Player* player2;
    Deck& deck;
    bool isPlayer1Turn;

public:
    Game(Player* p1, Player* p2, Deck& d);
    void displayGrid();
    void initializeGame();
    void announceWinner();
 void playTurn(); // Method added here
    void playGame();
    ~Game();
};

#endif
