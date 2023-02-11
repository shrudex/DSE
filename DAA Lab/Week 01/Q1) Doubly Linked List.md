Write an algorithm😲 and program to implement a doubly linked list🔗 which supports the following operations:
1) Create the list by adding each node at the front.
2) Insert a new node to the left of the node whose key value is read as an input.
3) Delete all occurrences of a given key, if it is found. Otherwise, display appropriate message.
4) Search a node based on its key value.
5) Display the contents of the list.
   
```
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList {
private:
    Node *head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    Node* createNode(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->prev = NULL;
        temp->next = NULL;
        return temp;
    }

    void addNodeAtFront(int value) {
        Node *temp = createNode(value);
        if (head == NULL) {
            head = temp;
            return;
        }
        head->prev = temp;
        temp->next = head;
        head = temp;
    }

    void insertNodeToLeft(int key, int value) {
        Node *temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << key << " not found in the list." << endl;
            return;
        }
        Node *newNode = createNode(value);
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        Node *temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << key << " not found in the list." << endl;
            return;
        }
        while (temp != NULL && temp->data == key) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            if (temp == head) {
                head = temp->next;
            }
            Node *toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        cout << "Deleted all occurrences of " << key << " from the list." << endl;
    }

    void searchNode(int key) {
        Node *temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << key << " not found in the list." << endl;
            return;
        }
        cout << key << " found in the list." << endl;
    }

    void displayList() {
        Node *temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value, key;
    while (1) {
        cout << "1. Add a node at the front" << endl
                << "2. Insert a node to the left of a given key" << endl
        << "3. Delete all occurrences of a given key" << endl
        << "4. Search for a node with a given key" << endl
        << "5. Display the list" << endl
        << "6. Exit" << endl
        << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value of the node: ";
                cin >> value;
                dll.addNodeAtFront(value);
                break;
            case 2:
                cout << "Enter the key: ";
                cin >> key;
                cout << "Enter the value of the new node: ";
                cin >> value;
                dll.insertNodeToLeft(key, value);
                break;
            case 3:
                cout << "Enter the key to delete: ";
                cin >> key;
                dll.deleteNode(key);
                break;
            case 4:
                cout << "Enter the key to search for: ";
                cin >> key;
                dll.searchNode(key);
                break;
            case 5:
                dll.displayList();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    return 49;
}
```

**_Output_**

![image](https://user-images.githubusercontent.com/91502997/218237255-59425121-ec21-4163-a2ec-c74bf47c8809.png)
