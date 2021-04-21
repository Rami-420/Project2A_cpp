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
    void settaille(QString n);
    void setsauce(QString n);
    void setnom(QString n);
    
    int get_ID_pizza();
    int getprix();
    int getnb_cals();
    int getnb_pnt();
    QString gettaille();
    QString getsauce();
    QString getnom();


    pizza(int ID_pizza, int prix, int nb_cals, int nb_pnt,int taille , bool sauce, QString nom);
    bool ajouter_pizza();
    QSqlQueryModel* afficher_pizza();
    QSqlQueryModel* recherchePizza(QString i ,QString n,QString o);
    QSqlQueryModel* trieS (QString n );
    bool supprimer_pizza(int n);

    bool update_pizza(int n);
    pizza trouver_pizza(QString n);
    bool supprimer_P(int n );
//private:
    int ID_pizza,prix,nb_cals,nb_pnt;
    QString nom,taille, sauce;
    QVector<QString> ingredient;
};

#endif // PIZZA_H
