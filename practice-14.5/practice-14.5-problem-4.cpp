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

    int arr[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0, k = col-1; j < col; j++, k--)
        {
            if (k > j){
                int temp = arr[i][j];
                arr[i][j] = arr[i][k];
                arr[i][k] = temp;
            }
        }
    }
    cout<<"After reverse:"<<endl;
    print2DArray(*arr,row, col);
    return 0;
}