#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "include.h"
#include "pizza.h"
#include "offre.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    //void on_ajouter_pizza_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_ajouter_pizza_button_clicked();

    void on_pushButton_2_clicked();

    void on_ajouter_plat_button_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_ajouter_offre_button_clicked();

    void on_update_pizza_clicked();

    void on_order_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_recherche_pizza_clicked();

    void on_update_pizza_button_7_clicked();

    void on_delete_pizza_clicked();


private:
    Ui::MainWindow *ui;
    pizza P;
    offre Offre;
};
#endif // MAINWINDOW_H
