#include <stdio.h>
#include <stdlib.h>

#define MAX 8 


void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}


void subtract(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}


void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
    int P[MAX][MAX], Q[MAX][MAX], R[MAX][MAX], S[MAX][MAX], T[MAX][MAX], U[MAX][MAX], V[MAX][MAX];
    int temp1[MAX][MAX], temp2[MAX][MAX];

   
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // P = (A11 + A22) * (B11 + B22)
    add(A11, A22, temp1, newSize);
    add(B11, B22, temp2, newSize);
    strassen(temp1, temp2, P, newSize);

    // Q = B11*(A21 + A22)  
    add(A21, A22, temp1, newSize);
    strassen(temp1, B11, Q, newSize);

    // R = A11 * (B12 - B22)
    subtract(B12, B22, temp1, newSize);
    strassen(A11, temp1, R, newSize);

    // S = A22 * (B21 - B11)
    subtract(B21, B11, temp1, newSize);
    strassen(A22, temp1, S, newSize);

    // T = (A11 + A12) * B22
    add(A11, A12, temp1, newSize);
    strassen(temp1, B22, T, newSize);

    // U = (A21 - A11) * (B11 + B12)
    subtract(A21, A11, temp1, newSize);
    add(B11, B12, temp2, newSize);
    strassen(temp1, temp2, U, newSize);

    // V = (A12 - A22) * (B22 + B21)
    subtract(A12, A22, temp1, newSize);
    add(B21, B22, temp2, newSize);
    strassen(temp1, temp2, V, newSize);

    // C11 = P+S-T+V
    add(P, S, temp1, newSize);
    subtract(temp1, T, temp2, newSize);
    add(temp2, V, C11, newSize);

    // C12 = R+T
    add(R, T, C12, newSize);

    // C21 = Q + S
    add(Q, S, C21, newSize);

    // C22  = P+R-Q+U
    add(P, R, temp1, newSize);
    subtract(temp1, Q, temp2, newSize);
    
    add(temp2, U, C22, newSize);

  
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}


void printMatrix(int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], n;

    printf("Enter size of matrix: ", MAX);
    scanf("%d", &n);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, n);

    printf("Resultant matrix C = A * B:\n");
    printMatrix(C, n);

    return 0;
}