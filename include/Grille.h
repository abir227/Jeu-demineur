#ifndef GRILLE_H
#define GRILLE_H
#include "Case.h"

class Grille{

public:
    Grille(int rows, int columns,int bombes);
    Grille();

    int LookAllCasesEmptys(int posr,int poc);
    void LookForBombs();

    void PrintGrilles();
    int Getrows() const;
    int Getcolumns() const;
    int Getcoups() const;
    int Getbombes() const;
    void setcoups();
      void DeleteCases();

      bool Win();
      void RevealAllCases();
    Case **& GetCases() ;
    ~Grille();

private:

    Case **_grillecases;
    void CreateColumnsDynamic();
    int _rows;//x
    int _columns;//y
    int _bombes;
    int coups;
    bool _caseempty;
    bool _gameover;
};


#endif	/* GRILLE_H */

