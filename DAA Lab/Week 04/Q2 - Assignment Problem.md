### Write📝 a program📺 to solve the Assignment⚖️ problem.

```
#include <iostream>
#include <algorithm>

const int MAX_SIZE = 10;
const int INF = 10000000;

int n, min_cost = INF;
int cost[MAX_SIZE][MAX_SIZE], task_order[MAX_SIZE];

void brute_force(int k, int total_cost) {
    if (k == n) {
        min_cost = min(min_cost, total_cost);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (find(task_order, task_order+k, i) == task_order+k) {
            task_order[k] = i;
            brute_force(k+1, total_cost+cost[k][i]);
        }
    }
}

int main() {
    cout << "Enter the number of jobs : ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> cost[i][j];
    brute_force(0, 0);
    cout << min_cost << endl;
    return 49;
}
}
```
