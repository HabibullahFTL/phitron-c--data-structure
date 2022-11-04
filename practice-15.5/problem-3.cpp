// ============================ [ Practice 15.5 - Question 3 ] ============================
// WAP that will take inputs of m x n sized matrix into a 2D array and 
// find the maximum element with index location from that matrix.
// ====================================== [ Question ] ====================================

#include <bits/stdc++.h>
using namespace std;

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
    int row, col;
    cin >> row >> col;

    int metrics[row][col];
    int max_num = INT_MIN, max_row, max_col;

    // Taking metrics inputs
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> metrics[i][j];
            if (metrics[i][j] > max_num)
            {
                max_num = metrics[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    cout << "Max: " << max_num << endl<<"Locatin: ["<<max_row<<"]["<<max_col<<"]"<<endl;
    return 0;
}
