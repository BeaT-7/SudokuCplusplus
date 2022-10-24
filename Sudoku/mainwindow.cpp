#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "puzzle.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    puzzle = new Puzzle;
    validInput = new QIntValidator(1,9,this);

    // stylesheets for puzzles input boxes
    staticVal = "font-size:20px; background-color:LightGray; color: black;";
    staticValInval = "font-size:20px; background-color:lightcoral; color: black;";
    dynamicVal = "font-size:20px; background-color:LightGray; color: dimgray";
    dynamicValInval = "font-size:20px; background-color:lightcoral; color: dimgray;";

    // Game won text
    gameWonText = new QLabel;
    gameWonText->hide();
    gameWonText->setStyleSheet("font-size: 35px; color: green; font-weight: bold;");
    gameWonText->setGeometry(170,60,500,50);
    gameWonText->setText("Game finished, you WON!!");
    this->layout()->addWidget(gameWonText);

    // Back button
    back = new QPushButton;
    back->setGeometry(20,20,80,25);
    back->setText("Back");
    back->setStyleSheet("background-color: LightGray; font-weight: bold; font-size: 22px;");
    back->hide();
    this->layout()->addWidget(back);
    connect(back, &QPushButton::clicked,[this](){this->showStartScreen();});

    int x = 230, y = 150;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            inputBoxes[i][j] = new QLineEdit;
            inputBoxes[i][j]->setGeometry(x,y,30,30);
            this->layout()->addWidget(inputBoxes[i][j]);
            inputBoxes[i][j]->setValidator(validInput);
            inputBoxes[i][j]->setStyleSheet(dynamicVal);
            inputBoxes[i][j]->setObjectName("box");
            inputBoxes[i][j]->setAlignment(Qt::AlignCenter);
            inputBoxes[i][j]->hide();
            x += ((j+1)%3==0)?36:31;
            connect(inputBoxes[i][j], &QLineEdit::textChanged,
                    [this, i, j](){this->newInput(i,j);});
        }
        y+= ((i+1)%3==0)?36:31;
        x=230;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete puzzle;
    delete validInput;
}

void MainWindow::on_StartGameBtn_clicked()
{
    setup = true;
    ui->StartGameBtn->hide();
    this->startGame();
    setup = false;
}

void MainWindow::showStartScreen(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            inputBoxes[i][j]->hide();
            inputBoxes[i][j]->setReadOnly(false);
            inputBoxes[i][j]->setObjectName("box");
        }
    }
    back->hide();
    gameWonText->hide();
    ui->StartGameBtn->show();
}

void MainWindow::startGame(){
    puzzle->fillField();
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            QString newVal = QString::number(puzzle->getFieldValue(i, j));
            inputBoxes[i][j]->setText((newVal.toInt() < 1)?"":newVal);
            if (newVal.toInt() > 0) {
                inputBoxes[i][j]->setReadOnly(true);
                inputBoxes[i][j]->setStyleSheet("font-size:20px; background-color:LightGray; color: black;");
                inputBoxes[i][j]->setObjectName("static");
            }
            inputBoxes[i][j]->show();
        }
    }
    back->show();
}

void MainWindow::newInput(int i, int j){
    int curVal = inputBoxes[i][j]->text().toInt();
    if (inputBoxes[i][j]->text().toInt()==0) inputBoxes[i][j]->setText(""); // blocks "0" as input
    puzzle->setValue(i, j, curVal);
    if (!setup) colorBlocks();
    if (gameFinished) gameWon();
}

void MainWindow::colorBlocks(){
    gameFinished = true;
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            int val = inputBoxes[i][j]->text().toInt();
            if (val < 1) gameFinished = false;
            if(!puzzle->isValidNum(i,j,val) && val != 0 && inputBoxes[i][j]->objectName() == "static"){
                inputBoxes[i][j]->setStyleSheet(staticValInval);
                gameFinished=false;
            } else if(!puzzle->isValidNum(i,j,val) && val != 0){
                inputBoxes[i][j]->setStyleSheet(dynamicValInval);
                gameFinished=false;
            } else if(inputBoxes[i][j]->objectName() == "static") {
                inputBoxes[i][j]->setStyleSheet(staticVal);
            } else{
                inputBoxes[i][j]->setStyleSheet(dynamicVal);
            }
        }
    }
}

void MainWindow::gameWon(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            inputBoxes[i][j]->setReadOnly(true);
        }
    }
    gameWonText->show();
}
