#include <bits/stdc++.h>
#include "MYQUEUE.h"

using namespace std;

typedef pair<int, int> mytype;

int main()
{
    Queue<mytype> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        q.Push(make_pair(c1, c2));
    }

    if (!q.empty())
    {
        mytype chk;
        chk = q.Front();
        cout << "Front: " << chk.first << " " << chk.second << endl;
    }
    if (!q.empty())
    {
        mytype chk;
        chk = q.Back();
        cout << "Back: " << chk.first << " " << chk.second << endl;
    }

    return 0;
}