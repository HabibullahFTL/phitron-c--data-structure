#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Taking inputs
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // Sorting the array
    for (int i = 1; i < N; i++)
    {
        int flag = 0;
        for (int j = 0; j < N - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }

    // Printing output of the frequency
    int i = 0;
    while (i < N)
    {
        int count = 0;
        int lastDigit = arr[i];
        while (lastDigit == arr[i] && i <= N)
        {
            i++;
            count++;
        }
        // print
        cout<<lastDigit<<" => "<<count<<endl;
    }
    return 0;
}