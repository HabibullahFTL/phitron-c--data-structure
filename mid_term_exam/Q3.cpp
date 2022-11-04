#include <bits/stdc++.h>
using namespace std;

int main(){
    // Taking test Case input
    int T;
    cin>>T;
    for (int i = 0; i < T; i++)
    {
        // Taking days input
        int D;
        cin>>D;
        int earningArr[D], spendsArr[D], balanceArr[D];
        // Taking earnings array inputs
        for (int i = 0; i < D; i++)
        {
            cin>>earningArr[i];
        }
        // Taking spends array inputs
        for (int i = 0; i < D; i++)
        {
            cin>>spendsArr[i];
            // Storing balance
            if(i == 0) balanceArr[i] = earningArr[i] - spendsArr[i];
            else balanceArr[i] = balanceArr[i - 1] + earningArr[i] - spendsArr[i];
        }

        // Taking query count;
        int Q;
        cin>>Q;
        // Taking queries inputs
        int queries[Q];
        for (int i = 0; i < Q; i++)
        {
            cin>>queries[i];
        }
        // Showing outputs
        for (int i = 0; i < Q; i++)
        {
            if(balanceArr[queries[i]] >= 0) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}