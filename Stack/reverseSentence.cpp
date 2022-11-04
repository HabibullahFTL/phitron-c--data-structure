#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;

void reverseSentence(string chk){
    Stack <string> st;
    for(int i= 0; i < chk.length(); i++){
       string word = "";
        while (i < chk.length() && chk[i] != ' ')
        {
            word += chk[i];
            i++;
        }
        st.Push(word);
    }
    while (!st.Empty())
    {
        cout<<st.Pop()<<" ";
    }
    cout<<endl;
    
}

int main(){
    string chk = "I am a programmer";
    reverseSentence(chk);
    return 0;
}