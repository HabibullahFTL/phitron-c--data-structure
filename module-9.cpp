#include <bits/stdc++.h>
using namespace std;

void PrintArray(int arr[], int size)
{
    // Traversing a data structure means: "visiting" or "touching" the elements of the structure, and doing something with the data. (Traversing is also sometimes called iterating over the data structure)

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int array[50];
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    // 1. Traversing
    // cout<<endl<<"Given Array is: ";
    // PrintArray(array,size);

    // 2. Insertion
    int pos, val;
    // cout << "Position of insertion: ";
    cout << "Position of deletion: ";
    cin >> pos;

    if (pos >= 0 && pos < size)
    {
        // cout << "Value of insertion: ";
        // cout << "Value of deletion: ";
        // cin >> val;

        // INSERTION For sorted array
        // for (int i = size - 1; i >= pos; i--)
        // {
        //     array[i + 1] = array[i];
        // }
        // array[pos] = val;

        // INSERTION For non-sorted array
        // array[size] = array[pos];
        // array[pos] = val;

        // DELETION For last item
        if(pos == size - 1) size--;
        else{
            // DELETION for first or middle item
            // 1 2 3 4 5
            // i=> 2
            // 1 2 4 4 5 i => 3
            // 1 2 4 5 

            for(int i = pos; i < size ; i++){
                array[i] = array[i + 1];
            }
            size--;
        }

        // cout << "Array after the insertion: ";
        // PrintArray(array, size + 1);

        cout << "Array after the deletion: ";
        PrintArray(array, size);
    }else{
        cout<<"Position is not valid."<<endl;
    }
    return 0;
}