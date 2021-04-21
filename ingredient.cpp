#include "ingredient.h"

ingredient::ingredient()
{
    ID_ing = 0;
    prix = 0;
    type =0;
    nom = "";
    path="";
}
ingredient::ingredient(int ID_ingredient, int prix, int type, QString path, QString nom)
{
    this->ID_ing = ID_ingredient;
    this->prix = prix;
    this->path = path;
    this->type = type;
    this->nom = nom;
}

void ingredient::set_ID_ing(int n) { ID_ing = n; }
void ingredient::setprix(int n) { prix = n; }
void ingredient::settype(int n) { type = n; }
void ingredient::setpath(QString n) { path = n; }
void ingredient::setnom(QString n) { nom = n; }

int ingredient::get_ID_ing() { return ID_ing; }
int ingredient::getprix() { return prix; }
int ingredient::gettype() { return type; }
QString ingredient::getpath() { return path; }
QString ingredient::getnom() { return nom; }
