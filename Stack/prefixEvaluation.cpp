#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;

int prefixEvaluation(string chk)
{
    Stack<int> st;
    for (int i = chk.length(); i >= 0; i--)
    {
        if (chk[i] >= '0' && chk[i] <= '9')
        {
            st.Push(chk[i] - '0');
        }
        else
        {
            int a = st.Pop();
            int b = st.Pop();

            switch (chk[i])
            {
            case '+':
                st.Push(a + b);
                break;
            case '-':
                st.Push(a - b);
                break;
            case '*':
                st.Push(a * b);
                break;
            case '/':
                st.Push(a / b);
                break;
            case '^':
                st.Push(pow(a, b));
                break;

            default:
                break;
            }
        }
    }
    return st.Top();
}

int precisionCalc(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '/' || ch == '*')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPrefix(string chk)
{
    // Step-1: Reverse the string
    reverse(chk.begin(), chk.end());

    Stack<char> st;
    string result;
    // Step-2: Check the character
    for (int i = 0; i < chk.length(); i++)
    {
        if (chk[i] >= '0' && chk[i] <= '9')
        { // Step-2.1: If the character is between 0-9 then add it to result
            result += chk[i];
        }
        else if (chk[i] == ')')
        { // Step-2.2: If the character is ")" then push it to stack
            st.Push(chk[i]);
        }
        else if (chk[i] == '(')
        { // Step-2.3: If the character is "(" then pop from the stack until get ")" and add to result
            // After that pop again
            while (!st.Empty() && st.Top() != ')')
            {
                result += st.Pop();
            }
            if (!st.Empty())
                st.Pop();
        }
        else
        { // Step-2.4: Check the precision of character. If precision of the top element of the stack is equal or greater than precision of character then pop from the stack and add it to result. It will repeat until the condition gets false.
            while (!st.Empty() && precisionCalc(st.Top()) >= precisionCalc(chk[i]))
            {
                result += st.Pop();
            }
            // Step-2.5: Push character to stack
            st.Push(chk[i]);
        }
    }

    // Step-3: Pop from the stack until the stack is not empty and add to result
    while (!st.Empty())
    {
        result += st.Pop();
    }
    // Step-4: Reverse the string and return it
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    // (7+(4*5))-(2+0)
    //
    string prefix = infixToPrefix("2+4/5*(5-3)^5^4");
    cout << "Prefix value: " << prefix << endl
         << "Prefix evaluation: " << prefixEvaluation(prefix) << endl;
    return 0;
}