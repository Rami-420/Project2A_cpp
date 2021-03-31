#ifndef PLAT_H
#define PLAT_H
#include "include.h"

class plat
{
public:
    void set_ID_plat(int n);
    void setprix(int n);
    void setnb_cals(int n);
    void setnb_pnt(int n);
    //void setID_ing(vector<int> n);
    void setnom(QString n);
    int get_ID_plat();
    int getprix();
    int getnb_cals();
    int getnb_pnt();
    //vector getID_ing();
    QString getnom();
    plat();
    plat(int ID_plat, int prix, int nb_cals, int nb_pnt,/* vector ID_ingredient,*/ QString nom);
    bool ajouter_plat();
    bool supprimer_plat(int n);
    void trouver_plat(int n);

    //vector<int> ID_ingredient;
private:
    int ID_plat, prix,nb_cals,nb_pnt;
    //vector<int> ID_ingredient;
    QString nom;
};

    void aasba ();
#endif // PLAT_H
