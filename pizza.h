#ifndef PIZZA_H
#define PIZZA_H
#include "include.h"

class pizza
{
public:
    pizza();
    void set_ID_pizza(int n);
    void setprix(int n);
    void setnb_cals(int n);
    void setnb_pnt(int n);
    void settaille(int n);
    void setsauce(int n);
    void setnom(QString n);
    
    int get_ID_pizza();
    int getprix();
    int getnb_cals();
    int getnb_pnt();
    int gettaille();
    int getsauce();
    QString getnom();


    pizza(int ID_pizza, int prix, int nb_cals, int nb_pnt,int taille , bool sauce, QString nom);
    bool ajouter_pizza();
    QSqlQueryModel* afficher_pizza();
    bool supprimer_pizza(int n);

    bool update_pizza(int n);
    pizza trouver_pizza(QString n);
    bool supprimer_client(int n );
QSqlQueryModel* trieS (QString n );
//private:
    int ID_pizza,prix,nb_cals,nb_pnt,taille, sauce;
    QString nom;
    QVector<QString> ingredient;
};

#endif // PIZZA_H
