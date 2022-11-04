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
    int mid = (0 + sqv) / 2;
    int first = 0, last = sqv - 1;

    int arr[sqv][sqv];
    for (int i = 0; i < sqv; i++)
    {
        for (int j = 0; j < sqv; j++)
        {
            cin >> arr[i][j];
        }
    }

    int majorDiagonal[sqv];
    for (int i = 0; i < sqv; i++)
    {
        for (int j = 0; j < sqv; j++)
        {
            if (i == j)
                majorDiagonal[i] = arr[i][j];
        }
    }
    cout<<"Major diagonal: ";
    printArray(majorDiagonal, sqv);

    int minorDiagonal[sqv];
    for (int i = 0; i < sqv; i++)
    {
        for (int j = sqv - 1; j >= 0; j--)
        {
            if ((sqv - 1 - i) == j)
                minorDiagonal[i] = arr[i][j];
        }
    }
    cout<<"MinorMinor diagonal: ";
    printArray(minorDiagonal, sqv);
    return 0;
}