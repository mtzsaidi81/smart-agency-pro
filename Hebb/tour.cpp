//nabil.ayari@sprit.tn
#include "tour.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include "QPushButton"
#include "QPropertyAnimation"



tour::tour()
{

}

bool tour::createT(QString ID_TOUR, QDateTime DATE_D, QDateTime DATE_F, QString DESTINATION) // kima l base
{
    QSqlQuery q;
    q.prepare("INSERT INTO TOUR VALUES(:ID_TOUR,:DATE_D,:DATE_F,:DESTINATION)");
    q.bindValue(":ID_TOUR",ID_TOUR);
    q.bindValue(":DATE_D",DATE_D);
    q.bindValue(":DATE_F",DATE_F);
    q.bindValue(":DESTINATION",DESTINATION);
    return(q.exec());
}

bool tour::updateT(QString ID_TOUR, QDateTime DATE_D, QDateTime DATE_F, QString DESTINANTION)
{
    QSqlQuery q;
    q.prepare("UPDATE TOUR SET DATE_D=:DATE_D , DATE_F=:DATE_F, DESTINANTION=:Destinantion  WHERE ID_D=:ID_D");
    q.bindValue(":ID_TOUR",ID_TOUR);
    q.bindValue(":DATE_D",DATE_D);
    q.bindValue(":DATE_F",DATE_F);
    q.bindValue(":DESTINANTION",DESTINANTION);
    return(q.exec());
}

bool tour::DeleteT(QString ID_TOUR)
{
    QSqlQuery q;
    q.prepare("DELETE FROM TOUR WHERE ID_TOUR=:ID_TOUR");

    q.bindValue(":ID_TOUR",ID_TOUR);

    return(q.exec());
}

QSqlQueryModel *tour::ReadT() // afficher
{


    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM TOUR");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date de debut"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date de fin"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Destinantion"));
    return Model;

}

QSqlQueryModel *tour::Read1T(QString ID_TOUR) // filtrer
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM TOUR WHERE ID_TOUR LIKE '%"+ID_TOUR+"%'");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date de debut"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date de fin"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Destinantion"));
    return Model;
}

QSqlQueryModel *tour::SortT() // afficher & trier
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM TOUR ORDER BY DATE_F");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date de debut"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date de fin"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Destinantion"));
    return Model;
}

QSqlQueryModel *tour::Sort1T(QString ID_TOUR) // filtrer & trier
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM HEBERGEMENT WHERE ID_TOUR LIKE '%"+ID_TOUR+"%' ORDER BY DATE_D");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date de debut"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date de fin"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Destinantion"));
    return Model;
}





