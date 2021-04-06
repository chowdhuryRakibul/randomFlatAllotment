#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>

namespace Ui {
class resultWindow;
}

class resultWindow : public QDialog
{
    Q_OBJECT

public:
    explicit resultWindow(QWidget *parent = nullptr);
    ~resultWindow();

private slots:
    void on_pushButton_clicked();
    void updateTime();

    void on_pushButton_openPDF_clicked();

    void on_pushButton_Exit_clicked();

private:
    Ui::resultWindow *ui;
    QTimer *myTimer;
    int myCounter;
    QString fileName;
};

#endif // RESULTWINDOW_H
