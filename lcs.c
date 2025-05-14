#include <stdio.h>
#include <string.h>

void print_lcs(char X[], int b[21][21], int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 0) {
        print_lcs(X, b, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (b[i][j] == 1)
        print_lcs(X, b, i - 1, j);
    else
        print_lcs(X, b, i, j - 1);
}

void lcs(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int c[21][21];
    int b[21][21];
    
    for (int i = 0; i <= m; i++)
        c[i][0] = 0;
    for (int j = 0; j <= n; j++)
        c[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1;
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 2;
            }
        }
    }

    printf("Longest Common Subsequence: ");
    print_lcs(X, b, m, n);
    printf("\nLength of LCS: %d\n", c[m][n]);
}

int main() {
    char X[21], Y[21];
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);
    lcs(X, Y);
    return 0;
}
