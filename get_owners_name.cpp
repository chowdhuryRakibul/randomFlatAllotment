#include "get_owners_name.h"
#include "ui_get_owners_name.h"
#include "mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include "main.h"
#include "QRandomGenerator"
#include "QStringList"


extern allInfo myAllInfo;

GET_OWNERS_NAME::GET_OWNERS_NAME(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GET_OWNERS_NAME)
{
    ui->setupUi(this);
    QWidget::showMaximized();
}

GET_OWNERS_NAME::~GET_OWNERS_NAME()
{
    delete ui;
}

void GET_OWNERS_NAME::on_pushButton_5_clicked()
{
    close();
}

void GET_OWNERS_NAME::on_pushButton_clicked()
{
    myAllInfo.ownersName.clear();
    ui->textBrowser->clear();
    QString fileName;
    QMessageBox myMessageBox;
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Owners' Name"), "", tr("txt Files (*.txt)"));
    if(fileName.size()<=0)
    {
        return;
    }

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        myMessageBox.setText("Erro Opeing File");
    }
    QTextStream in(&file);

    QStringList actualList;

    while(!in.atEnd())
    {
        QString line = in.readLine();
        actualList<<line;
    }
    file.close();
    actualList.sort();
    for(int j=0;j<actualList.length();j++)
    {
        ui->textBrowser->append(actualList.at(j));
    }

    if(actualList.length()<(myAllInfo.numberOfFloors*myAllInfo.numberOfUnitPerFloor))
    {
        QMessageBox::warning(this, tr("Pacific Appartments"),
                                       tr("There is less owners than number of flats/garage.\n"
                                          "Please try again"),
                           QMessageBox::Ok);
        return;
    }

    QList<int> a;
    int num;
    QString separator(" : ");

    while(a.size() != actualList.size())
    {
        num = QRandomGenerator::global()->generate()%actualList.size();
        if(!a.contains(num))
        {
            a.append(num);
            myAllInfo.ownersName<<actualList.at(num);
        }
    }
    for(int i=0;i<myAllInfo.randomizeList.size();i++)
    {
        myAllInfo.finalList<<myAllInfo.randomizeList.at(i) + separator + myAllInfo.ownersName.at(i);
    }
    myAllInfo.finalList.sort();
    qDebug()<<myAllInfo.finalList;
}

void GET_OWNERS_NAME::on_pushButton_4_clicked()
{
    myResultWindow = new resultWindow(this);
    this->hide();
    myResultWindow->show();

}
