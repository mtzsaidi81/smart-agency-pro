#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include"widget.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    Widget widget ;
};

#endif // LOGIN_H
