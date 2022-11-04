#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void replaceEvenNums(Node *&head)
{
    if (head != NULL)
    {
        Node *temp;
        temp = head;
        while (temp != NULL)
        {
            if (temp->value % 2 == 0)
                temp->value = -1;
            temp = temp->next;
        }
        cout << endl;
    }
}

void displayList(Node *&head)
{
    if (head != NULL)
    {
        Node *temp;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->value;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    int N, val;
    cin >> N;
    Node *head = NULL;
    for (int i = 0; i < N; i++)
    {
        cin >> val;
        insertAtTail(head, val);
    }
    replaceEvenNums(head);
    displayList(head);
    return 0;
}