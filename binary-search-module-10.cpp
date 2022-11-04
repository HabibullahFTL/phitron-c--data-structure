#include <bits/stdc++.h>
using namespace std;

int binarySearch (int array[], int x, int lb, int ub)
{
    if(lb <= ub){
        int mid = (lb + ub) / 2;
        
        if(array[mid] == x) return mid;
        else if(x > array[mid])return binarySearch(array, x, mid + 1, ub);
        else return binarySearch(array, x, lb, mid - 1);
    }
    else return -1;
}

int main()
{
    int n;
    cout<<"Enter the array size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter items values of the array separating each with space: "<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int searchItem;
    cout<<endl<<endl<<"Enter which number you want to search: ";
    cin>>searchItem;

    int itemIndex = binarySearch(arr, searchItem, 0, n - 1);

    if(itemIndex != -1){
        cout<<"Your item found in "<<itemIndex<<endl;
    }else cout<<"Not found"<<endl;
    return 0; 
}