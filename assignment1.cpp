#include "assignment1.h"

// Default constructor: empty matrix
MatrixType::MatrixType() {
    values.numRows = 0;
    values.numCols = 0;
}

// Initialized constructor
MatrixType::MatrixType(unsigned int numRows, unsigned int numCols, int matrixValues[MAX_ROWS][MAX_COLS]) {
    values.numRows = numRows;
    values.numCols = numCols;
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numCols; j++) {
            values.matrixValues[i][j] = matrixValues[i][j];
        }
    }
}

void MatrixType::SetSize() {
    cout << "A matrix has been created. Enter the number of rows and columns for this new matrix:" << endl;
    cin >> values.numRows;
    cin >> values.numCols;
}

void MatrixType::SetValues() {
    cout << "Enter the values:" << endl;
    for (unsigned int i = 0; i < values.numRows; i++) {
        for (unsigned int j = 0; j < values.numCols; j++) {
            cin >> values.matrixValues[i][j];
        }
    }
}

void MatrixType::PrintValues() {
    for (unsigned int i = 0; i < values.numRows; i++) {
        for (unsigned int j = 0; j < values.numCols; j++) {
            cout << values.matrixValues[i][j] << " ";
        }
        cout << endl;
    }
}

unsigned int MatrixType::GetRows() {
    return values.numRows;
}

unsigned int MatrixType::GetColumns() {
    return values.numCols;
}

int MatrixType::GetValue(unsigned int row, unsigned int col) {
    if (row < values.numRows && col < values.numCols) {
        return values.matrixValues[row][col];
    }
    return 0;
}

// --- Operation Functions ---
MatrixType Add(MatrixType matrix1, MatrixType matrix2) {
    int resultArr[MAX_ROWS][MAX_COLS] = {0};
    for (unsigned int i = 0; i < matrix1.GetRows(); i++) {
        for (unsigned int j = 0; j < matrix1.GetColumns(); j++) {
            resultArr[i][j] = matrix1.GetValue(i, j) + matrix2.GetValue(i, j);
        }
    }
    return MatrixType(matrix1.GetRows(), matrix1.GetColumns(), resultArr);
}

MatrixType Sub(MatrixType matrix1, MatrixType matrix2) {
    int resultArr[MAX_ROWS][MAX_COLS] = {0};
    for (unsigned int i = 0; i < matrix1.GetRows(); i++) {
        for (unsigned int j = 0; j < matrix1.GetColumns(); j++) {
            resultArr[i][j] = matrix1.GetValue(i, j) - matrix2.GetValue(i, j);
        }
    }
    return MatrixType(matrix1.GetRows(), matrix1.GetColumns(), resultArr);
}

MatrixType Multi(MatrixType matrix1, MatrixType matrix2) {
    int resultArr[MAX_ROWS][MAX_COLS] = {0};
    for (unsigned int i = 0; i < matrix1.GetRows(); i++) {
        for (unsigned int j = 0; j < matrix2.GetColumns(); j++) {
            for (unsigned int k = 0; k < matrix1.GetColumns(); k++) {
                resultArr[i][j] += matrix1.GetValue(i, k) * matrix2.GetValue(k, j);
            }
        }
    }
    return MatrixType(matrix1.GetRows(), matrix2.GetColumns(), resultArr);
}

// --- Compatibility Functions ---
bool AddSubCompatible(MatrixNode *matrix1, MatrixNode *matrix2) {
    return (matrix1->matrix.GetRows() == matrix2->matrix.GetRows() &&
            matrix1->matrix.GetColumns() == matrix2->matrix.GetColumns());
}

bool MultiCompatible(MatrixNode *matrix1, MatrixNode *matrix2) {
    return (matrix1->matrix.GetColumns() == matrix2->matrix.GetRows());
}

// --- Matrix List Class Implementation ---
Matrix::Matrix() {
    head = nullptr;
}

unsigned int Matrix::GetLength() {
    unsigned int count = 0;
    MatrixNode *current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

MatrixNode *Matrix::FindNode(int n) {
    if (n < 1 || n > GetLength()) return nullptr;
    MatrixNode *current = head;
    for (int i = 1; i < n; i++) {
        current = current->next;
    }
    return current;
}

void Matrix::Print() {
    if (head == nullptr) {
        cout << "No matrices in the list." << endl;
        return;
    }
    cout << "All matrices are in the following." << endl;
    MatrixNode *current = head;
    int index = 1;
    while (current != nullptr) {
        cout << "Matrix " << index << ":" << endl;
        current->matrix.PrintValues();
        current = current->next;
        index++;
    }
}

void Matrix::Insert() {
    MatrixType newMatrix;
    newMatrix.SetSize();
    newMatrix.SetValues();
    
    MatrixNode *newNode = new MatrixNode;
    newNode->matrix = newMatrix;
    newNode->next = head;
    head = newNode;
}

// --- Wrapper Functions for List Operations ---
MatrixNode *Add(MatrixType matrix1, MatrixType *matrix2) {
    MatrixNode *newNode = new MatrixNode;
    newNode->matrix = Add(matrix1, *matrix2);
    newNode->next = nullptr;
    return newNode;
}

MatrixNode *Sub(MatrixType matrix1, MatrixType *matrix2) {
    MatrixNode *newNode = new MatrixNode;
    newNode->matrix = Sub(matrix1, *matrix2);
    newNode->next = nullptr;
    return newNode;
}

MatrixNode *Multi(MatrixType matrix1, MatrixType *matrix2) {
    MatrixNode *newNode = new MatrixNode;
    newNode->matrix = Multi(matrix1, *matrix2);
    newNode->next = nullptr;
    return newNode;
}