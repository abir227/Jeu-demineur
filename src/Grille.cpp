#include "Grille.h"
#include <iostream>
using namespace std;


Grille::Grille() {
    this->_columns=9;
    this->_rows=9;
    this->_bombes=0;
    this->coups=0;
    this->_caseempty=false;
    this->_gameover=false;
    this->CreateColumnsDynamic();
}

Grille::Grille(int rows, int columns, int bombes) {
    this->_columns=columns;
    this->_rows=rows;
    this->_bombes=bombes;
    this->coups=0;
    this->_gameover=false;
    this->_caseempty=false;
       this->CreateColumnsDynamic();

}

void Grille::CreateColumnsDynamic() {
    this->_grillecases=new Case*[this->_rows];
    for (int row = 0; row < _rows; ++row)
        this->_grillecases[row]= new Case[_columns];


            for (int i=0; i< this->_bombes ; i++){
                     int x1= rand()%this->_bombes ;
                     int y1= rand()%this->_bombes ;
                     this->_grillecases[x1][y1].TurnCaseInBombe();
                  }
}
 int Grille:: Getrows() const{
     return this->_rows;
 }
 int Grille::Getcolumns() const {
     return this->_columns;
 }
 int Grille::Getcoups() const {
     return this->coups;
 }
  int Grille::Getbombes() const {
     return this->_bombes;
 }
  void Grille::setcoups() {
     this->coups = this->coups+1;}
// lorsqu'on trouve une case vide va chercher
int Grille::LookAllCasesEmptys(int row,int col) {
    //Case** &grille,
    if (row>this->_rows-1 || row<0 || col>this->_columns-1 || col<0){ //numero de ligne ou de colomne non adéquat
        return -1;
    }
    if(this->_grillecases[row][col].IsBombe()){ // le contenu de la case est une bombe
        return 0;
    }

    if(this->_grillecases[row][col].Isreveal()){ // la case est déja découverte
        return 1;
    }
    if(this->_grillecases[row][col].GetNumberCase()>0){ // il existe des bombes autour de la case
        this->_grillecases[row ][col].TurnCaseReveal(); //casereveal= true
    }
    if (this->_grillecases[row ][col].GetNumberCase() == 0) {
            this->_grillecases[row ][col].TurnCaseReveal();
            if (LookAllCasesEmptys(row - 1, col - 1) == 1) { //fct recursive , verification pour tous les voisins
                LookAllCasesEmptys(row - 1, col - 1);
            }
            if (LookAllCasesEmptys(row + 1, col + 1) == 1) {
                LookAllCasesEmptys(row + 1, col + 1);
            }
            if (LookAllCasesEmptys( row -1, col ) == 1) {
                LookAllCasesEmptys(row - 1, col );
            }
            if(LookAllCasesEmptys(row-1,col+1)==1){
                LookAllCasesEmptys(row - 1, col+1 );
            }
            if(LookAllCasesEmptys(row,col-1)==1){
                LookAllCasesEmptys(row,col-1);
            }
            if(LookAllCasesEmptys(row,col+1)==1){
                LookAllCasesEmptys(row,col+1);
            }
            if(LookAllCasesEmptys(row+1,col-1)==1){
               LookAllCasesEmptys(row+1,col-1);
            }
            if(LookAllCasesEmptys(row+1,col)==1){
               LookAllCasesEmptys(row+1,col);
            }
        }
}
// chercher les bombes et modifier le nombre de Case toutes le cases ont pare defaut 0 comme valeur
void Grille::LookForBombs() {

    for (int row = 0; row < this->Getrows(); ++row) {

        for (int col = 0; col < this->Getcolumns(); ++col) {

            if (this->_grillecases[row][col].IsBombe()) { // si la case est une bombe on va changer le nombredecase des cases voisins
                if (row + 1 < this->Getrows())
                    this->_grillecases[row + 1][col].IncreaseValueCase();
                if (row - 1 > -1)
                    this->_grillecases[row - 1][col].IncreaseValueCase();
                if (col + 1 < this->Getcolumns()) {
                    this->_grillecases[row][col + 1].IncreaseValueCase();
                    if (row - 1 > -1)
                        this->_grillecases[row - 1][col + 1].IncreaseValueCase();
                    if (row + 1 < this->Getrows())
                        this->_grillecases[row + 1][col + 1].IncreaseValueCase();
                }
                if (col - 1 > -1) {
                    this->_grillecases[row][col - 1].IncreaseValueCase();
                    if (row - 1 > -1)
                        this->_grillecases[row - 1][col - 1].IncreaseValueCase();
                    if (row + 1 <  this->Getrows())
                        this->_grillecases[row + 1][col - 1].IncreaseValueCase();
                }
            }

        }

    }

}
Grille::~Grille(){

}

Case **& Grille::GetCases() {
    return this->_grillecases;
}

void Grille::DeleteCases(){
    delete [] this->_grillecases;
}
void Grille::PrintGrilles(){
    cout << "" << endl;
     for (int g = 0; g < 50; ++g) {
                cout << "**";
            }
            cout << endl;
            cout << endl;

        cout << "                                        ";
    for (int j = 0; j < this->Getcolumns(); ++j){
        cout << " "<<j ;}
        cout << endl;
    for (int i = 0; i < this->Getrows(); ++i) {
         cout <<"                                       "<<i ;
        for (int j = 0; j < this->Getcolumns(); ++j) {

            if (this->_grillecases[i][j].Isreveal()) {
                this->_grillecases[i][j].DevoilerCaseNbr();
            }
            if(this->_gameover && this->_grillecases[i][j].IsBombe()){
                this->_grillecases[i][j].ModifyDisplayBombe();
            }
            cout <<" " << this->_grillecases[i][j].DisplayCase();

        }
        cout << endl;
        if (i == this->Getrows()-1) {
            cout << endl;
            for (int g = 0; g < 50; ++g)

                cout << "**";
            cout << endl;
        }
    }

}
bool Grille::Win(){

    int nbrbombs= this ->_bombes;
    int casestotal=this->_columns*this->_rows;
    int cases=casestotal-nbrbombs;
    int compteurcasereveals=0;
    for (int row=0; row<Getrows(); ++row){
        for(int col=0; col<Getcolumns();++col){
            if(this->_grillecases[row][col].Isreveal())
                compteurcasereveals+=1;
        }
    }
    if(compteurcasereveals==cases){
        this->_gameover=true;
        return true;

    }
    return false;
 }
void Grille::RevealAllCases(){

    for (int row=0; row<Getrows(); ++row){
            for(int col=0; col<Getcolumns();++col){
                this->_grillecases[row][col].TurnCaseReveal();
            }
        }
    this->_gameover=true;
}
