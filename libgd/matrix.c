#include <stdio.h>
#include <stdlib.h>

// https://github.com/portfoliocourses/c-example-code/blob/main/return_dynamic_2d_array.c

int** create_matrix(int m, int n, int fill_value)
{
    int **matrix = malloc(sizeof(int*) * m);

    for (int i = 0; i < m; i++)
        matrix[i] = malloc(sizeof(int) * n);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = fill_value;

    return matrix;
}

int main()
{
    int W = 6;
    int H = 4;

    int **matrix = create_matrix(H, W, 2);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }

    for (int i = 0; i < H; i++)
        free(matrix[i]);

    free(matrix);

    return 0;
}


