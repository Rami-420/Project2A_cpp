#include "plat.h"
#include <QStringList>
#include <vector>
#include <QtDebug>
#include <QSqlError>
plat::plat()
{
    int i;
    ID_plat = 0;
    prix = 0;
    nb_cals = 0;
    nb_pnt = 0;
    for (i = 0; i <= 10; i++)
    {
        //ID_ingredient.push_back(-1);
    }
    nom = "";
}
plat::plat(int ID_plat, int prix, int nb_cals, int nb_pnt,/* vector ID_ingredient,*/ QString nom)
{
    this->ID_plat = ID_plat;
    this->prix = prix;
    this->nb_cals = nb_cals;
    this->nb_pnt = nb_pnt;
    //this->ID_ingredient = ID_ingredient;
    this->nom = nom;
}

void plat::set_ID_plat(int n) { ID_plat = n; }
void plat::setprix(int n) { prix = n; }
void plat::setnb_cals(int n) { nb_cals = n; }
void plat::setnb_pnt(int n) { nb_pnt = n; }
//void plat::setID_ing(vector n) { ID_ingredient = n; }
void plat::setnom(QString n) { nom = n; }

int plat::get_ID_plat() { return ID_plat; }
int plat::getprix() { return prix; }
int plat::getnb_cals() { return nb_cals; }
int plat::getnb_pnt() { return nb_pnt; }
//vector plat::getID_ing() { return ID_ingredient; }
QString plat::getnom() { return nom; }

bool plat::ajouter_plat()
{
    int i;
    QSqlQuery query;
    QString id_string = QString::number(ID_plat);
    QString prix_string = QString::number(prix);
    QString nb_cals_string = QString::number(nb_cals);
    QString nb_pnt_string = QString::number(nb_pnt);
    QString ID_ing_string[10];
    for (i = 0; i <= 10; i++)
    {
        //ID_ing_string[i] = QString::number(ID_ingredient[i]);
    }

    query.prepare("INSERT INTO plat (ID_plat, nom, prix, nb_cals, ing0, ing1, ing2, ing3, ing4, ing5, ing6, ing7, ing8, ing9, ing10 ) VALUES (:ID_plat, :nom, :prix, :nb_cals, :ing0, :ing1, :ing2, :ing3, :ing4, :ing5, :ing6, :ing7, :ing8, :ing9, :ing10)");
    query.bindValue(":ID_plat", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prix", prix_string);
    query.bindValue(":nb_cals", nb_cals_string);
    query.bindValue(":ing0", ID_ing_string[0]);
    query.bindValue(":ing1", ID_ing_string[1]);
    query.bindValue(":ing2", ID_ing_string[2]);
    query.bindValue(":ing3", ID_ing_string[3]);
    query.bindValue(":ing4", ID_ing_string[4]);
    query.bindValue(":ing5", ID_ing_string[5]);
    query.bindValue(":ing6", ID_ing_string[6]);
    query.bindValue(":ing7", ID_ing_string[7]);
    query.bindValue(":ing8", ID_ing_string[8]);
    query.bindValue(":ing9", ID_ing_string[9]);

    return query.exec();
}

void aasba(){
    QSqlDatabase db;
        db=QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("TEST.DB");
        db.open();
        QString namee;
        QSqlQuery sql;
        if(db.isValid()) {
            if(db.tables().isEmpty()) {
                sql.exec("CREATE TABLE \"users\" ( `ID` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, `username` TEXT NOT NULL, `pass` TEXT NOT NULL, `userGroup` INTEGER NOT NULL)");

            }
            sql.prepare("INSERT INTO users (username, pass, userGroup) VALUES (:name, :pass, :group)");
            sql.bindValue(":name", "Test Name");
            sql.bindValue(":pass", "Test Pass");
            sql.bindValue(":group", "0");
            //sql.bindValue(0,namee);
            sql.exec();
            if(sql.numRowsAffected() != 1) {
                qDebug() << sql.lastError();
                qDebug() << sql.lastQuery();
            }
            else qDebug() << "Num Rows Affected : " << sql.numRowsAffected();
        }
        else qDebug() << db.lastError();


}

bool plat::supprimer_plat(int n)
{
    QSqlQuery query;

    query.prepare("DELETE FROM plat where id = :id ");
    query.bindValue(":id", n);
    return query.exec();
}

void plat::trouver_plat(int n)
{

    QSqlQuery query;
    plat p;

    query.prepare("SELECT id  FROM plat where id = :id ");
    query.bindValue(":id", n);
    query.exec();
    set_ID_plat(query.boundValue(0).toInt());
    QSqlQuery query1;
    query1.prepare("SELECT nom  FROM plat where id = :id ");
    query1.bindValue(":id", n);
    query1.exec();
    setnom(query1.boundValue(0).toString());
}

