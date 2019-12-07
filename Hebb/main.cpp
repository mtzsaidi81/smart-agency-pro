//nabil.ayari@sprit.tn
#include "widget.h"
#include "connexion.h"
#include "QtDebug"
#include "QPushButton"
#include "QPropertyAnimation"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion C;


    if(C.ouvrirConnexion())
        qDebug() << "database opened";
    Widget w;
    w.show();

    //*******


    return a.exec();
}
