#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "puzzle.h"

#include <iostream>
#include <QMainWindow>
#include <QString>
#include <QIntValidator>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "qlayout.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Puzzle * puzzle;
    QIntValidator * validInput;
    QLineEdit* inputBoxes[9][9];
    QLabel* gameWonText;
    QPushButton* back;
    bool setup;
    bool gameFinished;
    QString staticVal;
    QString dynamicVal;
    QString staticValInval;
    QString dynamicValInval;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_StartGameBtn_clicked();


private:
    Ui::MainWindow *ui;
    void startGame();
    void showStartScreen();
    void newInput(int i, int j);
    void colorBlocks();
    void gameWon();

};
#endif // MAINWINDOW_H
