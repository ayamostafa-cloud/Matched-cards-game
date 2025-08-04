#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include <random>
#include <iostream>
using namespace std;
Card ::Card(int number , bool faceUp): number(number) ,faceUp(faceUp){
    }
 Card ::Card():number(0) ,faceUp(false){}
  void Card :: display() {
        if ( faceUp  ){
                cout<< number  ;
        }

        else {
            cout<< "*"  ;
        }
    }
    void Card ::reveal() {
        faceUp = true;
    }


    void Card :: hide() {
        faceUp = false;
    }
void Card ::filpUp(){
        faceUp = false;
    }
int Card ::  getNumber(){
         return number ;
     }
bool  Card ::getfaceUp(){
      return faceUp;
      }
void Card ::setNumber(bool faceUp){
           faceUp = faceUp ;
}
void Card ::setNumber(int number){
       number = number ;
       }
 Card :: ~Card() {}

StandardCard::StandardCard ( int number  , bool faceUp) : Card(number , faceUp ) {}
 StandardCard:: StandardCard() : Card() {}
  void StandardCard:: display(){
         cout<< " StandardCard: " << endl ;
}
 StandardCard::~StandardCard(){}
BonusCard:: BonusCard() : Card() {}
BonusCard:: BonusCard( int number  , bool faceUp) : Card(number , faceUp ) {}
//int BonusCard:: getBonusPoints()  {
      //  return bonuspoints;
 //   }


void BonusCard:: setBonusPoints(int bonuspoints) {
       bonuspoints = bonuspoints;
    }
void BonusCard::display(){
         cout<< " BonusCard: " << endl ;

    }
BonusCard:: ~BonusCard(){}
PenaltyCard ::PenaltyCard() : Card() {}

  PenaltyCard ::  PenaltyCard(int num, bool faceUp )
        : Card(num, faceUp) {}

//int  PenaltyCard ::getPenaltyPoints() {
   //     return penaltyPoints;
    //

//void  PenaltyCard ::setPenaltyPoints(int penaltyPoints) {
      // this-> penaltyPoints = penaltyPoints;
    //

void PenaltyCard :: display(){
         cout<< " PenaltyCard: " << endl ;
}
//PenaltyCard ::~PenaltyCard() {}




Deck::Deck() {
    gridSize = 4;
    totalCards = gridSize * gridSize;
    cardsArray = new Card*[totalCards];

    int standardCardValue = 1;
    int bonusCardValue = 7;
    int penaltyCardValue = 8;

    int standardCardCount = 0;
    int bonusCardCount = 0;
    int penaltyCardCount = 0;
    for (int i = 0; i < totalCards; ++i) {
        if (standardCardCount < 12) {
            cardsArray[i] = new StandardCard(standardCardValue, false);
            ++standardCardCount;

            if (standardCardCount % 2 == 0) {
                ++standardCardValue;
                if (standardCardValue > 6) standardCardValue = 1;
            }
        } else if (bonusCardCount < 2) {
            cardsArray[i] = new BonusCard(bonusCardValue, false);
            ++bonusCardCount;
        } else if (penaltyCardCount < 2) {
            cardsArray[i] = new PenaltyCard(penaltyCardValue, false);
            ++penaltyCardCount;
        } else {
            cardsArray[i] = new StandardCard(0, false);
        }
    }
}


 void Deck::shuffle() {
    for (int i = 0; i < totalCards; i++) {

        int randomPos = rand() % totalCards;

        Card* temp = cardsArray[randomPos];
        cardsArray[randomPos] = cardsArray[i];
        cardsArray[i] = temp;
    }
}

void Deck::revealCard(int x, int y) {
    if (isValidIndex(x, y)) {
        Card* card = getCardAt(x, y);
        if (card != nullptr) {
            card->reveal();
        } else {
            cout << "No card to reveal at position (" << x << ", " << y << ")." << endl;
        }
    } else {
        cout << "Invalid coordinates (" << x << ", " << y << ")." << endl;
    }
}

