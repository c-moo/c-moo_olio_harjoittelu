#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_N0_clicked();
    void on_N1_clicked();
    void on_N2_clicked();
    void on_N3_clicked();
    void on_N4_clicked();
    void on_N5_clicked();
    void on_N6_clicked();
    void on_N7_clicked();
    void on_N8_clicked();
    void on_N9_clicked();
    void on_Clear_clicked();
    void on_Enter_clicked();
    void on_Minus_clicked();
    void on_Times_clicked();
    void on_Divide_clicked();
    void on_Plus_clicked();

private:
    Ui::MainWindow *ui;
    QString number1, number2;
    int state = 1;
    float result = 0;
    short operand;

    void numberClickedHandler(int);
    void clearAndEnterClickHandler(int);
    void addSubMulDivClickHandler(int);
    void resetLineEdits();
};

#endif // MAINWINDOW_H
