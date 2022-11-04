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

void insertAtHead(Node *&head, int val);
void insertAtTail(Node *&head, int val);
void insertAtSpecificPosition(Node *&head, int position, int val);
void insertAfterSpecificValue(Node *&head, int searchVal, int val);
void insertAfterSpecificValueDuplicateList(Node *&head, int searchVal, int val);
void display(Node *temp);

void printReverseLinkList(Node *head);
int countLinkedList(Node *head);
int searchValuePosition(Node *&head, int n);
void searchByValueDuplicate(Node *&head, int n, int arr[]);
void deleteAtHead(Node *&head);
void deleteAtTail(Node *&head);
void deleteAtSpecificPosition(Node *&head, int pos);
void deleteBySpecificValue(Node *&head, int val);
void deleteBySpecificValueDuplicateList(Node *&head, int val);
Node *reverseNonRecursive(Node *&head);
Node *reverseRecursive(Node *&head);

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

void display2(Node *temp)
{
    if (temp == NULL)
        cout << "There is no value in the linked list" << endl;
    else
    {
        int count = 1;
        cout << "Values are: ";
        while (count != 8)
        {
            cout << temp->value;
            cout << " -> ";
            temp = temp->Next;
            count++;
        }
        cout << endl;
    }
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
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

void printReverseLinkList(Node *head)
{
    if (head == NULL)
        return;

    printReverseLinkList(head->Next);
    cout << head->value << " ";
}

int countLinkedList(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }

    return count;
}

void insertAtSpecificPosition(Node *&head, int position, int val)
{
    if (position == 1)
    {
        insertAtHead(head, val);
    }
    else
    {
        int i = 0;
        Node *temp = head;
        while (i < position - 2)
        {
            temp = temp->Next;
            i++;
        }

        Node *newNode = new Node(val);
        newNode->Next = temp->Next;
        temp->Next = newNode;
    }
};

int searchValuePosition(Node *&head, int n)
{
    if (head == NULL)
        return -1;
    else
    {
        int count = 1, foundAt = -1;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->value == n)
            {
                foundAt = count;
                break;
            };
            temp = temp->Next;
            count++;
        }
        return foundAt;
    }
}

void searchByValueDuplicate(Node *&head, int n, int arr[])
{
    if (head == NULL)
        cout << "Not found your entered value." << endl;
    else
    {
        Node *temp = head;
        int i = 1, count = 0;
        while (temp != NULL)
        {
            if (temp->value == n)
            {
                count++;
                arr[count] = i;
            };
            temp = temp->Next;
            i++;
        }
        arr[0] = count;
    }
}

void insertAfterSpecificValue(Node *&head, int searchVal, int val)
{
    int position = searchValuePosition(head, searchVal);
    if (position == -1)
        cout << "Your entered search input is not found!" << endl;
    else
    {
        insertAtSpecificPosition(head, position + 1, val);
    }
};

void insertAfterSpecificValueDuplicateList(Node *&head, int searchVal, int val)
{
    int size = countLinkedList(head);
    int arr[size + 1];
    arr[0] = size;
    searchByValueDuplicate(head, searchVal, arr);
    if (arr[0] > 0)
    {
        cout << "Your entered value found " << arr[0] << " times." << endl;
        for (int i = 1; i <= arr[0]; i++)
        {
            insertAtSpecificPosition(head, arr[i] + i, val);
        }
    }
    else
    {
        cout << "Your entered value not found.";
    }
};

void deleteAtHead(Node *&head)
{
    if (head == NULL)
        cout << "There is no value in the linked list" << endl;
    else
    {
        Node *temp = head;
        head = temp->Next;
        delete temp;
    }
}

void deleteAtTail(Node *&head)
{
    if (head == NULL)
        cout << "There is no value in the linked list" << endl;
    else if (head->Next == NULL)
    {
        deleteAtHead(head);
    }
    else
    {
        Node *temp = head;
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }

        Node *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
}

void deleteAtSpecificPosition(Node *&head, int pos)
{
    int length = countLinkedList(head);
    if (head == NULL)
    {
        cout << "There is no value in the linked list" << endl;
    }
    else if (pos > length)
    {
        cout << "Invalid position value" << endl;
    }
    else if (pos == 1)
    {
        deleteAtHead(head);
    }
    else if (pos == length)
    {
        deleteAtTail(head);
    }
    else
    {
        int count = 1;
        Node *temp = head;
        while (count < pos - 1)
        {
            temp = temp->Next;
            count++;
        }
        Node *delNode = temp->Next;
        temp->Next = delNode->Next;
        delete delNode;
    }
};

void deleteBySpecificValue(Node *&head, int val)
{
    int position = searchValuePosition(head, val);
    if (position == -1)
        cout << "Your entered search input is not found!" << endl;
    else
    {
        deleteAtSpecificPosition(head, position);
    }
};

