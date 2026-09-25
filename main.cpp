#include "assignment1.h"
#include <iostream>

using namespace std;


//Jana Marie Reyes
//September 2026
//200548478


int main() {
    Matrix matrixList;
    int choice = 0;

    do {
        cout << "\nEnter the corresponding number for your desired operation:" << endl;
        cout << "1 - insert a new matrix;" << endl;
        cout << "2 - add two matrices and insert the resultant matrix;" << endl;
        cout << "3 - subtract a matrix from another and insert the resultant matrix;" << endl;
        cout << "4 - multiply two matrices and insert the resultant matrix;" << endl;
        cout << "5 - print all matrices;" << endl;
        cout << "6 - end the program" << endl;

        cin >> choice;

        if (choice == 1) {
            matrixList.Insert();
        } 
        else if (choice == 2 || choice == 3 || choice == 4) {
            // Check if there are enough matrices
            if (matrixList.GetLength() < 2) {
                cout << "Error: At least two matrices are required for this operation." << endl;
                continue;
            }

            int idx1, idx2;
            
            // Match the exact prompts from the screenshots
            if (choice == 2) {
                cout << "\nThere are total " << matrixList.GetLength() << " matrices in the list. Enter which matrices you want to add:" << endl;
            } else if (choice == 3) {
                cout << "\nThere are total " << matrixList.GetLength() << " matrices in the list. Enter minuend matrix first and then subtrahend matrix:" << endl;
            } else if (choice == 4) {
                cout << "\nThere are total " << matrixList.GetLength() << " matrices in the list. Enter which matrices you want to multiply:" << endl;
            }

            cin >> idx1;
            cin >> idx2;

            MatrixNode *node1 = matrixList.FindNode(idx1);
            MatrixNode *node2 = matrixList.FindNode(idx2);

            if (node1 == nullptr || node2 == nullptr) {
                cout << "Error: Invalid matrix index." << endl;
                continue;
            }

            if (choice == 2) { // Addition
                if (AddSubCompatible(node1, node2)) {
                    MatrixType res = Add(node1->matrix, node2->matrix);
                    MatrixNode *newNode = new MatrixNode{res, matrixList.head};
                    matrixList.head = newNode;
                    cout << "Addition successful. Result inserted at the beginning." << endl;
                } else {
                    cout << "The operation is not compatible." << endl;
                }
            } 
            else if (choice == 3) { // Subtraction
                if (AddSubCompatible(node1, node2)) {
                    MatrixType res = Sub(node1->matrix, node2->matrix);
                    MatrixNode *newNode = new MatrixNode{res, matrixList.head};
                    matrixList.head = newNode;
                    cout << "Subtraction successful. Result inserted at the beginning." << endl;
                } else {
                    cout << "The operation is not compatible." << endl;
                }
            } 
            else if (choice == 4) { // Multiplication
                if (MultiCompatible(node1, node2)) {
                    MatrixType res = Multi(node1->matrix, node2->matrix);
                    MatrixNode *newNode = new MatrixNode{res, matrixList.head};
                    matrixList.head = newNode;
                    cout << "Multiplication successful. Result inserted at the beginning." << endl;
                } else {
                    cout << "The operation is not compatible." << endl;
                }
            }
        } 
        else if (choice == 5) {
            matrixList.Print();
        } 
        else if (choice != 6) {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}