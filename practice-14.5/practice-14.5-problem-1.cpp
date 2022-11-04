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

    cout << "Given array:" << endl;
    print2DArray(*arr, sqv, sqv);

    int sum = 0;
    for (int i = 0; i < sqv; i++)
    {
        for (int j = 0; j < sqv; j++)
        {
            // For first row
            if ((i == first && j <= mid) || (i == first && j == last))
                sum += arr[i][j];
            // For middle row
            else if (i == mid)
                sum += arr[i][j];
            // For last row
            else if ((i == last && j == first) || (i == last && j >= mid))
                sum += arr[i][j];
            // For others
            else if (
                (i != first || i != last) &&
                (j == mid || (i < mid && j == last) ||
                 (i > mid && j == first)))
                sum += arr[i][j];
        }
    }
    cout << "Sum: " << sum << endl;
    return 0;
}