#include <bits/stdc++.h>
using namespace std;
void nullify_row(int **matrix, int n, int row)
{
    for (int j = 0; j < n; j++)
        matrix[row][j] = 0;
}
void nullify_col(int **matrix, int m, int col)
{
    for (int i = 0; i < m; i++)
        matrix[i][col] = 0;
}
void nullify_matrix(int **matrix, int m, int n)
{
    bool first_row = false, first_col = false;
    //first row
    for (int i = 0; i < n; i++)
    {
        if (matrix[0][i] == 0)
        {
            first_row = true;
            break;
        }
    }
    //first col
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            first_col = true;
            break;
        }
    }
    //rest of the matrix
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    //rows first
    for (int i = 1; i < m; i++)
    {
        if (matrix[i][0] == 0)
            nullify_row(matrix, n, i);
    }
    //cols now
    for (int j = 1; j < n; j++)
    {
        if (matrix[0][j] == 0)
            nullify_col(matrix, m, j);
    }
    //first row
    if (first_row)
        nullify_row(matrix, n, 0);
    //first col
    if (first_col)
        nullify_col(matrix, m, 0);
}
void print_matrix(int **matrix, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
int main()
{
    int m = 2, n = 4, i, j;
    int **matrix = new int *[m];
    for (i = 0; i < m; ++i)
        matrix[i] = new int[n];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            matrix[i][j] = rand() % 4;
    }
    cout << "Original Matrix\n";
    print_matrix(matrix, m, n);
    nullify_matrix(matrix, m, n);
    cout << "\nNullified Matrix\n";
    print_matrix(matrix, m, n);
    return 0;
}