#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;


class Player {
private:
   string name;
    int score;
public:
   Player();
   Player( string &name, int score);
   string getName()  ;
   int getScore();
   void setScore(int score);
   void setName(string& name);
   void displayScore() ;
   void decreaseScore(int points);
   void increaseScore(int points);

};

#endif // PLAYER_H_H_INCLUDED
