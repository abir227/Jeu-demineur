#ifndef JEU_H
#define JEU_H
#include  "Case.h"
#include "Grille.h"
#include <iostream>
using namespace std;

class Jeu {

    public :
    Jeu();
     void MessageGameStart();
     void ChoicePlay(int choix);
    void ChoiceAction(int choix);
    void GoToMenuPrincipal();
    void Play(int x, int y);
    void flag (int x,int y);
    void GetCoordinatesXYdr();
    void GetCoordinatesXY();
    void MenuGameStarted();
    int ValidationOptionNumber();
    int ValidationCoordinates();
    virtual ~Jeu();

private :

     void LevelBeginner();
     void LevelAvance();
     void Exit();
    bool lost=false;
    Grille grille;



};

#endif // JEU_H