void Deck::hideCard(int x, int y) {
    if (isValidIndex(x, y)) {
        Card* card = getCardAt(x, y);
        if (card != nullptr) {
            card->hide();
        } else {
            cout << "No card to hide at position (" << x << ", " << y << ")." << endl;
        }
    } else {
        cout << "Invalid coordinates (" << x << ", " << y << ")." << endl;
    }
}



    bool  Deck::isFaceUp(int index)  {
        return cardsArray[index]->getfaceUp();
    }


    Card* Deck::getCardAt(int x, int y) {
    if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
        return cardsArray[x * gridSize + y];
    }
    return nullptr;
}




 //DISPLAY IN A GRID??
void Deck::displayGrid() {
    int counter = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {

            if (cardsArray[counter] == nullptr) {
                cout << "  ";
            } else if (cardsArray[counter]->getfaceUp()) {
                cout << cardsArray[counter]->getNumber() <<" ";
            } else {
                cout << "* ";
            }
            counter++;
        }
        cout << "\n";
    }
}





Deck::~Deck() {
    for (int i = 0; i < totalCards; ++i) {
        delete cardsArray[i];
    }
    delete[] cardsArray;
}

bool Deck::isValidIndex(int row, int col) {
    return row >= 0 && row < gridSize && col >= 0 && col < gridSize;
}



void Deck::deleteCard(int row, int col) {
    if (isValidIndex(row, col)) {
        delete cardsArray[row * gridSize + col];
        cardsArray[row * gridSize + col] = nullptr;
    }
}
bool Deck::isEmpty() {
    for (int i = 0; i < totalCards; ++i) {
        if (!cardsArray[i]->getfaceUp()) {
            return false;
        }
    }
    return true;
}




//FOR PLAYER CLASS


Player::Player( string& name, int score) {
    this->name = name;
    this->score = score;
}

Player::Player(){
    name = "Unknown";
    score = 0 ;
}
string Player::getName()   {
    return name;
}

int Player::getScore()  {
    return score;
}
void Player::setScore(int score){
    this->score=score;
}
void Player::setName(string& name){
    this->name=name;
}

void Player::increaseScore(int points) {
        score += points;
    }

    void Player::decreaseScore(int points) {
        score -= points;
    }
void Player::displayScore() {
   cout << "Player: " << getName() << ", Score: " << getScore() << endl;

}



//GAME CLASS




Game::Game(Player* p1, Player* p2, Deck& d)
    : player1(p1), player2(p2), deck(d), isPlayer1Turn(false)  {}



  void Game::initializeGame() {
    cout << "Player 1: ";
    player1->displayScore();
    cout << "Player 2: ";
    player2->displayScore();


    deck.shuffle();
    deck.displayGrid();

}

void  Game::displayGrid() {
        deck.displayGrid();

    }




