#include "mainwindow.h"
#include <iostream>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QList>
#include "pizza.h"
#include "plat.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ajouter pizza



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_order_4_clicked()
{


}

void MainWindow::on_ajouter_pizza_button_clicked()
{
    pizza p;
    p.set_ID_pizza(0000);

    p.setprix(ui->ajouter_pizza_prix->text().toInt());
    p.setnb_cals(ui->ajouter_pizza_cals->text().toInt());
    p.setnb_pnt(ui->ajouter_pizza_nb_pnt->text().toInt());

    if (ui->ajouter_pizza_M->isChecked()) {
        p.settaille(0);
    }
    if (ui->ajouter_pizza_L->isChecked()) {
        p.settaille(1);
    }
    if (ui->ajouter_pizza_XL->isChecked()) {
        p.settaille(2);
    }
    if (ui->ajouter_pizza_blanche->isChecked()) {
        p.setsauce(1);
    }
    p.setnom(ui->ajouter_pizza_nom->text());
    p.ajouter_pizza();

}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::on_ajouter_plat_button_clicked()
{
    aasba();
}
