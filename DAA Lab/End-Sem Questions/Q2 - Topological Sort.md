# ✅Question - 02
## Write a program to determine the _Topological Sort🔝_ of a given graph📊 using _Depth-First_ technique.

```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

void depthFirstSearch(int vertex, int adjList[][MAX], int visited[], int n, int& currentIndex, int sortedOrder[]) {
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adjList[vertex][i] == 1 && visited[i] == 0)
            depthFirstSearch(i, adjList, visited, n, currentIndex, sortedOrder);
    }

    sortedOrder[currentIndex] = vertex;
    currentIndex--;
}

void topologicalSort(int adjList[][MAX], int n) {
    int visited[MAX] = {0};
    int sortedOrder[MAX];
    int currentIndex = n - 1;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0)
            depthFirstSearch(i, adjList, visited, n, currentIndex, sortedOrder);
    }

    cout << "Topological Sort: ";
    for (int i = 0; i < n; i++)
        cout << sortedOrder[i] << " ";
}

int main() {
    int n, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;
    cout << "Enter the edges (source destination):" << endl;

    int adjList[MAX][MAX] = {0};
    int degree[MAX] = {0};

    for (int i = 0; i < e; ++i) {
        int u, v;
		    cin >> u >> v;
		    adjL[u][degree[u]++] = v;
		    adjL[v][degree[v]++] = u;
    }

    cout << "DFS Order: ";
    topologicalSort(adjList, n);

    return 49;
}
```
