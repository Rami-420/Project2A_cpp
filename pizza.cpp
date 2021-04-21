#include "pizza.h"
#include <ctime>
pizza::pizza()
{
    ID_pizza = 0;
    prix = 0;
    nb_cals = 0;
    nb_pnt = 0;
    taille = "";
    sauce = "";
    nom = "";
}
pizza::pizza(int ID_pizza, int prix, int nb_cals, int nb_pnt, int taille, bool sauce, QString nom)
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
void pizza::settaille(QString n) { taille = n; }
void pizza::setsauce(QString n) { sauce = n; }
void pizza::setnom(QString n) { nom = n; }

int pizza::get_ID_pizza() { return ID_pizza; }
int pizza::getprix() { return prix; }
int pizza::getnb_cals() { return nb_cals; }
int pizza::getnb_pnt() { return nb_pnt; }
QString pizza::gettaille() { return taille; }
QString pizza::getsauce() { return sauce; }
QString pizza::getnom() { return nom; }

QSqlQueryModel *pizza::afficher_pizza()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    //model->setQuery("SELECT ID_pizza, nom, prix, nb_cals, nb_pnt, taille, sauce, ing_0, ing_1, ing_2, ing_3, ing_4, ing_5, ing_6, ing_7, ing_8, ing_9, ing_10 FROM pizza");
    model->setQuery("SELECT * FROM pizza");
    return model;
}

bool pizza::ajouter_pizza()
{
    srand((unsigned)time(0));
    int a = rand() % 8888 + 1111, b;

    ID_pizza = a;
    QSqlQuery query;
    query.exec("SELECT * FROM client");

    while (query.next())
    {
        b = query.value(0).toInt();
        //qDebug() << b;
        if (ID_pizza == b)
            ID_pizza++;
    }

    QString id_string = QString::number(ID_pizza);
    QString prix_string = QString::number(prix);
    QString nb_cals_string = QString::number(nb_cals);
    QString nb_pnt_string = QString::number(nb_pnt);

    /*QString ing_string[10];
    int i;
    for (i = 0; i < 5; i++)
    {
        //ing_string[i]= "NOO";
    }
*/
    //query.prepare("INSERT INTO pizza (ID_pizza, nom, prix, nb_cals, nb_pnt, taille, sauce, ing_0, ing_1, ing_2, ing_3, ing_4, ing_5, ing_6, ing_7, ing_8, ing_9) VALUES (:ID_pizza, :nom, :prix, :nb_cals,:nb_pnt, :taille, :sauce, :ing_0, :ing_1, :ing_2, :ing_3, :ing_4, :ing_5, :ing_6, :ing_7, :ing_8, :ing_9)");
    query.prepare("INSERT INTO pizza (ID_pizza, nom, prix, nb_cals, nb_pnt, taille, sauce) VALUES (:ID_pizza, :nom, :prix, :nb_cals,:nb_pnt, :taille, :sauce)");
    query.bindValue(":ID_pizza", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prix", prix_string);
    query.bindValue(":nb_cals", nb_cals_string);
    query.bindValue(":nb_pnt", nb_pnt_string);
    query.bindValue(":taille", taille);
    query.bindValue(":sauce", sauce);
    /* query.bindValue(":ing_0", ing_string[0]);
    query.bindValue(":ing_1", ing_string[1]);
    query.bindValue(":ing_2", ing_string[2]);
    query.bindValue(":ing_3", ing_string[3]);
    query.bindValue(":ing_4", ing_string[4]);
    query.bindValue(":ing_5", ing_string[5]);
    query.bindValue(":ing_6", ing_string[6]);
    query.bindValue(":ing_7", ing_string[7]);
    query.bindValue(":ing_8", ing_string[8]);
    query.bindValue(":ing_9", ing_string[9]);*/

    return query.exec();
}

bool pizza::update_pizza(int n)
{
    //trouver_pizza(QString::number(n));
    QString ID = QString::number(n);
    QString prix_string = QString::number(prix);
    QString nb_cals_string = QString::number(nb_cals);
    QString nb_pnt_string = QString::number(nb_pnt);


    QSqlQuery query;
    query.prepare("UPDATE pizza set nom= :nom,prix= :prix,nb_cals= :nb_cals,nb_pnt= :nb_pnt,taille= :taille,sauce= :sauce where ID_pizza= :ID_pizza");
    query.bindValue(":ID_pizza", ID);
    query.bindValue(":nom", nom);
    query.bindValue(":prix", prix_string);
    query.bindValue(":nb_cals", nb_cals_string);
    query.bindValue(":nb_pnt", nb_pnt_string);
    query.bindValue(":taille", taille);
    query.bindValue(":sauce", sauce);

    return query.exec();
}
bool pizza::supprimer_P(int n)
{
    QSqlQuery query;


    query.prepare("Delete FROM pizza where ID_pizza = :id ");
    query.bindValue(":id", n);

    return query.exec();
}
pizza pizza::trouver_pizza(QString n)
{
    pizza p;
    QSqlQuery query;
    //QString n1 = QString::number(n);
    // if (n == "ID ")
    query.exec("SELECT * FROM pizza where ID_pizza = " + n);
    int c;
    QString s;
    while (query.next())
        {
            c = query.value(0).toInt();
            p.set_ID_pizza(c);
            s = query.value(1).toString();
            p.setnom(s);
            c = query.value(2).toInt();
            p.setprix(c);
            c = query.value(3).toInt();
            p.setnb_cals(c);
            c = query.value(4).toInt();
            p.setnb_pnt(c);
            s = query.value(5).toString();
            p.settaille(s);
            s = query.value(6).toString();
            p.setsauce(s);
        }
    // qDebug() <<c << s ;
    return p;
}

QSqlQueryModel* pizza::trieS (QString n )
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM PIZZA ORDER BY "+ n.toUpper() );
    //cout<<"SELECT * FROM PIZZA ORDER BY "<< n.toUpper().toStdString()<< endl;

    return model ;
}

QSqlQueryModel *pizza::recherchePizza(QString i ,QString n,QString o)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from pizza where "+i +" LIKE '"+n+"%' ORDER BY "+o);
    //cout<<"select * from pizza where "<<i.toStdString() <<"LIKE '"<<n.toStdString()<<"%' ORDER BY "<<o.toStdString()<<endl;
 return model;
}
