#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}
/*
void MainWindow::numberClickedHandler() {

};

void MainWindow::clearAndEnterClickHandler() {

};

void MainWindow::addSubMulDivClickHandler() {

};

void MainWindow::resetLineEdits() {

};
*/

void MainWindow::on_Count_clicked() {
    count += 1;
    ui->lineEdit->setText(QString::number(count));
};

void MainWindow::on_Reset_clicked() {
    count = 0;
    ui->lineEdit->setText("0");
};

