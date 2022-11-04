#include <bits/stdc++.h>
using namespace std;

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of your array: ";
    cin >> size;

    int arr[size];
    cout << "Enter values of array by space separation: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < size; i++)
    {
        int flag = 0;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
            PrintArray(arr, size);
        }
        if(flag == 0) break;
        cout << endl;
    }

    cout << "Sorted array: ";
    PrintArray(arr, size);
    return 0;
}