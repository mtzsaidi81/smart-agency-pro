#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>


namespace Ui {
class widget1;
}

class widget1 : public QWidget
{
    Q_OBJECT

public:
    explicit widget1(QWidget *parent = nullptr);
    ~widget1();

private slots:
    void on_pushButtonT1_clicked();

    void on_pushButtonT2_clicked();

  //  void on_lineEditT_cursorPositionChanged(int arg1, int arg2);

    void on_lineEditT_cursorPositionChanged(int arg1, int arg2);

    void on_lineEditT_textChanged(const QString &arg1);

    void on_pushButtonT3_clicked();

    void on_PUSHT4_clicked();

private:
    Ui::widget1 *ui;

};

#endif // WIDGET1_H
