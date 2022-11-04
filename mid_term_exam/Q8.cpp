#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node(int val){
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
            if (temp->next != NULL)cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void insertAtTail(Node *&head, int val){
    Node *newNode = new Node(val);
    if (head == NULL) head = newNode;
    else{
        Node *temp;
        temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNextNNode(Node *&head, int M, int N){
    if (head == NULL) return;
    Node *temp = head;
    Node *keepEnd = temp;
    for (int i = 1; i < M; i++){
        temp = temp->next;
        keepEnd = temp;
    }
    temp = temp->next;
    Node *delNode = NULL;
    for (int i = 0; i < N; i++){
        delNode = temp;
        temp = temp->next;
        keepEnd->next = temp;
        delete delNode;
    }
    deleteNextNNode(temp, M, N);
}

int main(){
    // Inputs
    int K, M, N, val;
    cin >> K >> M >> N;
    Node *head = NULL;
    for (int i = 0; i < K; i++){
        cin >> val;
        insertAtTail(head, val);
    }

    deleteNextNNode(head, M, N);
    // Output
    displayList(head);
    return 0;
}