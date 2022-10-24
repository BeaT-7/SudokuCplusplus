#ifndef PUZZLE_H
#define PUZZLE_H

#include <QString>
#include <fstream>
#include <cstdlib>
#include <QCoreApplication>


class Puzzle
{
   int ** field;
   int *** puzzles;

public:
    Puzzle();
    ~Puzzle();

    void fillField();
    void setValue(int i, int j, int val);
    int getFieldValue(int i, int j);
    bool isValidNum(int row, int col, int val);
    bool isValidRow(int row, int col, int val);
    bool isValidCol(int row, int col, int val);
    bool isValidBlock(int row, int col, int val);
};

#endif // PUZZLE_H
