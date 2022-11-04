#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;

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

string infixToPostfix(string chk)
{
    Stack<char> st;
    string result;

    // Step-1: Iterating characters
    for (int i = 0; i < chk.length(); i++)
    {
        if (chk[i] >= '0' && chk[i] <= '9')
        { // Step-1.1: If the character is between 0-9 then add it to result
            result += chk[i];
        }
        else if (chk[i] == '(')
        { // Step-1.2: If the character is "(" then push it to stack
            st.Push(chk[i]);
        }
        else if (chk[i] == ')')
        { // Step-1.3: If the character is ")" then pop from the stack until get "(" and add to result
            // After that pop again
            while (!st.Empty() && st.Top() != '(')
            {
                result += st.Pop();
            }
            if (!st.Empty())
                st.Pop();
        }
        else
        {
            // Step-1.4: Check the precision of character. If precision of the top element of the stack is equal or greater than precision of character then pop from the stack and add it to result. It will repeat until the condition gets false.
            while (!st.Empty() && precisionCalc(st.Top()) >= precisionCalc(chk[i]))
            {
                result += st.Pop();
            }
            // Step-1.5: Push character to stack
            st.Push(chk[i]);
        }
    }

    // Step-2: Pop from the stack until the stack is not empty and add to result
    while (!st.Empty())
    {
        result += st.Pop();
    }

    return result;
}

int postfixEvaluation(string chk)
{
    Stack<int> st;
    int a, b;
    // Start iterating from left to right
    for (int i = 0; i < chk.length(); i++)
    {
        if (chk[i] >= '0' && chk[i] <= '9')
        { // If found operand 0 - 9, push it to stack
            st.Push(chk[i] - '0');
        }
        else
        { // Otherwise, calculate and push to stack
            b = st.Pop();
            a = st.Pop();

            switch (chk[i])
            {
            case '+':
                st.Push(a + b);
                break;

            case '-':
                st.Push(a - b);
                break;

            case '/':
                st.Push(a / b);
                break;

            case '*':
                st.Push(a * b);
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

int main()
{
    string postfix = infixToPostfix("(4*(3+5))-(2+0)");
    cout << "Postfix: " << postfix << endl
         << "Postfix evaluation: " << postfixEvaluation(postfix) << endl;
    return 0;
}