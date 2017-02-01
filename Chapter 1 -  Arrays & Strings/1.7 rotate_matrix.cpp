#include <iostream>
using namespace std;
void transpose(int **matrix, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (i != j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
}
void reverse(int *row, int n)
{
    for (int i = 0; i < n / 2; ++i)
        swap(row[i], row[n - i - 1]);
}
void rotate(int **matrix, int n)
{
    transpose(matrix, n);
    // reverse each row
    for (int i = 0; i < n; ++i)
        reverse(matrix[i], n);
}
void print_matrix(int **matrix, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
int main()
{
    int n = 3, no = 1, i, j;
    int **matrix = new int *[n];
    for (i = 0; i < n; i++)
        matrix[i] = new int[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            matrix[i][j] = no++;
    }
    cout << "Original Matrix\n";
    print_matrix(matrix, n);
    rotate(matrix, n);
    cout << "\nAfter Rotation\n";
    print_matrix(matrix, n);
    return 0;
}