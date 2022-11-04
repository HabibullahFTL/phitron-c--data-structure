// ============================ [ Practice 15.5 - Question 1 ] ============================
// WAP that will take n integers into a sqrt(n) by sqrt(n) array (2D) and 
// show them as traditional matrix view.
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

int main(){
    int n;
    cin>>n;
    int tempArr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>tempArr[i];
    }
    
    int count = 0;
    int sqrt_of_n = sqrt(n);
    int arr[sqrt_of_n][sqrt_of_n];

    for(int i = 0; i < sqrt_of_n; i++){
        for(int j = 0; j < sqrt_of_n; j++){
            arr[i][j] = tempArr[count];
            count++;
        }
    }

    print2DArray(*arr, sqrt_of_n,sqrt_of_n);
    return 0;
}