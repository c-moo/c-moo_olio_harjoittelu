#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // setting variables here that I could do in the header but -_(O.O)_-
    ui->player1Bar->setMinimum(0);
    ui->player2Bar->setMinimum(0);
    ui->player1Button->setEnabled(false);
    ui->player2Button->setEnabled(false);
    ui->StopGame->setEnabled(false);
    ui->StartGame->setEnabled(false);
    currentPlayer = -1;
}

MainWindow::~MainWindow() {
    delete ui;
    if(pQTimer)
    {
        pQTimer->stop();
        delete pQTimer;
        pQTimer=nullptr;
    }
}

void MainWindow::updateProgressBar() {
    if (player1Time <= 0) {
        setGameInfoText("Player 2 won!");
        timeout();
    }
    else if (player2Time <= 0) {
        setGameInfoText("Player 1 won!");
        timeout();
    }

    if (currentPlayer == 1) {
        ui->player1Bar->setValue(player1Time);
        --player1Time; // decrement value by one same as var = var - 1;
    }
    else {
        ui->player2Bar->setValue(player2Time);
        --player2Time;
    }
};

void MainWindow::timeout() {
    if(pQTimer) {
    pQTimer->stop();
    delete pQTimer;
    pQTimer=nullptr;
    currentPlayer = -1;
     ui->player1Button->setEnabled(false);
     ui->player2Button->setEnabled(false);
     ui->StopGame->setEnabled(false);
     ui->timer_120->setEnabled(true);
     ui->timer_5min->setEnabled(true);
     ui->StartGame->setEnabled(true);
    }
}

void MainWindow::setGameInfoText(QString text) {
    ui->label->setText(text);                   // don't know how to actually make text bigger so I didn't add it
};

void MainWindow::on_player1Button_clicked() {
    currentPlayer = 0;
     ui->player2Button->setEnabled(true);
     ui->player1Button->setEnabled(false);
}

void MainWindow::on_player2Button_clicked() {
    currentPlayer = 1;
    ui->player2Button->setEnabled(false);
    ui->player1Button->setEnabled(true);
}


void MainWindow::on_timer_120_clicked() {
    gameTime = 120;
    ui->player1Bar->setMaximum(gameTime);
    ui->player2Bar->setMaximum(gameTime);
    ui->player1Bar->setValue(gameTime);
    ui->player2Bar->setValue(gameTime);
    ui->StartGame->setEnabled(true);
    setGameInfoText("Start the game with a 120 second timer");
}


void MainWindow::on_timer_5min_clicked() {
    gameTime = 300;
    ui->player1Bar->setMaximum(gameTime);
    ui->player2Bar->setMaximum(gameTime);
    ui->player1Bar->setValue(gameTime);
    ui->player2Bar->setValue(gameTime);
    ui->StartGame->setEnabled(true);
    setGameInfoText("Start the game with a 5min timer");
}


void MainWindow::on_StartGame_clicked() {

    player1Time = gameTime;
    player2Time = gameTime;
    currentPlayer = 1;
    ui->player2Button->setEnabled(false);

    pQTimer = new QTimer(this);
    connect(
        pQTimer,
        &QTimer::timeout,
        this,
        &MainWindow::updateProgressBar
        );
    pQTimer->start(1000);

    ui->player1Button->setEnabled(true);
    ui->StopGame->setEnabled(true);
    ui->timer_120->setEnabled(false);
    ui->timer_5min->setEnabled(false);
    ui->StartGame->setEnabled(false);

    setGameInfoText("Game started!");
}


void MainWindow::on_StopGame_clicked() {
    setGameInfoText("Game stopped");
    timeout();
}

