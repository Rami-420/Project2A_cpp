#include "mainwindow.h"
#include <iostream>
#include "ui_mainwindow.h"
#include "include.h"
#include "pizza.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->afficher_pizza_list->setModel(P.afficher_pizza());
    ui->afficher_pizza_list->setModel(P.afficher_pizza());
    //ui->afficher_offre_list->setModel(Offre.afficher_offre());
    //ajouter pizza
    P.supprimer_client(22);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_pizza_button_clicked()
{
    cout << "ADDING... ";
    pizza p;


    p.setprix(ui->ajouter_pizza_prix->text().toInt());
    p.setnb_cals(ui->ajouter_pizza_cals->text().toInt());
    p.setnb_pnt(ui->ajouter_pizza_nb_pnt->text().toInt());

    if (ui->ajouter_pizza_M->isChecked())
    {
        p.settaille(1);
    }
    if (ui->ajouter_pizza_L->isChecked())
    {
        p.settaille(2);
    }
    if (ui->ajouter_pizza_XL->isChecked())
    {
        p.settaille(3);
    }
    if (ui->ajouter_pizza_blanche->isChecked())
    {
        p.setsauce(1);
    }
    if (ui->ajouter_pizza_rouge->isChecked())
    {
        p.setsauce(2);
    }

    p.setnom(ui->ajouter_pizza_nom->text());
/*
    QVector<QString> V;

    QList<QListWidgetItem *> selection = ui->ajouter_pizza_ing->selectedItems();
    int S = selection.size();
    cout<<"S= " <<S<< endl;
    std::vector<int> indices;
    for (int i = 0; i <= S; i++)
    {

        indices.push_back(ui->ajouter_pizza_ing->row(selection[i]));
        cout<<"ind= "<< indices.at(i)<<endl;
    }

    for (int j = 0; j <= S; j++)
    {
       QString k=ui->ajouter_pizza_ing->takeItem(indices.at(j))->text();
       p.ingredient.push_back(k);
        cout <<"ing "<<j<<"= "<< k.toStdString()<<endl;
    }
*/
    if (p.ajouter_pizza())
    {
        cout << "ajoute complet";
    }
    else
        cout << "ERROOR";
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::on_ajouter_plat_button_clicked()
{
    //TEST();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->sidebar->setCurrentIndex(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    pizza p ;

    if (ui->afficher_pizza_search->currentText()=="ID" )
        p.trouver_pizza(ui->lineEdit_9->text());

    if (ui->afficher_pizza_search->currentText()=="Nom" )
        p.trouver_pizza(ui->lineEdit_9->text());
        p.trieS(ui->afficher_pizza_sort->currentText());
}

void MainWindow::on_ajouter_offre_button_clicked()
{
    offre O;
    //O.set_ID_offre(0000);
    O.setnom(ui->ajouter_offre_nom->text());
    O.setpath(ui->ajouter_offre_path->text());
    O.setprix(ui->ajouter_offre_prix->text().toInt());
    O.setnb_cals(ui->ajouter_offre_cals->text().toInt());
    O.setnb_pnt(ui->ajouter_offre_nb_pnt->text().toInt());
/*
    QList<QListWidgetItem *> selection = ui->ajouter_offre_listPizza->selectedItems();
    int S = selection.size();
    std::vector<int> indices;
    for (int i = 0; i < S; i++)
        indices.push_back(ui->ajouter_offre_listPizza->row(selection[i]));

    pizza pi;
    for (int j = 0; j < S; j++)
    {
        int id_p;
        id_p = ui->ajouter_pizza_ing->takeItem(indices.at(j))->text().toInt();
        pi.set_ID_pizza(id_p);

        O.P.push_back(pi);
    }
*/
}

void MainWindow::on_update_pizza_clicked()
{
    pizza p;
    int n=ui->update_id->text().toInt();
    cout<<"N= "<<n;


ui->ajouter_pizza_prix_2->setText(QString :: number(p.getprix()));
ui->ajouter_pizza_cals_2->setText(QString :: number(p.getnb_cals()));
ui->ajouter_pizza_nb_pnt_2->setText(QString :: number (p.getnb_pnt()));

       p.setprix(ui->ajouter_pizza_prix_2->text().toInt());
    p.setnb_cals(ui->ajouter_pizza_cals_2->text().toInt());
     p.setnb_pnt(ui->ajouter_pizza_nb_pnt_2->text().toInt());

    if (ui->ajouter_pizza_M_2->isChecked())
    {
        p.settaille(1);
    }
    if (ui->ajouter_pizza_L_2->isChecked())
    {
        p.settaille(2);
    }
    if (ui->ajouter_pizza_XL_2->isChecked())
    {
        p.settaille(3);
    }
    if (ui->ajouter_pizza_blanche_2->isChecked())
    {
        p.setsauce(1);
    }
    if (ui->ajouter_pizza_rouge_2->isChecked())
    {
        p.setsauce(2);
    }

    p.setnom(ui->ajouter_pizza_nom_2->text());
     p.update_pizza(ui->update_id->text().toInt());
}



