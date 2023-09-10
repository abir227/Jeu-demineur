#include "Jeu.h"
#include "Grille.h"
#include <fstream>
#include <string>
using namespace std;


Jeu::Jeu()
{
    //ctor
}

Jeu::~Jeu()
{
    //dtor
}
void Jeu::MessageGameStart() {


cout<<"----------  JEU DEMINEUR ------------\n"
        <<"1- Commencer"
        <<"2- Quitter \n"
        <<"-----------       -----------"
        <<endl;

    cout << "Entrez un choix valide (1 - 2): "<<endl;


    int option= ValidationOptionNumber();


    this->ChoicePlay(option);
}

void Jeu::ChoicePlay(int choix) {

    switch(choix) {
        case 1  :
            LevelBeginner();
            break;
        case 2  :
            Exit();
            break; //optional
        default :
            cout << "vous devez entrer un choix valide choissisez(1 ou 2)!!! \n";
            MessageGameStart();
            break;
    }
}
void  Jeu::LevelBeginner() {
      int n,b;
      cout << "donner la taille de votre grille" <<endl;
      cin >> n ;
      cout << "donner le nombre de bombes" <<endl;
      cin >> b ;
    this->grille = Grille(n,n,b);
    this->grille.LookForBombs();
    cout<<" Bienvenue au Jeu démineur"<<endl;
    cout << "nombre de mines : " << b<< endl;
    cout << "nombre de coups : " << this->grille.Getcoups()<<endl;
    this->grille.PrintGrilles();
    MenuGameStarted();

}
void Jeu::GoToMenuPrincipal(){

    this->grille.DeleteCases();
    MessageGameStart();

}
void Jeu::MenuGameStarted(){

   cout<<""<<endl;
    cout<<"1- Voulez-vous ouvrir une case choix(1) "<<endl;
    cout<<"2 -Voulez-vous mettre un drapeau choix(2)"<<endl;
    cout<<""<<endl;

    cout << "Entrez un choix valide (1 ou 2): "<<endl;

    int option =ValidationOptionNumber();
    ChoiceAction(option);
}

void Jeu::ChoiceAction(int choix){
        switch(choix){
            case 1:
                 this->grille.setcoups();
                 GetCoordinatesXY();
                 break;
            case 2:
                this->grille.setcoups();
                GetCoordinatesXYdr();
                break;
            default :
                 MenuGameStarted();
                 break;
            }
}
void Jeu::GetCoordinatesXY(){

    cout<<"Donner les coordonnées de la case:"<<endl;
    cout << "ligne X ="<<endl;

    int optionx=ValidationCoordinates();
    cout << " colonne Y ="<<endl;

    int optiony=ValidationCoordinates();
     Play(optionx,optiony);
}
void Jeu::GetCoordinatesXYdr(){

    cout<<"Donner les coordonnées de la case:"<<endl;
    cout << "ligne X ="<<endl;
    int optionx=ValidationCoordinates();
    cout << "colonne Y ="<<endl;
    int optiony=ValidationCoordinates();
    flag(optionx,optiony);
}

void Jeu::Exit() {
    cout<<"EXIT"<<endl;
}
void Jeu::flag (int x,int y){
    cout << "nombre de mines : " << this->grille.Getbombes()<< endl;
    cout << "nombre de coups : " << this->grille.Getcoups()<<endl;
    this->grille.GetCases()[x][y].HideCase();
    this->grille.PrintGrilles();
    this->MenuGameStarted();
}
void Jeu::Play(int x,int y ){
    cout << "nombre de mines : " << this->grille.Getbombes()<< endl;
    cout << "nombre de coups : " << this->grille.Getcoups()<<endl;
    if(this->grille.GetCases()[x][y].IsBombe()) {
           this->grille.GetCases()[x][y].Isreveal();
            cout<<"VOUS AVEZ PERDU !!!!!"<<endl;
            cout<<"! ---VOICI LE PLATEAU SUR LEQUEL VOUS AVEZ JOUÉ --!"<<endl;
            this->grille.RevealAllCases();
            this->grille.PrintGrilles();
            cout<<" *** FIN JEU DEMINEUR ***"<<endl;
            MessageGameStart();
        }
        else {
            this->grille.LookAllCasesEmptys(x, y);
            if(this->grille.Win()){
                this->grille.PrintGrilles();
                cout<<"!!!!!! VOUS AVEZ GAGNÉ !!!!!!!"<<endl;
                cout << "donner votre nom" << endl;
                char nom [15];
                cin >> nom;
                //cout << nom << endl ;
                FILE * f;
                f = fopen ("score.txt", "a");
                fprintf (f, "Nom :  %s ", nom );
                fprintf (f, " score : %d \n", this->grille.Getcoups());
                fclose (f);
                this->MessageGameStart();
            }
            else{
                this->grille.PrintGrilles();
                this->MenuGameStarted();
            }
        }
}
int Jeu::ValidationOptionNumber(){
    int numberoption;

    cin >> numberoption;
    while(!cin)
    {
        cout << "1- Validation !!! La valeur saisie n'est pas un entier Entrez un entier !!! ) \n"<<endl;
        cin.clear();
        cin.ignore();
        cin >> numberoption;
    }
    return numberoption;
}
int Jeu::ValidationCoordinates(){

    int coordinates=0;
    bool verificationcoord=false;
    cin >> coordinates;
    while(!cin || !verificationcoord){
    while(!cin )
    {
        cout << "1- Validation - !!! La valeur saisi n'est pas un entier Entrez un entier !!! ) \n"<<endl;
        cin.clear();
        cin.ignore();
        cin >> coordinates;
    }
    if(coordinates<0 || coordinates >= this->grille.Getrows()){
            cout << "2 -Validation - Coordonnees !!!coordonnees saisi sont hors de la grille (entre 0 - "<< this->grille.Getrows() <<") /n "<<endl;
            cin.clear();
            cin.ignore();
            cin >> coordinates;
      }
      else{
          verificationcoord=true;
      }

    }


    return coordinates;



}

