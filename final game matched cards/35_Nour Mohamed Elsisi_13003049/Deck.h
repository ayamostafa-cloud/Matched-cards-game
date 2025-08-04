#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED
#include "Card.h"
#include <iostream>
#include <vector>
using namespace std;
class Deck{

   private:
       Card** cardsArray;
       int totalCards;
       int gridSize;

   public:
    Deck();
   ~Deck();
    void shuffle();
    void displayGrid();
    void revealCard(int x , int y);
    void hideCard(int x , int y);
    Card* getCardAt(int x , int y);
    bool isFaceUp(int index) ;
    bool isEmpty();
bool isValidIndex(int row, int col);
    void deleteCard(int row, int col);
    int getGridSize() ;
};


#endif // DECK_H
