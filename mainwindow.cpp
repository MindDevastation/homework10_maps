#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Start->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Check_clicked()
{
    QString inputString;
    inputString.append(ui->lineEdit->text());

    for(int i=0; i < inputString.length(); i++){
        if(inputString.at(i) >= '0' && inputString.at(i) <= '9' || inputString.at(i) == ' '){
            ui->status->setText("Status: OK");
            ui->Start->setEnabled(true);
        }else{
            ui->status->setText("Status: ERROR!");
        }
    }

}


void MainWindow::on_Start_clicked()
{
    this->myMap.clearInfo();
    QString inputString;
    inputString.append(ui->lineEdit->text());
    this->myMap.setLine(inputString);

    int res = this->myMap.findLucky();
    ui->label->setNum(res);

    ui->status->setText("Status: Job Done!");
    ui->Start->setEnabled(false);
}

