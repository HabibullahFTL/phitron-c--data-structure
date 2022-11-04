#include <bits/stdc++.h>
using namespace std;

void Print2DArray(int *arr, int row, int col)
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
    // Taking Inputs
    int size;
    cin >> size;
    int arr[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Calculating output
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 && (j <= size / 2 || j == size - 1))
            {
                sum += arr[i][j];
            }
            else if (i == size - 1 && (j == 0 || j >= size / 2))
            {
                sum += arr[i][j];
            }
            else if (i == size / 2)
                sum += arr[i][j];
            else
            {
                if ((j == size / 2) || (i < size / 2 && j == size - 1) || (i > size / 2 && j == 0))
                    sum += arr[i][j];
            }
        }
    }

    // Showing output
    cout<<sum<<endl;
    return 0;
}