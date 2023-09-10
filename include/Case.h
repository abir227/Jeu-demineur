#ifndef CASE_H
#define CASE_H
#include "iostream"
#include <string>
using  namespace std;

class Case {
public:
    Case();
    void TurnCaseInEmpty();
    void IncreaseValueCase();
    string DisplayCase() const;
    void DisplayNumberCase();
    bool  IsBombe();
    void TurnCaseInBombe();
    bool Isreveal();
    void TurnCaseReveal();
    void DevoilerCaseNbr() ;
    void HideCase();
    int GetNumberCase();
     void ModifyDisplayBombe();
     ~Case();

private:
    bool _cases,_casereveal;
    int _quantityBombs;
    string _caseImg;



};


#endif
