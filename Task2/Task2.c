#include <stdio.h>

#define MAX 10

// Function prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    // Matrix A Setup
    printf("--- Matrix A Setup ---\n");
    printf("Enter rows and columns for Matrix A (max %d): ", MAX);
    scanf("%d %d", &r1, &c1);
    if (r1 > MAX || c1 > MAX) {
        printf("Error: Matrix size exceeds maximum limit of %d.\n", MAX);
        return 1;
    }
    inputMatrix(A, r1, c1);

    // Matrix B Setup
    printf("\n--- Matrix B Setup ---\n");
    printf("Enter rows and columns for Matrix B (max %d): ", MAX);
    scanf("%d %d", &r2, &c2);
    if (r2 > MAX || c2 > MAX) {
        printf("Error: Matrix size exceeds maximum limit of %d.\n", MAX);
        return 1;
    }
    inputMatrix(B, r2, c2);

    // Displaying initial matrices
    printf("\n--- Initial Matrices ---\n");
    printf("Matrix A:\n");
    displayMatrix(A, r1, c1);
    printf("\nMatrix B:\n");
    displayMatrix(B, r2, c2);

    // 1. Matrix Addition
    printf("\n=========================================\n");
    printf("1. Matrix Addition (A + B):\n");
    if (r1 == r2 && c1 == c2) {
        addMatrices(A, B, result, r1, c1);
        displayMatrix(result, r1, c1);
    } else {
        printf("Error: Addition impossible! Dimensions must be identical.\n");
    }

    // 2. Matrix Multiplication
    printf("\n=========================================\n");
    printf("2. Matrix Multiplication (A * B):\n");
    if (c1 == r2) {
        multiplyMatrices(A, B, result, r1, c1, c2);
        displayMatrix(result, r1, c2);
    } else {
        printf("Error: Multiplication impossible! Columns of A must equal Rows of B.\n");
    }

    // 3. Transpose
    printf("\n=========================================\n");
    printf("3. Transpose of Matrix A:\n");
    transposeMatrix(A, result, r1, c1);
    displayMatrix(result, c1, r1); // Dimensions swap for transpose

    return 0;
}

// Function to take matrix input from user
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter elements row-wise:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix cleanly
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%6d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0; // Initialize the cell
            for (int k = 0; k < c1; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to find transpose of a matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j]; // Swapping rows and columns
        }
    }
}