void Game::playTurn() {


    while (!deck.isEmpty()){
            Player* currentPlayer = isPlayer1Turn ? player1 : player2;

           bool takeAnotherTurn = true;

   while (takeAnotherTurn){
           int x1, y1, x2, y2;
        deck.displayGrid();

        cout << currentPlayer->getName() << "'s Turn.\n";
        cout << "Enter coordinates for the first card (row and column, 0-based index): ";
        cin >> x1 >> y1;


        while  (!deck.isValidIndex(x1, y1)) {
            cout << "Invalid coordinates. Please try again.\n";
            cout << "Enter coordinates for the first card (row and column, 0-based index): ";
            cin >> x1 >> y1;
        }

        cout << "Enter coordinates for the second card (row and column, 0-based index): ";
        cin >> x2 >> y2;


       while  (!deck.isValidIndex(x2, y2)) {
            cout << "Invalid coordinates. Please try again.\n";
            cout << "Enter coordinates for the second card (row and column, 0-based index): ";
            cin >> x2 >> y2;
        }


         while (x1 == x2 && y1 == y2) {
            cout << "You cannot select the same card twice. Please try again.\n";
            cout << "Enter coordinates for the first card (row and column, 0-based index): ";
            cin >> x1 >> y1;
            cout << "Enter coordinates for the second card (row and column, 0-based index): ";
            cin >> x2 >> y2 ;
        }
        deck.revealCard(x1, y1);
        deck.revealCard(x2, y2);
        deck.displayGrid();
        int card1Number = deck.getCardAt(x1, y1)->getNumber();
        int card2Number = deck.getCardAt(x2, y2)->getNumber();
        if (card1Number == card2Number && card1Number != 7 && card1Number != 8) {
            cout << "Match found! You gain 1 point.\n";
            currentPlayer->increaseScore(1);
            deck.deleteCard(x1, y1);
            deck.deleteCard(x2, y2);
            takeAnotherTurn = true;

        } else if (card1Number == 7 || card2Number == 7) {
            if (card1Number == 7 && card2Number == 7) {
                cout << "You revealed two Bonus Cards! Choose an option:\n";
                cout << "1. Gain +2 points.\n";
                cout << "2. Gain +1 point and take another turn.\n";

                int choice;
                cin >> choice;

                if (choice == 1) {
                    currentPlayer->increaseScore(2);
                    deck.deleteCard(x1, y1);
                    deck.deleteCard(x2, y2);
                    takeAnotherTurn = false; // el player el tani hayl3ab

                } else if (choice == 2) {
                    currentPlayer->increaseScore(1);
                    deck.deleteCard(x1, y1);
                    deck.deleteCard(x2, y2);
                    takeAnotherTurn = true;
                }

            } else {
                cout << "You revealed a Bonus Card and a Standard Card. Gain +1 point.\n";
                currentPlayer->increaseScore(1);

                if (card1Number == 7) {
                    deck.deleteCard(x1, y1);
                    deck.hideCard(x2,y2 );
                } else {
                    deck.deleteCard(x2, y2);
                    deck.hideCard(x1, y1);
                }

                takeAnotherTurn = false;
            }

        } else if (card1Number == 8 || card2Number == 8) {

            if (card1Number == 8 && card2Number == 8) {
                cout << "You revealed two Penalty Cards! Choose an option:\n";
                cout << "1. Lose 2 points.\n";
                cout << "2. Lose 1 point and skip your next turn.\n";

                int choice;
                cin >> choice;

                if (choice == 1) {
                    currentPlayer->decreaseScore(2);
                    deck.deleteCard(x1, y1);
                    deck.deleteCard(x2, y2);
                    takeAnotherTurn = false;

                } else if (choice == 2) {
                    currentPlayer->decreaseScore(1);
                    deck.deleteCard(x1, y1);
                    deck.deleteCard(x2, y2);
                    isPlayer1Turn = !isPlayer1Turn;
                    return;
                }

            } else {
                cout << "You revealed a Penalty Card and a Standard Card. Lose 1 point.\n";
                currentPlayer->decreaseScore(1);

                if (card1Number == 8) {
                    deck.deleteCard(x1, y1);
                   deck.hideCard(x2, y2);
                } else {
                    deck.deleteCard(x2, y2);
                    deck.hideCard(x1, y1);
                }

                takeAnotherTurn = false;
            }

        } else {
            cout << "No match. Cards will be flipped back.\n";
           deck.hideCard(x1, y1);
           deck.hideCard(x2, y2);
            takeAnotherTurn = false;
        }

    }
      deck.displayGrid();
    cout << "Current Scores:\n";
    cout << player1->getName() << ": " << player1->getScore() << "\n";
    cout << player2->getName() << ": " << player2->getScore() << "\n";
    isPlayer1Turn = !isPlayer1Turn;

          }

               announceWinner();
}


void Game::announceWinner() {
    cout << "Game Over!" << endl;

    if (player1->getScore() > player2->getScore()) {
        cout << "Winner: " << player1->getName() << " with a score of " << player1->getScore() << endl;
    } else if (player2->getScore() > player1->getScore()) {
        cout << "Winner: " << player2->getName() << " with a score of " << player2->getScore() << endl;
    } else {
        cout << "It's a tie! Both players scored " << player1->getScore() << endl;
    }
}


void Game::playGame() {
    while (!deck.isEmpty()) {
        playTurn();

        if (deck.isEmpty()) {
            announceWinner();
            break;
        }
    }
}



Game::~Game() {
delete player1;
delete player2;

}


#include <iostream>
#include <string>
using namespace std;
int main() {

    string player1Name, player2Name;


    cout << "Enter Player 1 Name: ";
    getline(cin, player1Name);

    cout << "Enter Player 2 Name: ";
    getline(cin, player2Name);


    Player* player1 = new Player(player1Name, 0);
    Player* player2 = new Player(player2Name, 0);

    Deck deck;

    Game game(player1, player2, deck);

     game.initializeGame();

     cout<<" "<<endl;
    game.playGame();



    delete player1;
    delete player2;

    return 0;
}
