#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;

int globalId = 100;

class Person
{
    int ID;
    string name;
    float salary;

public:
    Person()
    {
        ID = -1;
        this->name = "";
        this->salary  = -1.0;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }
    Person(string name, float salary)
    {
        ID = globalId;
        setName(name);
        setSalary(salary);
        globalId++;
    }
    string getName(){
        return name;
    }
    float getSalary(){
        return salary;
    }
    void print(){
        cout<<ID<<"\t"<<name<<"\t"<<salary<<endl;
    }
};

int main()
{
    // Stack<pair<int, char>> st;
    // st.Push(make_pair(1, 'b'));
    // st.Push(make_pair(3, 'f'));
    // st.Push(make_pair(1, 'c'));

    // while (!st.Empty())
    // {
    //     pair<int, char> chk;
    //     chk = st.Pop();
    //     cout << chk.first << " | " << chk.second << endl;
    // }
    Stack <Person> st;
    Person a ("Habibullah", 1025.6);
    Person b ("Bahar", 2025.6);
    Person c ("Piash", 3025.6);

    st.Push(a);
    st.Push(b);
    st.Push(c);
    
    // while (!st.Empty())
    // {
    //     Person printObj;
    //     printObj = st.Pop();
    //     printObj.print();
    // }
            Person printObj;
        printObj = st.Top();
        printObj.print();
    
    return 0;
}