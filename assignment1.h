#ifndef MATRIXTYPE_H
#define MATRIXTYPE_H

#include <iostream>
using namespace std;

const unsigned int MAX_ROWS = 10;
const unsigned int MAX_COLS = 10;

//struct for matrix values
struct MatrixValues {
    unsigned int numRows;
    unsigned int numCols;
    int matrixValues[MAX_ROWS][MAX_COLS];
};

//MatrixType class
class MatrixType {
    MatrixValues values;

public:
    MatrixType();
    MatrixType(unsigned int numRows, unsigned int numCols, int matrixValues[MAX_ROWS][MAX_COLS]);
    void SetSize();
    void SetValues();
    void PrintValues();
    unsigned int GetRows();
    unsigned int GetColumns();
    int GetValue(unsigned int row, unsigned int col);
};

//operation function prototypes
MatrixType Add(MatrixType matrix1, MatrixType matrix2);
MatrixType Sub(MatrixType matrix1, MatrixType matrix2);
MatrixType Multi(MatrixType matrix1, MatrixType matrix2);

//link list & compatibility
struct MatrixNode {
    MatrixType matrix;
    MatrixNode *next;
};

bool AddSubCompatible(MatrixNode *matrix1, MatrixNode *matrix2);
bool MultiCompatible(MatrixNode *matrix1, MatrixNode *matrix2);

//matrix link class
class Matrix {
public:
    MatrixNode *head; 
    Matrix();
    unsigned int GetLength();
    MatrixNode *FindNode(int n);
    void Print();
    void Insert();
};

//wrapper prototypes
MatrixNode *Add(MatrixType matrix1, MatrixType *matrix2);
MatrixNode *Sub(MatrixType matrix1, MatrixType *matrix2);
MatrixNode *Multi(MatrixType matrix1, MatrixType *matrix2);

#endif