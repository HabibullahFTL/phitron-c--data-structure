// ============================ [ Practice 15.5 - Question 4 ] ============================
// WAP that will take (n x n) integer inputs into a square matrix of dimension n (where n 
// must be an odd number). Then calculate sum of the integers at first row, last row and 
// two diagonals without overlap. Please see the sample input-output.
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
    int n, sum = 0;
    cin >> n;

    int metrics[n][n];

    // Taking metrics inputs
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> metrics[i][j];
        }
    }

    for (int i = 0, k = 0, l = n - 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == 0 || i == n - 1){
                sum += metrics[i][j];
            }else if(j == k){
                sum += metrics[i][j];
            }else if(j == l){
                sum += metrics[i][j];
            }
        }
        if(i < n/2){
            k++;
            l--;
        }else{
            k--;
            l++;
        }
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
