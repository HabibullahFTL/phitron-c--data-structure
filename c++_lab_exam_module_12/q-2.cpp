#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    getchar();
    getchar();

    for(int i = 0; i < t; i++){
        cout<<"Case "<<i+1<<":"<<endl;
        int n, q;
        cin>>n>>q;

        int marks[n];
        for(int j = 0; j < n; j++){
            cin>>marks[j];
        }

        for(int j = 0; j < q; j++){
            int startPoint, endPoint;
            cin>>startPoint>>endPoint;
            int min = marks[startPoint - 1];
            if(startPoint == endPoint){
                min = marks[startPoint - 1];
            }else {
                
            int *min = min_element(marks + startPoint - 1, marks + endPoint -  1);
            }
            cout<<min<<endl;
        }
    }
}