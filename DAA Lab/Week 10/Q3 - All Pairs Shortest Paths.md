# ✅Question - 03
## Write a program to implement _Floyd’s Algorithm_ for the _All-Pairs-ShortestPaths🚶🏻‍♂️_ problem for any given graph📊.

```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

void floyd(int graph[][MAX], int n)
{
    int dist[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INT_MAX) cout << "INF ";
            else cout << dist[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int n, graph[MAX][MAX];
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix for the graph: " << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];
    floyd(graph, n);
    return 49;
}
```

![image](https://github.com/shrudex/DSE/assets/91502997/830a310f-c3ef-492d-a462-0db093c46c20)
