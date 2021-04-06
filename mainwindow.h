#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "get_owners_name.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_radioButton_garage_clicked();

    void on_radioButton_appartment_clicked();

    void on_spinBox_numberOfUnitsPerFloor_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    GET_OWNERS_NAME *myOwnersName;
};

#endif // MAINWINDOW_H
