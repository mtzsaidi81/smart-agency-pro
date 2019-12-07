//nabil.ayari@sprit.tn
#include "widget.h"
#include "ui_widget.h"
#include "hebergement.h"
#include "QMessageBox"

/*
#include "QPushButton"
#include "QPropertyAnimation"

*/


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    hebergement He;

    ui->tableView->setModel(He.Read());

}



Widget::~Widget()
{
    delete ui;
}




void Widget::on_pushButton_2_clicked()
{
    if (ui->id->text()!="" && ui->type_id->currentText()!="" )
    {

      hebergement He ;

        if (!He.create(ui->id->text(),ui->date_arriv->date() , ui->date_sort->date() ,  ui->type_id->currentText()))

        {
             QMessageBox::warning(nullptr,"Erreur!","Identifiant deja utilisé !");

        }
        else
            ui->tableView->setModel(He.Read());



    }

    else
        QMessageBox::warning(nullptr,"Erreur!","Rien a ajouter");



    }









void Widget::on_pushButton_3_clicked() // button update
{
    if(ui->tableView->currentIndex().row()!=-1) // souris
        {if(ui->comboBox_2->currentText()!="")
{
                hebergement h;
                if (! h.update(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toString(),ui->date_arriv_md->date(),ui->date_sort_md->date(),ui->comboBox_2->currentText()))
                {

                    QMessageBox::information(nullptr,"Attention!","Erreur ( b.d ) !");

                }
                else{
                    ui->tableView->setModel(h.Read());
          QMessageBox::information(nullptr,"ok !"," Modification effectuee !");
                }


            }else QMessageBox::information(nullptr,"Attention!","erreur !");
        } else QMessageBox::information(nullptr,"Attention!","indexe invalide!");// pas de clique




    }








void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    hebergement he;
    if(ui->lineEdit->text()=="") // vide
        ui->tableView->setModel(he.Read()); // recherche normale
    else // filtrer
        ui->tableView->setModel(he.Read1(ui->lineEdit->text())); //recherche avec condition
}




/*
void Widget::on_pushButton_4_clicked()
{

}
*/

void Widget::on_pushButton_delete_clicked() // delete
{




    if(ui->tableView->currentIndex().row()!=-1)
    {
      hebergement he ;
      if(!he.Delete(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toString()))
{
      QMessageBox::warning(nullptr,"Attention!",ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toString());

}
      else


      {







          QMessageBox::information(nullptr,"Attention!","Suppression effectuée !");

          ui->tableView->setModel(he.Read());





      }
}
}



void Widget::on_trier_clicked()
{

    hebergement he;
    if(ui->lineEdit->text()=="")
        ui->tableView->setModel(he.Sort());
    else
        ui->tableView->setModel(he.Sort1(ui->lineEdit->text()));

}
