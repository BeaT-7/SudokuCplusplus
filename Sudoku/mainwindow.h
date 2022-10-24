#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "puzzle.h"

#include <iostream>
#include <QMainWindow>
#include <QString>
#include <QIntValidator>
#include <QLineEdit>
#include <QPushButton>
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
    QPushButton* back;
    bool setup;
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

};
#endif // MAINWINDOW_H
