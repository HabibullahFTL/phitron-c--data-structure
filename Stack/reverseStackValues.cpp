#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

void printStack(Stack<int> &st)
{
    while (!st.Empty())
    {
        cout << st.Pop() << endl;
    }
}

void insertAtBottom(Stack <int> &st, int checkElement){
    if(st.Empty()){
        st.Push(checkElement);
        return;
    }

    int newTopElem = st.Top();
    st.Pop();
    insertAtBottom(st, checkElement);
    st.Push(newTopElem);

};

void recursiveStack(Stack <int> &st){
    if(st.Empty()) return;

    int topElem = st.Top();
    st.Pop();
    recursiveStack(st);
    insertAtBottom(st, topElem);
};

int main()
{
    Stack<int> st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(5);
    
    cout<<"Before: "<<endl;
    // printStack(st);

    recursiveStack(st);

    cout<<"After:"<<endl;
    printStack(st);
    return 0;
}