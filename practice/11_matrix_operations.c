#include <stdio.h>

void displayMatrix(int matrix[10][10], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            printf("%d\t", matrix[i][j]);

        printf("\n");
    }
}

int main()
{
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("===== MATRIX OPERATIONS =====\n");

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    if(r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0 ||
       r1 > 10 || c1 > 10 || r2 > 10 || c2 > 10)
    {
        printf("Invalid matrix size.\n");
        return 0;
    }

    printf("\nEnter elements of Matrix A:\n");

    for(i = 0; i < r1; i++)
        for(j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter elements of Matrix B:\n");

    for(i = 0; i < r2; i++)
        for(j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    printf("\n===== MATRIX A =====\n");
    displayMatrix(A, r1, c1);

    printf("\n===== MATRIX B =====\n");
    displayMatrix(B, r2, c2);

    if(r1 == r2 && c1 == c2)
    {
        printf("\n===== ADDITION =====\n");

        for(i = 0; i < r1; i++)
        {
            for(j = 0; j < c1; j++)
                C[i][j] = A[i][j] + B[i][j];
        }

        displayMatrix(C, r1, c1);
    }
    else
    {
        printf("\nMatrix addition not possible.\n");
    }

    if(c1 == r2)
    {
        printf("\n===== MULTIPLICATION =====\n");

        for(i = 0; i < r1; i++)
        {
            for(j = 0; j < c2; j++)
            {
                C[i][j] = 0;

                for(k = 0; k < c1; k++)
                    C[i][j] += A[i][k] * B[k][j];
            }
        }

        displayMatrix(C, r1, c2);
    }
    else
    {
        printf("\nMatrix multiplication not possible.\n");
    }

    return 0;
}
