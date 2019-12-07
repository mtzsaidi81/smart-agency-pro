//nabil.ayari@sprit.tn
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_lineEdit_textChanged(const QString &arg1);


    void on_pushButton_delete_clicked();

    void on_trier_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
