#ifndef OFFRE_H
#define OFFRE_H

#include "pizza.h"
#include "include.h"
class offre
{
public:
    offre();
    void set_ID_offre(int n);
    void setprix(int n);
    void setnb_cals(int n);
    void setnb_pnt(int n);
    void setpath(QString n);
    void setnom(QString n);

    int get_ID_offre();
    int getprix();
    int getnb_cals();
    int getnb_pnt();
    QString getpath();
    QString getnom();

    offre(int ID_offre, int prix, int nb_cals, int nb_pnt, QString path, QString nom);
    bool ajouter_offre();
    QSqlQueryModel *afficher_offre();
    bool supprimer_offre(int n);
    void trouver_offre(int n);
    //private:
    int ID_offre, prix, nb_cals, nb_pnt;
    QString nom,path;
    vector<pizza> P;
};

#endif // OFFRE_H

/*CREATE TABLE  "PIZZA"
   (	"ID_PIZZA" NUMBER, 
	"NOM" VARCHAR2(20), 
	"PRIX" NUMBER, 
	"NB_CALS" NUMBER, 
	"NB_PNT" NUMBER, 
   "TAILLE" VARCHAR2(20), 
	"SAUCE" VARCHAR2(20), 
	"ING_0" VARCHAR2(20), 
	"ING_1" VARCHAR2(20), 
	"ING_2" VARCHAR2(20), 
	"ING_3" VARCHAR2(20), 
	"ING_4" VARCHAR2(20), 
	"ING_5" VARCHAR2(20), 
	"ING_6" VARCHAR2(20), 
	"ING_7" VARCHAR2(20), 
	"ING_8" VARCHAR2(20), 
	"ING_9" VARCHAR2(20), 
   "ING_10" VARCHAR2(20)
   )


CREATE TABLE  "OFFRE" 
   (	"ID_OFFRE" NUMBER, 
	"PRIX" NUMBER, 
	"NB_CALS" NUMBER, 
	"NB_PNT" NUMBER, 
	"NOM" VARCHAR2(20), 
	"PATH" VARCHAR2(50), 
	"PIZZA_0" NUMBER, 
	"PIZZA_1" NUMBER, 
	"PIZZA_2" NUMBER, 
	"PIZZA_3" NUMBER, 
	"PIZZA_4" NUMBER, 
	"PIZZA_5" NUMBER, 
	"PIZZA_6" NUMBER, 
	"PIZZA_7" NUMBER, 
	"PIZZA_8" NUMBER, 
	"PIZZA_9" NUMBER
   )*/
