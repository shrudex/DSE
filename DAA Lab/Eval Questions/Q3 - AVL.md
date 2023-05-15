## ✅Question - 03
### Write a program to create an _AVL Tree🌲_ for a set of numbers. Once created, insert➡️ 2 elements to the _AVL Tree🌲_. 
### Determine the _Height👆🏻_ of the AVL Tree and show the different _Traversal Methods🚶🏻‍♂️_.

```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(Node* node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* z = x->right;

    x->right = y;
    y->left = z;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* z = y->left;

    y->left = x;
    x->right = z;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    updateHeight(root);
    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && data < root->left->data)
        return rightRotate(root);
 
    if (balanceFactor > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balanceFactor < -1 && data > root->right->data)
        return leftRotate(root);

    if (balanceFactor < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int calculateHeight(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = NULL;
    cout << "How many elements will you enter in the AVL tree? : ";
    int n;
    cin >> n;
    
    cout << "Start entering the elements : ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    
    cout << "Traversals before INSERTION of 2 elements : " << endl;
    
    cout << "InOrder" << endl;
    inOrderTraversal(root);
    cout << endl;
    
    cout << "PreOrder" << endl;
    preOrderTraversal(root);
    cout << endl;
    
    cout << "PostOrder" << endl;
    postOrderTraversal(root);
    cout << endl << endl;
    
    int num1, num2;
    cout << "Enter 2 new elements : ";
    cin >> num1 >> num2;
    
    root = insert (root, num1);
    root = insert (root, num2);
    
    cout << "AVL Tree after INSERTION : " << endl;

    cout << "InOrder Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "PreOrder Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    int treeHeight = calculateHeight(root);
    cout << "Height of the AVL Tree: " << treeHeight << endl;

    return 40;
}
```

![image](https://github.com/shrudex/DSE/assets/91502997/0137ddce-fbe7-4c12-9a1e-fcbab2de112e)
