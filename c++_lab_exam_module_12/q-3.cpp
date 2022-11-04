#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        int arr[n];
        for(int j = 0; j < n; j++){
            cin>>arr[j];
        }
        int count = 0;
        // for(int j = 0; j < n - 1; j++){
        //     if(arr[j] < min) min = arr[j];
        // }
        sort(arr,arr+n);
        for(int j = 0; j < n; j++){
            if(arr[j] > arr[0]) count++;
        }
        cout<<count<<endl;
    }
    return 0;
}