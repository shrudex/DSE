# ✅Question - 02
## Write a program to compute the _Transitive Closure📪_ of a given directed graph📊 using _Warshall's Algorithm_.

```
#include <iostream>
#include <cstring>
using namespace std;

void transitiveClosure(int **graph, int n) {
    int **closure = new int*[n];
    for (int i = 0; i < n; i++) {
        closure[i] = new int[n];
        memcpy(closure[i], graph[i], n * sizeof(int));
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
        }
    }
    cout << "Transitive closure is:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << closure[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;
    int **graph = new int*[n];
    cout << "Enter the adjacency matrix of the graph:" << endl;
    for (int i = 0; i < n; ++i) {
        graph[i] = new int[n];
        for (int j = 0; j < n; ++j) cin >> graph[i][j];
    }
    transitiveClosure(graph, n);
    return 49;
}
```

![image](https://github.com/shrudex/DSE/assets/91502997/578e99cc-174f-4d73-b592-44a11f84c21f)
