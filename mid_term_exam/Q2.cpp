#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Taking inputs of array A
    int N;
    cin >> N;
    int arrA[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arrA[i];
    }

    // Taking inputs of array B
    int M;
    cin >> M;
    int arrB[M];
    for (int i = 0; i < M; i++)
    {
        cin >> arrB[i];
    }

    // Printing differences of A - B
    for (int i = 0; i < N; i++)
    {
        int count = 0;
        for (int j = 0; j < M; j++)
        {
            if (arrA[i] == arrB[j])
                count++;
        }
        if (count == 0)
            cout << arrA[i] << " ";
    }
    cout << endl;
    return 0;
}