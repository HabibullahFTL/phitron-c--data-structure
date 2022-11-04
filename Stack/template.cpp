#include <bits/stdc++.h>
using namespace std;

template<typename T> T myMax(T a, T b){
    return a > b ? a : b;
}

int main(){
    cout<<myMax<int>(9, 7)<<endl;
    cout<<myMax<float>(9.4, 7.6)<<endl;
    cout<<myMax<char>('a', 'b')<<endl;
    return 0;
}