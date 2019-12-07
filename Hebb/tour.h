//nabil.ayari@sprit.tn
#ifndef TOUR_H
#define TOUR_H
#include "QDate"
#include "QString"
#include "QSqlQueryModel"

class tour
{
public:
    tour();

    bool createT (QString,QDateTime,QDateTime, QString); // ajout

    bool updateT (QString,QDateTime ,QDateTime , QString); // modifier

    bool DeleteT (QString); // supprimer


    QSqlQueryModel* ReadT(); // afficher

    QSqlQueryModel* Read1T(QString); // afficher

    QSqlQueryModel* SortT(); // chercher

    QSqlQueryModel* Sort1T(QString); // chercher


};


#endif // TOUR_H
