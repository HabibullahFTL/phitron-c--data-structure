#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

void display(Node *temp)
{
    if (temp == NULL)
        cout << "There is no value in the linked list" << endl;
    else
    {
        cout << "Values are: ";
        while (temp != NULL)
        {
            cout << temp->value;
            if (temp->Next != NULL)
                cout << " -> ";
            temp = temp->Next;
        }
        cout << endl;
    }
}

void createCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *newNode;
    int count = 1;

    while (temp->Next != NULL)
    {
        if (count == pos)
        {
            newNode = temp;
        }
        temp = temp->Next;
        count++;
    }
    temp->Next = newNode;
}

bool detectCycle(Node *&head)
{
    if (head == NULL)
        return false;
    Node *fast = head;
    Node *slow = head;
    cout << "Entered" << endl;

    while (fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        if (fast->Next->Next == NULL)
            return false;
        fast = fast->Next->Next;
        if (slow->Next == fast->Next)
        {
            return true;
        }
    }
    return false;
}
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }

    temp->Next = newNode;
}
void removeCycle(Node *&head)
{
    bool isFound = detectCycle(head);
    if (isFound)
    {
        Node *fast = head;
        Node *slow = head;

        do
        {
            slow = slow->Next;
            fast = fast->Next->Next;
        } while (slow != fast);

        fast = head;

        while (slow->Next != fast->Next)
        {
            slow = slow->Next;
            fast = fast->Next;
        }
        slow->Next = NULL;
    };
}
int main()
{
    Node *head = NULL;

    int choice = 1, output, searchVal, val, position = 0;
    bool isTrue = false;
    while (choice != 0)
    {
        cout << endl
             << endl
             << "1. Display list" << endl
             << "2. Insert at tail" << endl
             << "3. Create cycle" << endl
             << "4. Detect cycle" << endl
             << "5. Remove cycle" << endl
             << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            display(head);
            break;

        case 2:
            cout << "Enter a number: ";
            cin >> val;
            insertAtTail(head, val);
            break;

        case 3:
            cout << "Enter position to create cycle ";
            cin >> position;
            createCycle(head, position);
            break;

        case 4:
            isTrue = detectCycle(head);
            if (isTrue)
                cout << "Found a cycle" << endl;
            else
                cout << "Found no cycle" << endl;
            break;

        case 5:
            removeCycle(head);
            break;

        default:
            break;
        }
    }

    cout << "Display list: ";
    display(head);
    cout << endl;
    return 0;
}