## Write📝 a program📺 to implement BFS algorithm.
_node begins with 1 and not 0_
```
#include <iostream>
using namespace std;
int main() {
	int n, m;
	cout << "Enter the no. of vertices and edges : ";
	cin >> n >> m;
	int adjL[n+1][n+1];
	int degree[n+1] = {0};
	cout << "Enter the edges : "<< endl;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		adjL[u][degree[u]++] = v;
		adjL[v][degree[v]++] = u;
	}
	cout << "Adjacency List" << endl;
	for (int i=1; i<=n; ++i) {
		cout << i << " : ";
		for (int j=0; j<degree[i]; ++j) cout << adjL[i][j] << " ";
		cout << endl;
	}
	int visited[n+1] = {0};
	int q[n*n];
	int front = 0;
	int rear = 0;
	q[rear++] = 1;
	visited[1] = 1;
	int bfs[n];
	int count = 0;
	while (rear>=front) {
		int t = q[front];
		front++;
		bfs[count++] = t;
		for (int i=0; i<degree[t]; ++i) {
			if (!visited[adjL[t][i]]) {
				q[rear++] = adjL[t][i];
				visited[adjL[t][i]]=1;
			}
		}
	}
	for (int i=0; i<count; ++i)	cout << bfs[i] << " ";
	return 49;
}
```
