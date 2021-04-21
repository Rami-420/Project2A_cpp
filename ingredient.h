#ifndef INGREDIENT_H
#define INGREDIENT_H
#include "include.h"
class ingredient
{
public:
    ingredient();
    ingredient(int ID_ing, int prix, int type, QString nom, QString path);

    void set_ID_ing(int n);
    void setnom(QString n);
    void setprix(int n);
    void settype(int n);
    void setpath(QString n);

    int get_ID_ing();
    QString getnom();
    int getprix();
    int gettype();
    QString getpath();

    bool ajouter_pizza();
    QSqlQueryModel *afficher_pizza();

private:
    int ID_ing, prix, type;
    QString path, nom;
};

#endif // INGREDIENT_H
