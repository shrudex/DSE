# ✅Question - 01
## Write a program to find Minimum Cost Spanning Tree🌲 of a given undirected graph📊 using _Prim’s algorithm_.

```
#include <iostream>
#include <climits>
using namespace std;

//finding the minimum vertex in the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

//printing the MST
void printMST(int parent[], int **graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

//finding the MST
void primMST(int **graph, int V) {
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    int **graph = new int *[V];
    for (int i = 0; i < V; i++) graph[i] = new int[V];
    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) cin >> graph[i][j];
    }
    primMST(graph, V);
    return 49;
}
```

![image](https://github.com/shrudex/DSE/assets/91502997/ac2b8055-b0f1-44b3-93b3-49454613f49d)

