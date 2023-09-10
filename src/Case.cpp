#include "Case.h"

Case::Case(){
    this->_cases=false;
    this->_quantityBombs=0;
    this->_caseImg="#";
    this->_casereveal=false;
}

string Case::DisplayCase() const {
    return this->_caseImg;
}
Case::~Case() {}
bool Case::IsBombe() {

    return this->_cases;
}
ostream & operator << (ostream &out, const Case &c)
{
    out << c.DisplayCase()<< endl;
    return out;
}
void Case::TurnCaseInBombe() {

    this->_cases=true;
   // this->ModifyDisplayBombe();
}
void Case::ModifyDisplayBombe() {

    this->_caseImg="M";
}
void Case::DisplayNumberCase() {
    cout<<this->_quantityBombs;
}
void Case::IncreaseValueCase() {
    this->_quantityBombs+=1;
    //this->caseImg=to_string(this->quantiteBombes);
}
bool Case::Isreveal() {
        return this->_casereveal;
}
void Case::TurnCaseReveal(){
    this->_casereveal=true;
}
void Case::DevoilerCaseNbr() {

    if(this->_quantityBombs==0 && !this->_cases)
        this->_caseImg= "X";
    else
        this->_caseImg=to_string(this->_quantityBombs);

}

void Case::HideCase(){
    this->_caseImg="D";
}
int Case::GetNumberCase() {
    return this->_quantityBombs;
}
void Case::TurnCaseInEmpty() {
    this->_caseImg="X";
}

