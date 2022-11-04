#include <bits/stdc++.h>
using namespace std;

void abc()
{
    static int id = 1;
    cout << id << endl;
    id++;
}

int main()
{
    abc();
    abc();
    abc();
    abc();
    abc();
    abc();
    abc();
    return 0;
}