# ✅Question - 03
## Write a program to construct the _Open Hash Table#️⃣_. Find the number of key comparisons🔀 in successful search and unsuccessful search🔎.

```
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_TABLE_SIZE = 100;

struct Node {
    int data;
    Node* next;
};

class HashTable {
private:
    Node* table[MAX_TABLE_SIZE];
public:
    HashTable() {
        memset(table, 0, sizeof(table));
    }
    int hashFunction(int key) 
        return key % MAX_TABLE_SIZE;

    //inserting a new key-value pair into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = NULL;

        if (table[index] == NULL) {
            //inserting the new node as the head
            table[index] = newNode;
        } else {
            //adding the new node to the end
            Node* temp = table[index];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    //searching for a key in the hash table
    int search(int key) {
        int index = hashFunction(key);
        int count = 0;
        Node* temp = table[index];
        while (temp != NULL) {
            count++;
            if (temp->data == key)
                return count;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    HashTable hashTable;
    int n;
    cout << "Enter the number of keys to insert: ";
    cin >> n;

    cout << "Enter the keys to insert: ";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        hashTable.insert(key);
    }

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    int comparisons = hashTable.search(key);
    cout << "Number of key comparisons: " << comparisons << endl;

    return 49;
}
```

![image](https://github.com/shrudex/DSE/assets/91502997/fd5a85f3-682c-4deb-9be7-693870164948)
