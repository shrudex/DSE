### Write✒️ a program to determine🤔 the height of a Binary Search Tree.🌲

```
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) root = createNode(value);
    else if (value <= root->value) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

int height(Node* root) {
    if (root == NULL) return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

int main() {
    Node* root = NULL;
    root = insert(root, 3);
    insert(root, 14);
    insert(root, 5);
    insert(root, 18);
    insert(root, 24);
    insert(root, 1);

    int h = height(root);
    cout << "The height of the binary search tree is: " << treeHeight << endl;

    return 49;
}
```
