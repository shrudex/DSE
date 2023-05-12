# ✅Question - 02
## Write a program to find Minimum Cost Spanning Tree🌲 of a given undirected graph📊 using _Kruskal's algorithm_.

```
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

//finding the parent of a vertex in a subset
int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    parent[x] = y;
}

//finding the MST
void kruskalMST(Edge edge[], int V, int E) {
    sort(edge, edge + E, cmp);  //sorting the edges by their weights
    Edge MST[V - 1];
    int parent[V];
    memset(parent, -1, sizeof(parent));
    int count = 0, i = 0;
    while (count < V - 1 && i < E) {
        Edge currentEdge = edge[i++];
        int x = find(parent, currentEdge.src);
        int y = find(parent, currentEdge.dest);
        if (x != y) {
            MST[count++] = currentEdge;
            Union(parent, x, y);
        }
    }
    cout << "Edge \tWeight\n";
    for (i = 0; i < V - 1; ++i)
        cout << MST[i].src << " - " << MST[i].dest << "\t" << MST[i].weight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    Edge edge[E];
    cout << "Enter the source vertex, destination vertex and weight of each edge:\n";
    for (int i = 0; i < E; ++i)
        cin >> edge[i].src >> edge[i].dest >> edge[i].weight;
    kruskalMST(edge, V, E);
    return 49;
}
```

![image](https://github.com/shrudex/DSE/assets/91502997/20c834df-3b40-49f4-ba1c-f03b310a6177)

