#include "connection.h"

#include <iostream>
using namespace std;

Connection::Connection()
{
}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Project2A"); //inserer le nom de la source de données ODBC
    db.setUserName("rami");          //inserer nom de l'utilisateur
    db.setPassword("esprit");        //inserer mot de passe de cet utilisateur

    QSqlQuery query;
    QMessageBox msgBoxC;


    if (db.open())
    {
        test = true;
    }
    return test;
}
