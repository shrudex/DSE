# ✅Question - 03
## Write a program to find shortest path🛣️ from a given vertex to other vertices in each weighted⚖️ connected graph📊, using _Dijkstra's algorithm_.

```
#include <iostream>
#include <climits>
using namespace std;

const int MAX_VERTICES = 100;

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int source, int num_vertices) {
    int dist[num_vertices]; 
    bool visited[num_vertices];
    for(int i=0; i<num_vertices; i++) {
        dist[i] = INT_MAX; 
        visited[i] = false;
    }
    dist[source] = 0; 
    for(int count=0; count<num_vertices-1; count++) {
        int u = -1;
        for(int i=0; i<num_vertices; i++) {
            if(!visited[i] && (u == -1 || dist[i] < dist[u])) u = i;
        }
        visited[u] = true;
        for(int v=0; v<num_vertices; v++) {
            if(graph[u][v] != 0 && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    cout << "Shortest distances from vertex " << source << ":\n";
    for(int i=0; i<num_vertices; i++) {
        if(dist[i] == INT_MAX)
            cout << i << ": " << "Infinity" << endl;
        else
            cout << i << ": " << dist[i] << endl;
    }
}

int main() {
    int num_vertices, source;
    int graph[MAX_VERTICES][MAX_VERTICES];

    cout << "Enter the number of vertices: ";
    cin >> num_vertices;
    cout << "Enter the adjacency matrix of the graph:\n";
    for(int i=0; i<num_vertices; i++) {
        for(int j=0; j<num_vertices; j++)
            cin >> graph[i][j];
    }
    cout << "Enter the source vertex: ";
    cin >> source;
    dijkstra(graph, source, num_vertices);
    return 49;
}
```

![image](https://github.com/shrudex/DSE/assets/91502997/a87bd34a-c7bc-464b-b73c-63274cadb027)

