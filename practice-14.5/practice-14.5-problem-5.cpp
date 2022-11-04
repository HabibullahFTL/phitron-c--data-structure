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

    int max_num = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > max_num)
                max_num = arr[i][j];
        }
    }

    int freq[max_num + 1];
    for (int i = 0; i <= max_num; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            freq[arr[i][j]]++;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (freq[arr[i][j]] != -1 && freq[arr[i][j]] > 0)
            {
                freq[arr[i][j]]--;
                if (freq[arr[i][j]] > 0)
                    freq[arr[i][j]] = -1;
            }else if(freq[arr[i][j]] == -1){
                arr[i][j] = -1;
            }
        }
    }

    cout << "After:" << endl;
    print2DArray(*arr, row, col);
    return 0;
}