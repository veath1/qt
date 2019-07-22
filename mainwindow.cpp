#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include "stdio.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    moeny=moeny+10;
    ui->lcdNumber->display(moeny);

}

void MainWindow::on_lcdNumber_overflow()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    moeny=moeny+100;
    ui->lcdNumber->display(moeny);
}

void MainWindow::on_pushButton_3_clicked()
{
    if(moeny>=100){
        moeny=moeny-100;
        ui->lcdNumber->display(moeny);
    }else {
        QMessageBox::question(this,"return","not enough moeny",NULL);
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    if(moeny>=100){
        moeny=moeny-100;
        ui->lcdNumber->display(moeny);
    }else {
        QMessageBox::question(this,"return","not enough moeny",NULL);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    char buf[256];
    int cout[3]={0,0,0};
    int coin[]={500,100,10};
    if(moeny==0){
               QMessageBox::question(this,"return","반환 금액 없음",NULL);
    }else {

        int n=moeny;
        int num=0;
        for(int i=0;i<3;i++){
            int num=0;
            while(n>coin[i]){
                n -= coin[i];
                num++;
            }
            cout[i]=num;

        }

           sprintf(buf,"500 :%d, 100 : %d, 10 : %d",cout[0],cout[1],cout[2]+1);
           moeny=0;
           ui->lcdNumber->display(moeny);
           QMessageBox::question(this,"return",buf,NULL);
    }

    }



void MainWindow::on_pushButton_6_clicked()
{
    moeny=moeny+500;
    ui->lcdNumber->display(moeny);
}
