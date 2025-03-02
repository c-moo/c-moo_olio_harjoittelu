#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timeout();
    void updateProgressBar();
    void setGameInfoText(QString);

private slots:
    void on_player1Button_clicked();
    void on_player2Button_clicked();
    void on_timer_120_clicked();
    void on_timer_5min_clicked();
    void on_StartGame_clicked();
    void on_StopGame_clicked();

private:
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer *pQTimer;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
