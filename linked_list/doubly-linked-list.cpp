#include <bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode *prev;
    doublyNode *next;

    doublyNode(int val)
    {
        value = val;
        prev = NULL;
        next = NULL;
    }
};

int countLinkedList(doublyNode *head);
void display(doublyNode *temp);
void insertAtHead(doublyNode *&head, int val);
void insertAtTail(doublyNode *&head, int val);

void display(doublyNode *temp)
{
    if (temp == NULL)
        cout << "There is no value in the linked list" << endl;
    else
    {
        cout << "Values are: ";
        while (temp != NULL)
        {
            cout << temp->value;
            if (temp->next != NULL)
                cout << " --> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int countLinkedList(doublyNode *head)
{
    int count = 0;
    doublyNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void insertAtHead(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    if (head == NULL)
        head = newNode;
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void viewReverseList(doublyNode *&head)
{
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->prev != NULL)
            cout << " --> ";
        temp = temp->prev;
    }
};

void insertAtSpecificPosition(doublyNode *&head, int position, int val)
{
    if (position == 1)
    {
        insertAtHead(head, val);
    }
    else
    {
        int i = 0;
        doublyNode *temp = head;
        while (i < position - 2)
        {
            temp = temp->next;
            i++;
        }

        doublyNode *newNode = new doublyNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
};

int searchValuePosition(doublyNode *&head, int n)
{
    if (head == NULL)
        return -1;
    else
    {
        int count = 1, foundAt = -1;
        doublyNode *temp = head;
        while (temp != NULL)
        {
            if (temp->value == n)
            {
                foundAt = count;
                break;
            };
            temp = temp->next;
            count++;
        }
        return foundAt;
    }
}

void searchByValueDuplicate(doublyNode *&head, int n, int arr[])
{
    if (head == NULL)
        cout << "Not found your entered value." << endl;
    else
    {
        doublyNode *temp = head;
        int i = 1, count = 0;
        while (temp != NULL)
        {
            if (temp->value == n)
            {
                count++;
                arr[count] = i;
            };
            temp = temp->next;
            i++;
        }
        arr[0] = count;
    }
}

void insertAfterSpecificValue(doublyNode *&head, int searchVal, int val)
{
    int position = searchValuePosition(head, searchVal);
    int length = countLinkedList(head);
    if (position == -1)
        cout << "Your entered search input is not found!" << endl;
    else if (position == length)
        insertAtTail(head, val);
    else
    {
        insertAtSpecificPosition(head, position + 1, val);
    }
};

void insertAfterSpecificValueDuplicateList(doublyNode *&head, int searchVal, int val)
{
    int size = countLinkedList(head);
    int arr[size + 1];
    arr[0] = size;
    searchByValueDuplicate(head, searchVal, arr);
    if (arr[0] > 0)
    {
        for (int i = 1; i <= arr[0]; i++)
        {
            cout << "arr[i] " << arr[i] << " arr[i] + i " << arr[i] + i << " countLinkedList(head)" << countLinkedList(head) << endl;
            if (arr[i] + i == countLinkedList(head) + 1)
                insertAtTail(head, val);
            else
                insertAtSpecificPosition(head, arr[i] + i, val);
        }
    }
    else
    {
        cout << "Your entered value not found.";
    }
};

void deleteAtHead(doublyNode *&head)
{
    if (head == NULL)
        cout << "There is no value in the linked list" << endl;
    else
    {
        doublyNode *temp = head;
        if (head->next != NULL)
        {
            temp->next->prev = NULL;
        }
        head = temp->next;
        delete temp;
    }
}

void deleteAtTail(doublyNode *&head)
{
    if (head == NULL)
        cout << "There is no value in the linked list" << endl;
    else if (head->next == NULL)
    {
        deleteAtHead(head);
    }
    else
    {
        doublyNode *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        doublyNode *delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
}

void deleteAtSpecificPosition(doublyNode *&head, int pos)
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
        doublyNode *temp = head;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        doublyNode *delNode = temp->next;
        temp->next = delNode->next;
        delNode->next->prev = temp;
        delete delNode;
    }
};

void deleteBySpecificValue(doublyNode *&head, int val)
{
    int position = searchValuePosition(head, val);
    if (position == -1)
        cout << "Your entered search input is not found!" << endl;
    else
    {
        deleteAtSpecificPosition(head, position);
    }
};

void deleteBySpecificValueDuplicateList(doublyNode *&head, int val)
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


int main()
{
    doublyNode *head = NULL;

    int choice = 1, output, searchVal, val, position = 0;

    while (choice != 0)
    {
        cout << endl
             << endl
             << "1. Display list" << endl
             << "2. Insert at head" << endl
             << "3. Insert at tail" << endl
             << "4. View reverse list values" << endl
             << "5. Insertion at Specific Position" << endl
             << "6. Search a value (Unique List)" << endl
             << "7. Search a value (Duplication enabled List)" << endl
             << "8. Insertion after a specific value (Unique List)" << endl
             << "9. Insertion after a specific value (Duplication enabled List)" << endl
             << "10. Deletion at Head" << endl
             << "11. Deletion at Tail" << endl
             << "12. Deletion at a Specific Position" << endl
             << "13. Deletion by Value (Unique List)" << endl
             << "14. Deletion by Value(Duplication enabled List)" << endl
             << "Next choice:";

        cin >> choice;
        int size = countLinkedList(head);
        int arr[size + 1];
        arr[0] = size;

        switch (choice)
        {
        case 1:
            display(head);
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
            viewReverseList(head);
            break;

        case 5:
            cout << "Enter a number: ";
            cin >> val;
            cout << "Enter a position: ";
            cin >> position;
            insertAtSpecificPosition(head, position, val);
            break;

        case 6:
            cout << "Enter a number to search: ";
            cin >> val;
            output = searchValuePosition(head, val);
            if (output == -1)
                cout << "Your entered search input is not found!" << endl;
            else
                cout << "Your entered value found in position " << output << endl;
            break;

        case 7:
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

        case 8:
            cout << "Enter a number to search: ";
            cin >> searchVal;
            cout << "Enter a number to insert: ";
            cin >> val;
            insertAfterSpecificValue(head, searchVal, val);
            break;

        case 9:
            cout << "Enter a number to search: ";
            cin >> searchVal;
            cout << "Enter a number to insert: ";
            cin >> val;
            insertAfterSpecificValueDuplicateList(head, searchVal, val);
            break;

        case 10:
            deleteAtHead(head);
            break;

        case 11:
            deleteAtTail(head);
            break;

        case 12:
            cout << "Enter the position";
            cin >> position;
            deleteAtSpecificPosition(head, position);
            break;

        case 13:
            cout << "Enter value to delete ";
            cin >> val;
            deleteBySpecificValue(head, val);
            break;

        case 14:
            cout << "Enter value to delete ";
            cin >> val;
            deleteBySpecificValueDuplicateList(head, val);
            break;

        default:
            break;
        }
    }
    return 0;
};