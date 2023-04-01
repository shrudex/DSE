### Write a program to find diameter😨 of a binary tree🌳. Diameter of a binary tree is the longest🍆 path between any two nodes.

```
#include <iostream>
using namespace std;
const int MAX_RANGE = 50;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* InsertNode(Node* root, int data)
{
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
    Node* queue[MAX_RANGE];
    int front, rear = 0;
    queue[rear] = root;
    
    while (front<=rear) {
        Node* temp = queue[front++];
        if (temp->left != NULL)	queue[++rear] = (temp->left);
        
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)	queue[++rear] = (temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}

void inOrder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inOrder(temp->left);
    cout << temp->data << ' ';
    inOrder(temp->right);
}

int h(Node* node)
{
    if (node == NULL)	return 0;
    return 1 + max(h(node->left), h(node->right));
}

int diameter(Node* tree)
{
    if (tree == NULL)
        return 0;
 
    int lh = h(tree->left);
    int rh = h(tree->right);
 
    int ld = diameter(tree->left);
    int rd = diameter(tree->right);
    
    return max(lh + rh + 1,
               max(ld, rd));
}
 
int main()
{
	int n, ele;
    cout << "For the construction of Binary Tree, firstly construct a BT" << endl;
    cout << "For that, tell the number of elements to be added in BT : ";
    cin >> n;
    cout << "Start entering the elements, they will be added in a level-wise order" << endl;
    cin >> ele;
    Node* root = CreateNode(ele);
    Node* copy = root;
    
    for (int i=1; i<n; ++i) {
		cin >> ele;
		root = InsertNode (root, ele);
	}
	
    cout << "Inorder traversal : ";
    inOrder(root);
    cout << endl;
    
    cout << "Diamter of the Binary Tree : " << diameter(copy);
    return 49;
}
```
