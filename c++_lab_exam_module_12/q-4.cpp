#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        int N, count = 0;
        cin>>N;
        
        int arr[N];
        for(int j = 0; j < N; j++){
            cin>>arr[j];
        }
        
        sort(arr,arr+N);
        for(int j = 0; j < N; j++){
            if(arr[0] < arr[j]){
                count++;
            }
        }

        cout<<count<<endl;
    }
    return 0;
}