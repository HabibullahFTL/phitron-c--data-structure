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

/*
In-order: Left Root Right


Pre-order: Root Left Right
0 1 3 4 2 5 7 8 6
Root: 0
Left:
    Root: 1
    Left: 3
    Right: 4
Right:
    Root: 2
    Left:
        Root: 5
        Left: 7
        Right: 8
    Right: 6

Post-order: Left Right Root
*/

void printSpace(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }
}

void printTree(treeNode *rootNode, int level)
{
    // If there is no node in the rootNode
    if (rootNode == NULL)
        return;

    // If the root node has no right and left node
    if (rootNode->leftChild == NULL && rootNode->rightChild == NULL)
    {
        cout << rootNode->data << endl;
        return;
    }
    cout << endl;
    printSpace(level);
    cout << "Root: " << rootNode->data << endl;
    if (rootNode->leftChild != NULL)
    {
        printSpace(level);
        cout << "Left: ";
        printTree(rootNode->leftChild, level + 1);
    }

    if (rootNode->rightChild != NULL)
    {
        printSpace(level);
        cout << "Right: ";
        printTree(rootNode->rightChild, level + 1);
    }
}

void inOrder(treeNode *rootNode, string &chk)
{
    if (rootNode == NULL)
        return;

    inOrder(rootNode->leftChild, chk);
    chk += to_string(rootNode->data);
    chk += " ";
    inOrder(rootNode->rightChild, chk);
}

void preOrder(treeNode *rootNode, string &chk)
{
    if (rootNode == NULL)
        return;

    chk += to_string(rootNode->data);
    chk += " ";
    preOrder(rootNode->leftChild, chk);
    preOrder(rootNode->rightChild, chk);
}

void postOrder(treeNode *rootNode, string &chk)
{
    if (rootNode == NULL)
        return;

    postOrder(rootNode->leftChild, chk);
    postOrder(rootNode->rightChild, chk);
    chk += to_string(rootNode->data);
    chk += " ";
}

int levelOrderTraversal(treeNode *rootNode, string &chk, int k)
{
    if (rootNode == NULL)
        return -1;

    queue<treeNode *> q;
    q.push(rootNode);
    q.push(NULL);
    int level = 0;
    int maxNum = INT_MIN;

    while (!q.empty())
    {
        treeNode *checkNode = q.front();
        q.pop();

        if (checkNode != NULL)
        {
            if (maxNum < checkNode->data)
            {
                maxNum = checkNode->data;
            }
            cout << checkNode->data << " ";

            if (checkNode->leftChild)
            {
                q.push(checkNode->leftChild);
            }
            if (checkNode->rightChild)
            {
                q.push(checkNode->rightChild);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
    }
    return maxNum;
}

int main()
{
    int n;
    cin >> n;

    treeNode *allNodes[n];

    for (int i = 0; i < n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;
        allNodes[i]->data = value;

        if (left != -1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }

        if (right != -1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }
    printTree(allNodes[0], 0);

    string inOrderTraversal = "";
    inOrder(allNodes[0], inOrderTraversal);
    cout << inOrderTraversal << endl;

    string preOrderTraversal = "";
    preOrder(allNodes[0], preOrderTraversal);
    cout << preOrderTraversal << endl;

    // string postOrderTraversal = "";
    // postOrder(allNodes[0], postOrderTraversal);
    // cout << postOrderTraversal << endl;

    // string levelOrdrTrav = "";
    // levelOrderTraversal(allNodes[0], levelOrdrTrav, 2);

    // cout << endl
    //      << levelOrdrTrav << endl;
    return 0;
}

/*
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