//nabil.ayari@sprit.tn
#include "hebergement.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include "QPushButton"
#include "QPropertyAnimation"



hebergement::hebergement()
{

}

bool hebergement::create(QString ID, QDate DATE_ARR, QDate DATE_SORT, QString ID_TYPE) // kima l base
{
    QSqlQuery q;
    q.prepare("INSERT INTO HEBERGEMENT VALUES(:ID,:DATE_ARR,:DATE_SORT,:ID_TYPE)");
    q.bindValue(":ID",ID);
    q.bindValue(":DATE_ARR",DATE_ARR);
    q.bindValue(":DATE_SORT",DATE_SORT);
    q.bindValue(":ID_TYPE",ID_TYPE);
    return(q.exec());
}

bool hebergement::update(QString ID, QDate DATE_ARR, QDate DATE_SORT, QString ID_TYPE)
{
    QSqlQuery q;
    q.prepare("UPDATE HEBERGEMENT SET DATE_ARRIV=:DATE_ARR , DATE_SORT=:DATE_SORT , ID_TYPE=:ID_TYPE  WHERE ID=:ID");
    q.bindValue(":ID",ID);
    q.bindValue(":DATE_ARR",DATE_ARR);
    q.bindValue(":DATE_SORT",DATE_SORT);
    q.bindValue(":ID_TYPE",ID_TYPE);
    return(q.exec());
}

bool hebergement::Delete(QString ID)
{
    QSqlQuery q;
    q.prepare("DELETE FROM HEBERGEMENT WHERE ID=:ID");

    q.bindValue(":ID",ID);

    return(q.exec());
}

QSqlQueryModel *hebergement::Read() // afficher
{


    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM HEBERGEMENT");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date d'arrivée"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date de sortie"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type d'hebergement"));
    return Model;

}

QSqlQueryModel *hebergement::Read1(QString ID) // filtrer
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM HEBERGEMENT WHERE ID LIKE '%"+ID+"%'");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date d'arrivée"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date de sortie"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type d'hebergement"));
    return Model;
}

QSqlQueryModel *hebergement::Sort() // afficher & trier
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM HEBERGEMENT ORDER BY DATE_SORT");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date d'arrivée"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date de sortie"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type d'hebergement"));
    return Model;
}

QSqlQueryModel *hebergement::Sort1(QString ID) // filtrer & trier
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM HEBERGEMENT WHERE ID LIKE '%"+ID+"%' ORDER BY DATE_SORT");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date d'arrivée"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date de sortie"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type d'hebergement"));
    return Model;
}










