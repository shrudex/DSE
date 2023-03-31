### Write✍ a program📺 to create😮 a AVL tree🎄 for🌍 a set of integers. For the AVL tree🎄 created, 🔨🎨 insert an element 6.💪

```
#include <iostream>
#include <cstdlib>
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

int Height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int BalanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return Height(node->left) - Height(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(Height(y->left), Height(y->right)) + 1;
    x->height = max(Height(x->left), Height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(Height(x->left), Height(x->right)) + 1;
    y->height = max(Height(y->left), Height(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    else {
        return root;
    }

    root->height = max(Height(root->left), Height(root->right)) + 1;
    int balanceFactor = BalanceFactor(root);

    if (balanceFactor > 1 && data < root->left->data) {
        return rightRotate(root);
    }

    if (balanceFactor > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balanceFactor < -1 && data > root->right->data) {
        return leftRotate(root);
    }

    if (balanceFactor < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {3, 14, 5, 18, 24, 1};
    int n = 6;

    for (int i = 0; i < n; ++i)   root = insert(root, arr[i]);
    
    cout << "AVL tree elements after insertion: ";
    root = insert(root, 6);
    inOrder(root);
    return 49;
 }
```
