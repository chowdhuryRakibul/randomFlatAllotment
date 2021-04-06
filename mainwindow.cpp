#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "main.h"
#include "get_owners_name.h"
#include "QList"
#include "QRandomGenerator"


extern allInfo myAllInfo;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //hide all the labels at the begining
    ui->label_nameOfUnits->hide();
    ui->label_numbeOfFloors->hide();
    ui->label_numberOfUnitsPerFloor->hide();
    ui->label_numberOfGarage->hide();

    ui->spinBox_numberOfFloors->hide();
    ui->spinBox_numberOfGarage->hide();
    ui->spinBox_numberOfUnitsPerFloor->hide();

    ui->lineEdit_nameOfUnit_1->hide();
    ui->lineEdit_nameOfUnit_2->hide();
    ui->lineEdit_nameOfUnit_3->hide();
    ui->lineEdit_nameOfUnit_4->hide();

    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint |Qt::WindowMinimizeButtonHint |Qt::WindowCloseButtonHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_radioButton_garage_clicked()
{
    //hide everything except number of garage
    ui->label_nameOfUnits->hide();
    ui->label_numbeOfFloors->hide();
    ui->label_numberOfUnitsPerFloor->hide();
    ui->label_numberOfGarage->show();

    ui->spinBox_numberOfFloors->hide();
    ui->spinBox_numberOfUnitsPerFloor->hide();
    ui->spinBox_numberOfGarage->show();

    ui->lineEdit_nameOfUnit_1->hide();
    ui->lineEdit_nameOfUnit_2->hide();
    ui->lineEdit_nameOfUnit_3->hide();
    ui->lineEdit_nameOfUnit_4->hide();
}



void MainWindow::on_radioButton_appartment_clicked()
{
    ui->label_nameOfUnits->show();
    ui->label_numbeOfFloors->show();
    ui->label_numberOfUnitsPerFloor->show();
    ui->label_numberOfGarage->hide();

    ui->spinBox_numberOfFloors->show();
    ui->spinBox_numberOfUnitsPerFloor->show();
    ui->spinBox_numberOfGarage->hide();

    ui->lineEdit_nameOfUnit_1->hide();
    ui->lineEdit_nameOfUnit_2->hide();
    ui->lineEdit_nameOfUnit_3->hide();
    ui->lineEdit_nameOfUnit_4->hide();

}

void MainWindow::on_spinBox_numberOfUnitsPerFloor_valueChanged(int arg1)
{
    switch(arg1)
    {
    case 1:
        ui->lineEdit_nameOfUnit_1->show();
        ui->lineEdit_nameOfUnit_2->hide();
        ui->lineEdit_nameOfUnit_3->hide();
        ui->lineEdit_nameOfUnit_4->hide();
        break;
    case 2:
        ui->lineEdit_nameOfUnit_1->show();
        ui->lineEdit_nameOfUnit_2->show();
        ui->lineEdit_nameOfUnit_3->hide();
        ui->lineEdit_nameOfUnit_4->hide();
        break;
    case 3:
        ui->lineEdit_nameOfUnit_1->show();
        ui->lineEdit_nameOfUnit_2->show();
        ui->lineEdit_nameOfUnit_3->show();
        ui->lineEdit_nameOfUnit_4->hide();
        break;
    case 4:
        ui->lineEdit_nameOfUnit_1->show();
        ui->lineEdit_nameOfUnit_2->show();
        ui->lineEdit_nameOfUnit_3->show();
        ui->lineEdit_nameOfUnit_4->show();
        break;
    default:
        ui->lineEdit_nameOfUnit_1->hide();
        ui->lineEdit_nameOfUnit_2->hide();
        ui->lineEdit_nameOfUnit_3->hide();
        ui->lineEdit_nameOfUnit_4->hide();
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    myAllInfo.flatName = ui->lineEdit_nameOfAppartment->text();
    QMessageBox myMsgBox;
    QStringList actualList;
    if(ui->radioButton_appartment->isChecked())
    {
        if(ui->spinBox_numberOfFloors->value()>0)
        {
            if(ui->spinBox_numberOfUnitsPerFloor->value()>0)
            {
                myOwnersName = new GET_OWNERS_NAME(this);
                myOwnersName->show();
                this->hide();

                myAllInfo.numberOfFloors = ui->spinBox_numberOfFloors->value();
                myAllInfo.numberOfUnitPerFloor = ui->spinBox_numberOfUnitsPerFloor->value();
                switch(myAllInfo.numberOfUnitPerFloor)
                {
                case 4:
                    myAllInfo.nameOfUnits<<ui->lineEdit_nameOfUnit_4->text();
                case 3:
                    myAllInfo.nameOfUnits<<ui->lineEdit_nameOfUnit_3->text();
                case 2:
                    myAllInfo.nameOfUnits<<ui->lineEdit_nameOfUnit_2->text();
                case 1:
                    myAllInfo.nameOfUnits<<ui->lineEdit_nameOfUnit_1->text();
                    break;
                default:
                    break;
                }
                for(int i=0;i<myAllInfo.numberOfUnitPerFloor;i++)
                {
                    for(int j=1;j<myAllInfo.numberOfFloors+1;j++)
                    {
                        actualList<<myAllInfo.nameOfUnits.at(i)+QString::number(j);
                    }
                }
                QList<int> a;
                int num;

                while(a.size() != actualList.size())
                {
                    num = QRandomGenerator::global()->generate()%actualList.size();
                    if(!a.contains(num))
                    {
                        a.append(num);
                        myAllInfo.randomizeList<<actualList.at(num);
                    }
                }
            }
            else
            {
                myMsgBox.setText("Number of Units per floor Cannot be 0");
                myMsgBox.exec();
            }
        }
        else
        {
            myMsgBox.setText("Number of Floors cannot be 0");
            myMsgBox.exec();
        }
    }
    else if(ui->radioButton_garage->isChecked())
    {
        if(ui->spinBox_numberOfGarage->value()>0)
        {
            myOwnersName = new GET_OWNERS_NAME(this);
            myOwnersName->show();
            this->hide();

            myAllInfo.numberOfGarage = ui->spinBox_numberOfGarage->value();

        }
        else
        {
            myMsgBox.setText("Number of Garage cannot be 0");
            myMsgBox.exec();
        }
    }
    else
    {
        myMsgBox.setText("You must select either Garage or Appartment");
        myMsgBox.exec();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}
