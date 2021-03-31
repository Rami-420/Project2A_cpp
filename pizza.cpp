#include "pizza.h"



pizza::pizza()
{
    ID_pizza = 0;
    prix = 0;
    nb_cals = 0;
    nb_pnt = 0;
    taille = 0;
    sauce = 0;
    nom = "";
}
pizza::pizza(int ID_pizza, int prix, int nb_cals, int nb_pnt,int taille , bool sauce, QString nom)
{
    this->ID_pizza = ID_pizza;
    this->prix = prix;
    this->nb_cals = nb_cals;
    this->nb_pnt = nb_pnt;
    this->taille = taille;
    this->sauce = sauce;
    this->nom = nom;
}

void pizza::set_ID_pizza(int n) { ID_pizza = n; }
void pizza::setprix(int n) { prix = n; }
void pizza::setnb_cals(int n) { nb_cals = n; }
void pizza::setnb_pnt(int n) { nb_pnt = n; }
void pizza::settaille(int n) {taille  = n; }
void pizza::setsauce(bool n) {sauce  = n; }
void pizza::setnom(QString n) { nom = n; }

int pizza::get_ID_pizza() { return ID_pizza; }
int pizza::getprix() { return prix; }
int pizza::getnb_cals() { return nb_cals; }
int pizza::getnb_pnt() { return nb_pnt; }
int pizza::gettaille() { return taille; }
bool pizza::getsauce() { return sauce; }
QString pizza::getnom() { return nom; }

QSqlQueryModel* pizza::afficher_pizza()
{
 QSqlQueryModel* model = new QSqlQueryModel();


 model->setQuery("SELECT id, nom, prenom, adresse, mail, telephone, num_CB, CF FROM client ");


 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("num_CB"));
 model->setHeaderData(7, Qt::Horizontal, QObject::tr("CF"));



 return model ;
}

bool pizza::ajouter_pizza(){
    cout <<"\n zok om il 3icha";
    cout <<"\n nom : "<< nom.toStdString();
    cout <<"\n sauce : "<< sauce;
    cout <<"\n taille: "<< taille;

    return true;
}
