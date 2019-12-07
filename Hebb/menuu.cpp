#include "menuu.h"
#include "ui_menuu.h"

menuu::menuu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menuu)
{
    ui->setupUi(this);
}

menuu::~menuu()
{
    delete ui;
}
