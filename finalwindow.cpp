#include "finalwindow.h"
#include "ui_finalwindow.h"

finalWindow::finalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finalWindow)
{
    ui->setupUi(this);
}

finalWindow::~finalWindow()
{
    delete ui;
}
