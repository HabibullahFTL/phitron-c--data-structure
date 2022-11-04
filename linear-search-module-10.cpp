#include <bits/stdc++.h>
using namespace std;

int main(){
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

    int flag = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == searchItem) {
            cout<<"Found in index "<<i<<" and position is "<<i + 1<<endl;
            flag++;
        }
    }
    if(flag == 0) cout<<"Not found your item"<<endl;
    return 0;
}