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
    // Taking input row and col number
    int rows, cols;
    cin >> rows >> cols;
    int arr[rows][cols];

    int maxValue = INT_MIN;

    // Taking inputs for 2D array values and finding max value
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
            if (maxValue < arr[i][j])
                maxValue = arr[i][j];
        }
    }
    
    // Creating a maxValue + 1 size array and assigning 0 to all elements
    int freqArr[maxValue + 1];
    for (int i = 0; i < maxValue + 1; i++)
    {
        freqArr[i] = 0;
    }
    // Updating frequency array with frequency
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (freqArr[arr[i][j]] > 0)
                arr[i][j] = -1;
            freqArr[arr[i][j]]++;
        }
    }
    // Showing the final array
    Print2DArray(*arr, rows, cols);
    return 0;
}