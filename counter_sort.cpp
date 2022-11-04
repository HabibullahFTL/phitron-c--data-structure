#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n = 10;
    int arr[10] = {2, 6, 9, 4, 7, 2, 4, 6, 7, 2};
    cout<<"Before soring: ";
    printArray(arr, n);

    // Step 1 : Finding max number from basic arr
    int max_num = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > max_num) max_num = arr[i];
    }
    cout<<"Max : "<<max_num<<endl;

    // Step 2 : Making an array, length of (max + 1) with initializing every element by 0
    int new_arr[max_num + 1];
    for(int i = 0; i <= max_num; i++){
        new_arr[i] = 0;
    }

    // Step 3 : storing frequency of basic array
    for(int i = 0; i <= max_num; i++){
        new_arr[arr[i]]++;
    }
    cout<<"Freq array: ";
    printArray(new_arr, max_num + 1);

    // Step 4 : cumulative sum of frequency array
    for (int i = 1; i <=  max_num; i++)
    {
        new_arr[i] += new_arr[i - 1];
    }
    cout<<"Cumulative sum: ";
    printArray(new_arr, max_num + 1);

    // Setp 5 : Making sorted array
    int final[n];
    for(int i = n - 1; i >= 0; i--){
        new_arr[arr[i]]--;
        int k = new_arr[arr[i]];
        final[k] = arr[i];
    }
    
    cout<<"After sorting: ";
    printArray(final, n);
    return 0;
}