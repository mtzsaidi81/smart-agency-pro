#ifndef MENUU_H
#define MENUU_H

#include <QWidget>

namespace Ui {
class menuu;
}

class menuu : public QWidget
{
    Q_OBJECT

public:
    explicit menuu(QWidget *parent = nullptr);
    ~menuu();

private:
    Ui::menuu *ui;
};

#endif // MENUU_H
