#include <bits/stdc++.h>

using namespace std;

template <typename N>
class Node
{
public:
    N value;
    Node *Next;

    Node(N val)
    {
        value = val;
        Next = NULL;
    }
};

template <typename Q>
class Queue
{
    Node<Q> *front;
    Node<Q> *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // enqueue -> Push
    void Push(Q val)
    {
        Node<Q> *newNode = new Node<Q>(val);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->Next = newNode;
        rear = rear->Next;
    }

    // dequeue -> Pop
    Q Pop()
    {
        Q chk;
        if (rear == NULL)
        {
            cout << "Queue under flow. There is no value in the queue!" << endl;
            return chk;
        }

        Node<Q> *delNode = front;
        front = front->Next;
        chk = delNode->value;
        if (front == NULL)
            rear = NULL;
        delete delNode;
        return chk;
    }

    // pick
    Q Front()
    {
        Q chk;
        if (front == NULL)
            return chk;
        chk = front->value;
        return chk;
    }
    Q Back()
    {
        Q chk;
        if (rear == NULL)
            return chk;
        chk = rear->value;
        return chk;
    }
    // empty
    bool empty()
    {
        if (front == NULL && rear == NULL)
            return true;
        else
            return false;
    }
};