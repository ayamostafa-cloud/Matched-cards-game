#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include<iostream>
using namespace std;
class Card {
private:
    int number ;
    bool faceUp ;
public :
    Card(int number , bool faceUp);
    Card();
    virtual  void display() ;
    void filpUp();
    virtual ~Card() ;
    int getNumber();
    bool getfaceUp();
    void setNumber(bool faceUp);
    void setNumber(int number);
    void  reveal();
    void hide();
};
 class StandardCard :  public Card {
     public :
     StandardCard ( int number  , bool faceUp) ;
     StandardCard() ;
     void display();

    ~StandardCard();
 };
class BonusCard:  public Card {
  // private :
    //   int bonuspoints ;
    public :
    BonusCard() ;
    BonusCard( int number  , bool faceUp) ;
    int getBonusPoints()  ;
    void setBonusPoints(int bonuspoints) ;
    void display();
     ~BonusCard();
   };
class PenaltyCard : public Card {
     //  int penaltyPoints;
  public:

    PenaltyCard() ;
    PenaltyCard(int num, bool iFaceUp );
    int getPenaltyPoints()  ;


    void setPenaltyPoints(int penaltyPoints) ;

    void display();
    ~PenaltyCard() {}
};


#endif
