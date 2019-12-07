//nabil.ayari@sprit.tn
#ifndef HEBERGEMENT_H
#define HEBERGEMENT_H
#include "QDate"
#include "QString"
#include "QSqlQueryModel"

class hebergement
{
public:
    hebergement();

    bool create (QString,QDate,QDate, QString); // ajout

    bool update (QString,QDate ,QDate , QString); // modifier

    bool Delete (QString); // supprimer


    QSqlQueryModel* Read(); // afficher

    QSqlQueryModel* Read1(QString); // afficher

    QSqlQueryModel* Sort(); // chercher

    QSqlQueryModel* Sort1(QString); // chercher


};

#endif // HEBERGEMENT_H
