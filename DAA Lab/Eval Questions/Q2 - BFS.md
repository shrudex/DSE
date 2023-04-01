### Perform👨🏻‍💻 Breadth First Search Traversal✈️ on an un-directed graph📈 and perform the following operations: 
+ Show the queue content at each step.
+ Show the order of the traversal.

```
#include <iostream>
using namespace std;

void showContent (int q[], int f, int r) {
	cout << "Queue content : " << endl;
	for (int i=f; i<=r; ++i) cout << q[i] << " ";
	cout << endl;
	return;
}

void showBFS (int b[], int c) {
	cout << "Breadth First Search Traversal : " << endl;
	for (int i=0; i<c; ++i)	cout << b[i] << " ";
	cout << endl;
	return;
}

int main() {
	int n, e;
	cout << "Enter the number of vertices and edges : ";
	cin >> n >> e;
	cout << "Enter the path (source destination) : " << endl;
	int degree[n] = {0};
	int adjL [n][n];
	
	//Adjacency List Creation
	for (int i=0; i<e; ++i) {
		int u, v;
		cin >> u >> v;
		adjL[u][degree[u]++] = v;
		adjL[v][degree[v]++] = u;
	}
	int visited[n] = {0};
	int bfs[n], queue[n*n], count=0, rear=0, front=0;
	queue[front] = 0;
	visited[0] = 1;
	showContent (queue, front, rear);
	while (front<=rear) {
		int temp = queue[front];
		front++;
		bfs[count++] = temp;
		for (int i=0; i<degree[temp]; ++i){
			if (visited[adjL[temp][i]]==0) {
				queue [++rear] = adjL[temp][i];
				visited [adjL[temp][i]] = 1;
			}
		}
		showContent (queue, front, rear);
	}
	showBFS (bfs, count);
	return 49;
}
```
