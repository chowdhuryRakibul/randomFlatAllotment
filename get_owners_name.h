#ifndef GET_OWNERS_NAME_H
#define GET_OWNERS_NAME_H

#include <QDialog>
#include "resultwindow.h"

namespace Ui {
class GET_OWNERS_NAME;
}

class GET_OWNERS_NAME : public QDialog
{
    Q_OBJECT

public:
    explicit GET_OWNERS_NAME(QWidget *parent = nullptr);
    ~GET_OWNERS_NAME();
    resultWindow *myResultWindow;

private slots:

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::GET_OWNERS_NAME *ui;
//    MainWindow *myMainWindow;

};

#endif // GET_OWNERS_NAME_H
