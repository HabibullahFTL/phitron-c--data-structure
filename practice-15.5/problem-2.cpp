// ============================ [ Practice 15.5 - Question 2 ] ============================
// WAP that will take inputs of two 3 x 3 sized matrix into two 2D array, 
// suppose A and B. Now do C = A * B (multiplication). Finally display 
// all the elements from matrix / 2D array C.
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
    int row = 3, col = 3;
    int first[row][col], second[row][col], result[row][col];

    // Taking first metrics inputs
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> first[i][j];
        }
    }

    // Taking second metrics inputs
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> second[i][j];
        }
    }

    // Multiplying first metrics and second metrics
    // 7 8 9         1 1 1 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            int sum = 0;
            for(int k = 0; k < col; k++){
                sum += first[i][k] * second[k][j];
            }
            result[i][j] = sum;
        }
    } 
    cout<<endl<<endl<<"First metrics"<<endl;
    print2DArray(*first, 3, 3);

    cout<<endl<<endl<<"Second metrics"<<endl;
    print2DArray(*second, 3, 3);

    cout<<endl<<endl<<"Multiplied metrics"<<endl;
    print2DArray(*result, 3, 3);
    return 0;
}