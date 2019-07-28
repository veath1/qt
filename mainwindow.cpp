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
void MainWindow::sett(){
     if(moeny==0) ui->pushButton_5->setEnabled(false);
     else ui->pushButton_5->setEnabled(true);
     if(moeny<100) ui->pushButton_3->setEnabled(false);
     else ui->pushButton_3->setEnabled(true);
     if(moeny<200) ui->pushButton_4->setEnabled(false);
     else ui->pushButton_4->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{

    moeny=moeny+10;
    ui->lcdNumber->display(moeny);
    sett();
}

void MainWindow::on_lcdNumber_overflow()
{
    QMessageBox::information(this,"nop","제한 입력 초과",NULL);
}

void MainWindow::on_pushButton_2_clicked()
{
    moeny=moeny+100;
    ui->lcdNumber->display(moeny);
    sett();
}


void MainWindow::on_pushButton_3_clicked()
{

    if(moeny>=100){
        moeny=moeny-100;
        ui->lcdNumber->display(moeny);
    }else {
        QMessageBox::information(this,"nop","not enough moeny");
    }
    sett();
}

void MainWindow::on_pushButton_4_clicked()
{

    if(moeny>=200){
        moeny=moeny-200;
        ui->lcdNumber->display(moeny);
    }else {
        ui->lcdNumber->display(moeny);
        QMessageBox::information(this,"return","not enough moeny");
    }
    sett();
}

void MainWindow::on_pushButton_5_clicked()
{
    char buf[256];
    int cout[4]={0,0,0,0};
    int coin[]={500,100,50,10};
    if(moeny==0){
               QMessageBox::information(this,"return","반환 금액 없음");
    }else {

        int n=moeny;
        int num=0;
        for(int i=0;i<4;i++){
            int num=0;

            while(n>=coin[i]){
                n -= coin[i];
                num++;
            }
            cout[i]=num;

        }

           sprintf(buf,"500 :%d, 100 : %d,50 : %d, 10 : %d",cout[0],cout[1],cout[2],cout[3]);
           moeny=0;
           ui->lcdNumber->display(moeny);
           QMessageBox::information(this,"return",buf,NULL);
    }
    sett();
    }



void MainWindow::on_pushButton_6_clicked()
{
    moeny=moeny+500;
    ui->lcdNumber->display(moeny);
    sett();
}

void MainWindow::on_pushButton_7_clicked()
{
    moeny=moeny+50;
    ui->lcdNumber->display(moeny);
    sett();
}
