#include <bits/stdc++.h>
using namespace std;

template<typename N> class Node
{
public:
    N value;
    Node *prev;
    Node *next;
    Node(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template<typename S> class Stack
{

    Node <S> *head;
    Node <S> *top;
    int count;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
        count = 0;
    }

    // PUSH
    void Push( S val)
    {
        Node  <S> *newNode = new Node <S>(val);

        if (head == NULL)
        {
            top = head = newNode;
        }
        else
        {

            top->next = newNode;
            newNode->prev = top;
            top = newNode;
        }
        count++;
    }

    // POP
    S Pop()
    {
        S delValue;
        // If there is no value in the stack
        if (top == NULL)
            return delValue;

        Node <S> *delNode = top;
        delValue = delNode->value;

        // If only 1 value in the stack
        if (top == head)
            top = head = NULL;
        else
        {
            // If there is more than 1 value in the stack
            top = delNode->prev;
            top->next = NULL;
        }
        delete delNode;
        count--;
        return delValue;
    }

    // TOP
    S Top()
    {
        S topValue;
        if (top == NULL)
        {
            cout<<"Stack underflow"<<endl;
            return topValue;
        }
        else
        {
            topValue = top->value;
            return topValue;
        }
    }

    // EMPTY
    bool Empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }

    // SIZE
    int Size()
    {
        return count;
    }
};