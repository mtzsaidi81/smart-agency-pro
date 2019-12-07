#include "widget.h"
#include "ui_widget.h"
#include "tour.h"
#include "widget1.h"
#include "ui_widget1.h"
#include "QMessageBox"

widget1::widget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget1)
{
    ui->setupUi(this);
    tour R;
    ui->tableViewt->setModel(R.ReadT());

}

widget1::~widget1()
{
    delete ui;
}




void widget1::on_pushButtonT1_clicked()
{


    if (ui->id_t->text()!="" && ui->destination1->currentText()!="" )
    {

      //hebergement He ;
tour R ;
        if (!R.createT(ui->id_t->text(),ui->date_1->dateTime() , ui->date_2->dateTime() ,  ui->destination1->currentText()))

        {
             QMessageBox::warning(nullptr,"Erreur!","Identifiant deja utilisé !");

        }
        else
            ui->tableViewt->setModel(R.ReadT());



    }

    else
        QMessageBox::warning(nullptr,"Erreur!","Rien a ajouter");



}

void widget1::on_pushButtonT2_clicked()
{
    if(ui->tableViewt->currentIndex().row()!=-1) // souris
        {if(ui->destination2->currentText()!="")
{
 tour R ;
 if (! R.updateT(ui->tableViewt->model()->data(ui->tableViewt->model()->index(ui->tableViewt->currentIndex().row(),0)).toString(),ui->date_3->dateTime(),ui->date_4->dateTime(),ui->destination2->currentText()))
                //if (! h.update(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toString(),ui->date_arriv_md_2->date(),ui->date_sort_md_2->date(),ui->comboBox_3->currentText()))
                {

                    QMessageBox::information(nullptr,"Attention!","Erreur ( b.d ) !");

                }
                else{
                    ui->tableViewt->setModel(R.ReadT());
          QMessageBox::information(nullptr,"ok !"," Modification effectuee !");
                }


            }else QMessageBox::information(nullptr,"Attention!","erreur !");
        } else QMessageBox::information(nullptr,"Attention!","indexe invalide!");// pas de clique




}











void widget1::on_lineEditT_textChanged(const QString &arg1)
{





        tour R;

        if(ui->lineEditT->text()=="") // vide
            ui->tableViewt->setModel(R.ReadT()); // recherche normale
        else // filtrer
            ui->tableViewt->setModel(R.Read1T(ui->lineEditT->text())); //recherche avec condition

}




void widget1::on_pushButtonT3_clicked()
{

    if(ui->tableViewt->currentIndex().row()!=-1)
    {
      tour R ;
      if(!R.DeleteT(ui->tableViewt->model()->data(ui->tableViewt->model()->index(ui->tableViewt->currentIndex().row(),0)).toString()))
{
      QMessageBox::warning(nullptr,"Attention!",ui->tableViewt->model()->data(ui->tableViewt->model()->index(ui->tableViewt->currentIndex().row(),0)).toString());

}
      else


      {







          QMessageBox::information(nullptr,"Attention!","Suppression effectuée !");

          ui->tableViewt->setModel(R.ReadT());





      }
}
}

void widget1::on_PUSHT4_clicked()
{


        tour R;
        if(ui->lineEditT->text()=="")
            ui->tableViewt->setModel(R.SortT());
        else
            ui->tableViewt->setModel(R.Sort1T(ui->lineEditT->text()));


}


