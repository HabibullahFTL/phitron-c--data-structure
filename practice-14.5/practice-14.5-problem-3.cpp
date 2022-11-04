#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DArray(int *arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << *((arr + i * col) + j) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int sqv;
    cin >> sqv;

    int majorDiagonal[sqv][sqv];
    for (int i = 0; i < sqv; i++)
    {
        for (int j = 0; j < sqv; j++)
        {
            if (i == j)
                majorDiagonal[i][j] = 1;
            else
                majorDiagonal[i][j] = 0;
        }
    }
    print2DArray(*majorDiagonal, sqv, sqv);
    return 0;
}