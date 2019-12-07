#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
#include "widget.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username = ui->lineEdit_ussername->text();
    QString password = ui->lineEdit_password->text();
    if ( username == "test" && password == "test" )
    {
    QMessageBox::information(this , "Login " , "Username and password is correct ");



   //widget= new Widget(this);
    widget.show();





    }
    else
    {
    QMessageBox::warning(this,"Login" , "Username and password is not correct " );
    }
    }

