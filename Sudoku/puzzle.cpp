#include "puzzle.h"
#include <QString>

Puzzle::Puzzle()
{
    QString fullpath = QCoreApplication::applicationDirPath() + "/puzzleCollection.txt";
    puzzles = new int**[5];
    std::fstream file;
    file.open(fullpath.toStdString(), std::ios::in);
    //file.open("puzzleCollection.txt", std::ios::in);
    //file.open("F:/Programming/C++/Sudoku/puzzleCollection.txt", std::ios::in);
    char c;
    file.get(c);
    for (int i = 0; i < 5; i++){
        puzzles[i] = new int*[9];
        for (int j = 0; j < 9; j++){
            puzzles[i][j] = new int[9];
            for (int a = 0; a < 9; a++){
                puzzles[i][j][a] = c-'0';
                file.get(c);
                file.get(c);
            }
        }
        file.get(c);
    }
    file.close();

    field = new int*[9];
    for (int i = 0; i < 9; i++){
        field[i] = new int[9];
    }
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            field[i][j] = 0;
        }
    }

}
Puzzle::~Puzzle(){
    for (int i = 0; i < 9; i++) delete field[i];
    delete field;

    puzzles = new int**[5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 9; j++){
            delete puzzles[i][j];
        }
        delete puzzles[i];
    }
    delete puzzles;
}

void Puzzle::fillField(){
    srand(time(NULL));
    int randNum = rand() % 5;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            field[i][j] = puzzles[randNum][i][j];
        }
    }
}

int Puzzle::getFieldValue(int i, int j){
    return field[i][j];
}

void Puzzle::setValue(int i, int j, int val){
    field[i][j] = val;
}

bool Puzzle::isValidNum(int row, int col, int val){
    if (isValidRow(row,col,val) && isValidCol(row,col,val) && isValidBlock(row,col,val)) return true;
    return false;
}

bool Puzzle::isValidRow(int row, int col, int val){
    for(int i = 0; i < 9; i++){
        if (field[row][i] == val && i != col) return false;
    }
    return true;
}

bool Puzzle::isValidCol(int row, int col, int val){
    for(int i = 0; i < 9; i++){
        if (field[i][col] == val && i != row) return false;
    }
    return true;
}

bool Puzzle::isValidBlock(int row, int col, int val){
    int blockRow = row/3*3;
    int blockCol = col/3*3;
    for (int i = blockRow; i < blockRow+3; i++){
        for (int j = blockCol; j < blockCol+3; j++){
            if (field[i][j] == val && i != row && j != col) return false;
        }
    }
    return true;
}
