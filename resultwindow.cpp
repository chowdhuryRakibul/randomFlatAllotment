#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "QThread"
#include "QTime"
#include "QTimer"
#include "main.h"
#include "QPdfWriter"
#include "QDir"
#include "QString"
#include "QDateTime"
#include "QPainter"
#include "QPagedPaintDevice"
#include "QDesktopServices"


extern allInfo myAllInfo;

resultWindow::resultWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultWindow)
{
    ui->setupUi(this);
    myCounter = 10;
    ui->lcdNumber->hide();
    ui->textBrowser->hide();
    ui->pushButton_openPDF->hide();
    ui->pushButton_Exit->hide();

}

resultWindow::~resultWindow()
{
    delete ui;
}

void resultWindow::on_pushButton_clicked()
{
    myTimer = new QTimer(this);
    QObject::connect(myTimer,SIGNAL(timeout()),this,SLOT(updateTime()));
    myTimer->start(1000);
    ui->pushButton->hide();
    ui->lcdNumber->display(10);
    ui->lcdNumber->show();
}

void resultWindow::updateTime()
{
    ui->lcdNumber->display(myCounter);
    myCounter--;
    if(myCounter<0)
    {
        delete myTimer;
        ui->lcdNumber->hide();
        ui->textBrowser->show();
        for(int i=0;i<myAllInfo.finalList.size();i++)
        {
            ui->textBrowser->append(myAllInfo.finalList.at(i));
        }


        if(QDir("C:\\Pacific Flat Allotment").exists())
        {
            QDir().mkdir("C:\\Pacific Flat Allotment");
        }
        resultWindow::fileName = "C:\\Pacific Flat Allotment\\" + myAllInfo.flatName + QDateTime::currentDateTime().toString("_dd_hh_mm_ss") + ".pdf";

        QPdfWriter writer(resultWindow::fileName);
        writer.setPageSize(QPageSize(QPageSize::A4));
        writer.setPageMargins(QMargins(30, 30, 30, 30));

        QPainter painter(&writer);
        painter.setPen(Qt::black);
        painter.setFont(QFont("Times", 12));

        QRect r;

        QString myFinalString;

        myFinalString += "Flat Allocation of " + myAllInfo.flatName;
        painter.setFont(QFont("Times", 16));
        r = painter.viewport();
        painter.drawText(r,Qt::AlignHCenter | Qt::AlignTop,myFinalString);
        myFinalString.clear();
        painter.setFont(QFont("Times", 10));
        r = painter.viewport();
        myFinalString += "\n\nDate: " + QDateTime::currentDateTime().toString("ddd MMMM d, yyyy") + "\n";
        myFinalString += "Time: " + QDateTime::currentDateTime().toString("h:m:s ap") + "\n\n";
        painter.drawText(r,Qt::AlignRight,myFinalString);
        myFinalString.clear();

        myFinalString+="\n\n\n\n";
        for(int i=0;i<myAllInfo.finalList.size();i++)
        {
            myFinalString += myAllInfo.finalList.at(i);
            myFinalString += "\n";
        }
        painter.setFont(QFont("Times", 12));
        r = painter.viewport();
        painter.drawText(r,Qt::AlignLeft,myFinalString);

        painter.end();

        ui->pushButton_openPDF->show();
        ui->pushButton_Exit->show();
    }
}

void resultWindow::on_pushButton_openPDF_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(resultWindow::fileName));
}

void resultWindow::on_pushButton_Exit_clicked()
{
    close();
}
