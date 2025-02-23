#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::numberClickedHandler(int number) {
    // if lause switch sijasta, koska pitää tarkistaa vain yksi
    if (state == 1) {
        number1 += (QString::number(number));
        ui->Box1->setText(number1);
    }
    else {
        number2 += QString::number(number);
        ui->Box2->setText(number2);
    };
};

void MainWindow::clearAndEnterClickHandler(int value) {
    float x = number1.QString::toFloat();
    float y = number2.QString::toFloat();

    if (value == 1) {
        ui->Box3->setText("0");
    }
    else {
        switch (operand) {
            case 1:
                result = x + y;
                break;

            case 2:
                result = x - y;
                break;

            case 3:
                result = x * y;
                break;

            case 4:
                result = x / y;
                break;
        }
        ui->Box3->setText(QString::number(result));
    };

    resetLineEdits();
};

void MainWindow::addSubMulDivClickHandler(int value) {
    state = 2;
    operand = value;
};

void MainWindow::resetLineEdits() {
    result = 0;
    operand = 0;
    state = 1;
    number1 = "";
    number2 = "";
    ui->Box1->setText("0");
    ui->Box2->setText("0");
};

void MainWindow::on_N0_clicked() {
    numberClickedHandler(0);
}

void MainWindow::on_N1_clicked() {
    numberClickedHandler(1);
}

void MainWindow::on_N2_clicked() {
    numberClickedHandler(2);
}

void MainWindow::on_N3_clicked() {
    numberClickedHandler(3);
}

void MainWindow::on_N4_clicked() {
    numberClickedHandler(4);
}

void MainWindow::on_N5_clicked() {
    numberClickedHandler(5);
}

void MainWindow::on_N6_clicked() {
    numberClickedHandler(6);
}

void MainWindow::on_N7_clicked() {
    numberClickedHandler(7);
}

void MainWindow::on_N8_clicked() {
    numberClickedHandler(8);
}

void MainWindow::on_N9_clicked() {
    numberClickedHandler(9);
}

void MainWindow::on_Enter_clicked() {
    clearAndEnterClickHandler(2);
}

void MainWindow::on_Clear_clicked() {
    clearAndEnterClickHandler(1);
}

void MainWindow::on_Plus_clicked(){
    addSubMulDivClickHandler(1);
}

void MainWindow::on_Minus_clicked() {
    addSubMulDivClickHandler(2);
}

void MainWindow::on_Times_clicked() {
    addSubMulDivClickHandler(3);
}

void MainWindow::on_Divide_clicked() {
    addSubMulDivClickHandler(4);
}













