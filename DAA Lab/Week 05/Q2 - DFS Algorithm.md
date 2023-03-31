### Write📝 a program📺 to implement DFS algorithm.
```
#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;

int graph[MAX_VERTICES][MAX_VERTICES] = {0};
bool visited[MAX_VERTICES] = {false};

void dfs(int vertex, int n)
{
    visited[vertex] = true;
    cout << vertex << " ";
    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            dfs(i, n);
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges : ";
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Adjacency list:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
                cout << j << " ";
        }
        cout << endl;
    }

    cout << "DFS traversal: ";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, n);
    }
    cout << endl;

    return 49;
}
```
