#include "offre.h"

offre::offre()
{
    ID_offre = 0;
    prix = 0;
    nb_cals = 0;
    nb_pnt = 0;
    path = "";
    nom = "";
    int i;
    pizza p;
    p.ID_pizza = -1;
    for (i = 0; i <= 10; i++)
    {
        P.push_back(p);
    }
}
offre::offre(int ID_offre, int prix, int nb_cals, int nb_pnt, QString path, QString nom)
{
    this->ID_offre = ID_offre;
    this->prix = prix;
    this->nb_cals = nb_cals;
    this->nb_pnt = nb_pnt;
    this->path = path;
    this->nom = nom;
}

void offre::set_ID_offre(int n) { ID_offre = n; }
void offre::setprix(int n) { prix = n; }
void offre::setnb_cals(int n) { nb_cals = n; }
void offre::setnb_pnt(int n) { nb_pnt = n; }
void offre::setpath(QString n) { path = n; }
void offre::setnom(QString n) { nom = n; }

int offre::get_ID_offre(){ return ID_offre;}
int offre::getprix() { return prix; }
int offre::getnb_cals() { return nb_cals; }
int offre::getnb_pnt() { return nb_pnt; }
QString offre::getpath() { return path; }
QString offre::getnom() { return nom; }

QSqlQueryModel *offre::afficher_offre()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT ID_offre, prix, nb_cals, nb_pnt, nom, pizza_0,pizza_1,pizza_2,pizza_3,pizza_4,pizza_5,pizza_6,pizza_7,pizza_8,pizza_9 FROM offre ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_offre"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_cals"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_pnt"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pizza_0"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pizza_1"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pizza_2"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pizza_3"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pizza_4"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pizza_5"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pizza_6"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pizza_7"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pizza_8"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pizza_9"));

    return model;
}

bool offre::ajouter_offre()
{
    cout << "\n nom : " << nom.toStdString();
    cout << "\n path: " << path.toStdString();

    QSqlQuery query;
    QString id_string = QString::number(ID_offre);
    QString prix_string = QString::number(prix);
    QString nb_cals_string = QString::number(nb_cals);
    QString nb_pnt_string = QString::number(nb_pnt);
    QString Pizza[10];

    int i;
    for (i = 0; i <= 10; i++)
    {
        Pizza[i] = P[i].getnom();
    }
//    query.prepare("INSERT INTO offre (ID_offre, prix, nb_cals, nb_pnt, nom, path, pizza_0,pizza_1,pizza_2,pizza_3,pizza_4,pizza_5,pizza_6,pizza_7,pizza_8,pizza_9 ) VALUES (:ID_offre, :prix, :nb_cals, :nb_pnt, :nom, :path, :pizza_0 , :pizza_1 , :pizza_2 , :pizza_3 , :pizza_4 , :pizza_5 , :pizza_6 , :pizza_7 , :pizza_8 , :pizza_9)");

    query.prepare("INSERT INTO offre (ID_offre, prix, nb_cals, nb_pnt, nom, path ) VALUES (:ID_offre, :prix, :nb_cals, :nb_pnt, :nom, :path)");
    query.bindValue(":ID_offre", id_string);
    query.bindValue(":prix", prix_string);
    query.bindValue(":nb_cals", nb_cals_string);
    query.bindValue(":nb_pnt", nb_pnt_string);
    query.bindValue(":nom", nom);
    query.bindValue(":path", path);
/*
    query.bindValue(":pizza_0", Pizza[0]);
    query.bindValue(":pizza_1", Pizza[1]);
    query.bindValue(":pizza_2", Pizza[2]);
    query.bindValue(":pizza_3", Pizza[3]);
    query.bindValue(":pizza_4", Pizza[4]);
    query.bindValue(":pizza_5", Pizza[5]);
    query.bindValue(":pizza_6", Pizza[6]);
    query.bindValue(":pizza_7", Pizza[7]);
    query.bindValue(":pizza_8", Pizza[8]);
    query.bindValue(":pizza_9", Pizza[9]);
*/
    return query.exec();
}
