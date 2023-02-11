Write a program😲 to implement the following graph📈 representations:
1) Adjacency list🔗
2) Adjacency matrix🔢

```
#include <iostream>
using namespace std;  
const int N = 100;

int adj[N][N];
int degree[N];

void addEdgeList(int u, int v, int V) {
    adj[u][degree[u]] = v;
    degree[u]++;
    adj[v][degree[v]] = u;
    degree[v]++;
}

void displayList(int V) {
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int j = 0; j < degree[i]; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

int graph[N][N];

//add an edge to the adjacency matrix 
void addEdgeMatrix(int u, int v) {
    graph[u][v] = graph[v][u] = 1;
}

void displayMatrix(int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int V = 5, choice, u, v;
    while (true) {
        cout << endl << "Menu:" << endl;
        cout << "1. Add an edge (Adjacency List)" << endl;
        cout << "2. Display (Adjacency List)" << endl;
        cout << "3. Add an edge (Adjacency Matrix)" << endl;
        cout << "4. Display (Adjacency Matrix)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the two vertices (u and v) of the edge: ";
                cin >> u >> v;
                addEdgeList(u, v, V);
                break;
            case 2:
                displayList(V);
                break;
            case 3:
                cout << "Enter the two vertices (u and v) of the edge: ";
                cin >> u >> v;
                addEdgeMatrix(u, v);
                break;
            case 4:
                displayMatrix(V);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 49;
}
```

**_Output_**

![image](https://user-images.githubusercontent.com/91502997/218237958-aafe034c-7585-46e0-b2c9-75b9c25dacba.png)
