// ============================ [ Practice 15.5 - Question 5 ] ============================
// WAP that will take (n x n) integer inputs into a square matrix of 
// dimension n (where n must be an odd number). Then calculate the sum of 
// the integers based on the following position pattern (consider only the 
// boxed position during the sum). Please see the input-output.
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 2 == 1)
            {
                sum += metrics[i][j];
            }
            else
            {
                if (j % 2 == 1)
                {
                    sum += metrics[i][j];
                }
            }
        }
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
