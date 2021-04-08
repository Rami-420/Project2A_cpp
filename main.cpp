#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //connection
    Connection c;
    bool test=c.createconnect();
    if(test) w.show();
/*        QMessageBox::information(nullptr, QObject::tr("database is open "),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open TEST"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

*/
    //.qss
    /*
    QFile file("E:/Project C++/Qt/Menu/DeepBox.qss");
        file.open(QFile::ReadOnly);

        QString styleSheet { QLatin1Literal(file.readAll()) };

        //setup stylesheet
        a.setStyleSheet(styleSheet);
    */

    w.show();
    return a.exec();
}
