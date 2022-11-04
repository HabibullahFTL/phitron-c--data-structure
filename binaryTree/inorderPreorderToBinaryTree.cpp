#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int val)
    {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void preOrderTraversal(treeNode *rootNode, string &chk)
{
    if (rootNode == NULL)
        return;

    chk += to_string(rootNode->data);
    chk += " ";
    preOrderTraversal(rootNode->leftChild, chk);
    preOrderTraversal(rootNode->rightChild, chk);
}

int searchPosInInOrder(int inOrder[], int current, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == current)
            return i;
    }

    return -1;
}

treeNode *buildTreeFromPreIn(int preOrder[], int inOrder[], int start, int end)
{
    static int id = 0;
    int current = preOrder[id];
    id++;
    treeNode *newNode = new treeNode(current);

    if (start == end)
        return newNode;

    int pos = searchPosInInOrder(inOrder, current, start, end);
    newNode->leftChild = buildTreeFromPreIn(preOrder, inOrder, start, pos - 1);
    newNode->rightChild = buildTreeFromPreIn(preOrder, inOrder, pos + 1, end);

    return newNode;
}

int main()
{
    int n;
    cin >> n;
    int preOrder[n], inOrder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }

    treeNode *rootNode = buildTreeFromPreIn(preOrder, inOrder, 0, n - 1);

    string preOrderTrav = "";
    preOrderTraversal(rootNode, preOrderTrav);
    cout << preOrderTrav << endl;

    return 0;
}

/*
Pre-Order: 0 1 3 4 2 5 7 8 6
In-Order: 3 1 4 0 7 5 8 2 6

9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6


9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
*/