void deleteBySpecificValueDuplicateList(Node *&head, int val)
{
    int size = countLinkedList(head);
    int arr[size + 1];
    arr[0] = size;
    searchByValueDuplicate(head, val, arr);
    if (arr[0] > 0)
    {
        cout << "Your entered value found " << arr[0] << " times." << endl;
        for (int i = 1; i <= arr[0]; i++)
        {
            deleteAtSpecificPosition(head, arr[i] - i + 1);
        }
    }
    else
    {
        cout << "Your entered value not found.";
    }
};

Node *reverseNonRecursive(Node *&head)
{
    if (head == NULL)
        return head;
    else
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next = head->Next;

        while (true)
        {
            current->Next = prev;
            prev = current;
            current = next;
            if (current == NULL)
                break;
            next = next->Next;
        }
        return prev;
    }
};

Node *reverseRecursive(Node *&head)
{
    if (head->Next == NULL || head == NULL)
    {
        return head;
    }

    Node *newHead = reverseRecursive(head->Next);
    head->Next->Next = head;
    head->Next = NULL;
    return newHead;
};

int findMid(Node *&head)
{
    if (head == NULL)
        return -1;
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }
    return slow->value;
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
    // if (head == NULL)
    //     return false;
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
        if (slow->Next == fast->Next)
        {
            return true;
        }
    }
    return false;
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
             << "2. Insert at head" << endl
             << "3. Insert at tail" << endl
             << "4. Insert at specific position" << endl
             << "5. Insert after specific value " << endl
             << "6. Insert after specific value in duplicate list" << endl
             << "7. Search a value" << endl
             << "8. Search a value from duplicate listed" << endl
             << "9. Delete at head" << endl
             << "10. Delete at tail" << endl
             << "11. Delete at specific position" << endl
             << "12. Delete by specific value" << endl
             << "13. Delete by specific value from duplicate listed" << endl
             << "14. Reverse linked list (non-recursive)" << endl
             << "15. Reverse linked list (recursive)" << endl
             << "16. Find mid value" << endl
             << "17. Create a cycle at kth postion" << endl
             << "18. Detect cycle" << endl
             << "0. Enter 0 to exit" << endl
             << "Next choice:";
        cin >> choice;

        int size = 1;
        int arr[size + 1];
        arr[0] = size;

        switch (choice)
        {
        case 1:
            display2(head);
            cout << "List size: " << size << endl;
            break;

        case 2:
            cout << "Enter a number: ";
            cin >> val;
            insertAtHead(head, val);
            break;

        case 3:
            cout << "Enter a number: ";
            cin >> val;
            insertAtTail(head, val);
            break;

        case 4:
            cout << "Enter a number: ";
            cin >> val;
            cout << "Enter a position: ";
            cin >> position;
            insertAtSpecificPosition(head, position, val);
            break;

        case 5:
            cout << "Enter a number to search: ";
            cin >> searchVal;
            cout << "Enter a number to insert: ";
            cin >> val;
            insertAfterSpecificValue(head, searchVal, val);
            break;

        case 6:
            cout << "Enter a number to search: ";
            cin >> searchVal;
            cout << "Enter a number to insert: ";
            cin >> val;
            insertAfterSpecificValueDuplicateList(head, searchVal, val);
            break;

        case 7:
            cout << "Enter a number to search: ";
            cin >> val;
            output = searchValuePosition(head, val);
            if (output == -1)
                cout << "Your entered search input is not found!" << endl;
            else
                cout << "Your entered value found in position " << output << endl;
            break;

        case 8:
            cout << "Enter a number to search: ";
            cin >> val;
            searchByValueDuplicate(head, val, arr);
            if (arr[0] > 0)
            {
                cout << "Your entered value found " << arr[0] << " times." << endl
                     << "Found in these positions: ";
                for (int i = 1; i <= arr[0]; i++)
                {
                    cout << arr[i] << " ";
                }
            }
            else
            {
                cout << "Your entered value not found.";
            }
            break;

        case 9:
            deleteAtHead(head);
            break;

        case 10:
            deleteAtTail(head);
            break;

        case 11:
            cout << "Enter the position";
            cin >> position;
            deleteAtSpecificPosition(head, position);
            break;

        case 12:
            cout << "Enter value to delete ";
            cin >> val;
            deleteBySpecificValue(head, val);
            break;

        case 13:
            cout << "Enter value to delete ";
            cin >> val;
            deleteBySpecificValueDuplicateList(head, val);
            break;

        case 14:
            head = reverseNonRecursive(head);
            break;

        case 15:
            head = reverseRecursive(head);
            break;

        case 16:
            output = findMid(head);
            if (output == -1)
                cout << "There is no value in the linked list" << endl;
            else
                cout << "Mid value is " << output << endl;
            break;

        case 17:
            cout << "Enter position to create cycle ";
            cin >> position;
            createCycle(head, position);
            break;

        case 18:
            isTrue = detectCycle(head);
            if (isTrue)
                cout << "Found a cycle" << endl;
            else
                cout << "Found no cycle" << endl;
            break;

        default:
            break;
        }
    }

    cout << "Display list: ";
    display(head);
    cout << "Count list: " << countLinkedList(head);
    cout << endl;
    return 0;
}