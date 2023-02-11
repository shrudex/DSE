Write a program😲 to construct a binary tree🌳 to support the following operations. Assume no duplicate elements🙅‍♂️ while constructing👷‍♂️ the tree🌳.
1) Given a key, perform a search🔎 in the binary tree🌳. If the key is found☑️ then display “key found”🥰 else inserts the key👨‍💻 in the BST.
2) Display the tree🌳 using inorder, preorder and post order traversal methods⏩. 

```
	#include <iostream>
	using namespace std;
	
	struct Node {
	    int key;
	    Node *left, *right;
	};
	
	Node* newNode(int key) {
	    Node* node = new Node();
	    node->key = key;
	    node->left = node->right = NULL;
	    return node;
	}
	
	Node* insert(Node* node, int key) {
	    if (node == NULL) return newNode(key);
	    if (key < node->key)
	        node->left = insert(node->left, key);
	    else if (key > node->key)
	        node->right = insert(node->right, key);
	    return node;
	}
	
	bool search(Node* node, int key) {
	    if (node == NULL) return false;
	    if (node->key == key) return true;
	    if (key < node->key)
	        return search(node->left, key);
	    else
	        return search(node->right, key);
	}
	
	void inorder(Node* node) {
	    if (node != NULL) {
	        inorder(node->left);
	        cout << node->key << " ";
	        inorder(node->right);
	    }
	}
	
	void preorder(Node* node) {
	    if (node != NULL) {
	        cout << node->key << " ";
	        preorder(node->left);
	        preorder(node->right);
	    }
	}
	
	void postorder(Node* node) {
	    if (node != NULL) {
	        postorder(node->left);
	        postorder(node->right);
	        cout << node->key << " ";
	    }
	}
	
	int main() {
	    Node* root = NULL;
	    int choice, key;
	    while (true) {
	        cout << endl << "Menu:" << endl;
	        cout << "1. Search or Insert a key" << endl;
	        cout << "2. Display the tree using In-order traversal" << endl;
	        cout << "3. Display the tree using Pre-order traversal" << endl;
	        cout << "4. Display the tree using Post-order traversal" << endl;
	        cout << "5. Exit" << endl;
	        cout << "Enter your choice: ";
	        cin >> choice;
	        switch (choice) {
	            case 1:
	                cout << "Enter a key: ";
	                cin >> key;
	                if (search(root, key))
	                    cout << "Key found!" << endl;
	                else
	                    root = insert(root, key);
	                break;
	            case 2:
	                cout << "In-order: ";
	                inorder(root);
	                cout << endl;
	                break;
	            case 3:
	                cout << "Pre-order: ";
	                preorder(root);
	                cout << endl;
	                break;
	            case 4:
	                cout << "Post-order: ";
	                postorder(root);
	                cout << endl;
	                break;
	            case 5:
	                exit(0);
	            default:
	                cout << "Invalid choice, please try again." << endl;
	}
	}
	return 49;
	}
```

**_Output_**

![image](https://user-images.githubusercontent.com/91502997/218237700-0ae7d2ab-dd8c-4bc0-abf8-215d67e132e4.png)

