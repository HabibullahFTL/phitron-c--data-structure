#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node(int val) {
        value = val;
        next = NULL;
    }
};

void displayList(Node *&head){
    if (head != NULL){
        Node *temp;
        temp = head;
        while (temp != NULL){
            cout << temp->value;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void insertAtTail(Node *&head, int val){
    Node *newNode = new Node(val);
    if (head == NULL)
        head = newNode;
    else{
        Node *temp;
        temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node *reverseRecursive(Node *&head, Node *&reverseTill, Node *&endNode){
    if (head->next == NULL || head == NULL || head == reverseTill)
        return head;

    Node *newHead = reverseRecursive(head->next, reverseTill, endNode);
    head->next->next = head;
    head->next = endNode;
    return newHead;
};

void reverseKNodes(Node *&head, int K){
    // First reverse functionalities
    Node *kthNode = NULL;
    Node *afterKthStart = NULL;
    Node *newKthEnd = head;
    Node *temp = head;
    for (int i = 1; i < K; i++){
        temp = temp->next;
    }
    kthNode = temp;
    afterKthStart = kthNode->next;
    head = reverseRecursive(head, kthNode, afterKthStart);
    
    // Second reverse functionalities
    while (temp->next != NULL){
        temp = temp->next;
    }
    Node *afterKthEnd = NULL;
    Node *secondReversedList = reverseRecursive(afterKthStart, temp, afterKthEnd);
    newKthEnd->next = secondReversedList;
}

int main(){
    // Inputs
    int N, K, val;
    cin >> N;
    Node *head = NULL;
    for (int i = 0; i < N; i++){
        cin >> val;
        insertAtTail(head, val);
    }
    cin >> K;
    reverseKNodes(head, K);
    // Output
    displayList(head);
    return 0;
}