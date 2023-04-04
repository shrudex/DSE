### A student👨‍🎓 management system😏💋 should be developed🚀 by a software👨‍💻 company. There😏 are certain🤔🤔 dependent and independent🙅 modules that must be developed🚀 by K teams. The unit testing and integration testing is done✅ before the deployment of the product. 
### Design🖌️ an algorithm using📤📤 decrease and conquer technique such😛🍎 that it gives😚 a schedule of tasks🙌🤗 in the order in which👏🤤 it must be🤜 executed.

```
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_TEAMS = 100;
const int MAX_MODULES = 100;

int adj[MAX_MODULES][MAX_MODULES];
int visited[MAX_MODULES];
int indegree[MAX_MODULES];
int n, m;

// Function to add an edge between two modules
void addEdge(int u, int v) {
    adj[u][v] = 1;
    indegree[v]++;
}

// Function to print the schedule of tasks
void printSchedule(int schedule[]) {
    cout << "The schedule of tasks is: ";
    for (int i = 0; i < n; ++i) {
        cout << schedule[i] << " ";
    }
    cout << endl;
}

// Function to find the next independent module
int getNextIndependent() {
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && indegree[i] == 0) {
            visited[i] = 1;
            return i;
        }
    }
    return -1;
}

// Function to generate the schedule of tasks
void generateSchedule() {
    int schedule[MAX_MODULES];
    int i = 0;

    // Find and add all independent modules to the schedule
    while (i < n) {
        int j = getNextIndependent();
        if (j == -1) {
            cout << "Error: No independent module found!" << endl;
            return;
        }
        schedule[i++] = j;
        for (int k = 0; k < n; ++k) {
            if (adj[j][k]) {
                indegree[k]--;
            }
        }
    }
    printSchedule(schedule);
}

int main() {
    cout << "Enter the number of modules: ";
    cin >> n;
    cout << "Enter the number of teams: ";
    cin >> m;
    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));
    memset(indegree, 0, sizeof(indegree));

    // Add dependencies between modules based on team assignments
    for (int i = 0; i < m; ++i) {
        int num, u, v;
        cout << "Enter the number of dependent modules for team " << i+1 << ": ";
        cin >> num;
        cout << "Enter the dependent modules for team " << i+1 << ": ";
        cin >> u;
        for (int j = 1; j < num; ++j) {
            cin >> v;
            addEdge(u, v);
            u = v;
        }
    }

    // Generate the schedule of tasks
    generateSchedule();

    return 0;
}
```

### CREDITS - **chatGPT**
Please note that the code provided was written by ChatGPT and not by me. I want to give full credits to ChatGPT for their work.

### EXPLANATION
The program prompts the user to enter the number of modules and teams, and then takes the team assignments and dependencies between modules as input. It then uses the decrease and conquer technique to generate a schedule of tasks in the order in which they must be executed.

The addEdge function adds an edge between two modules in the adjacency matrix adj. The printSchedule function prints the schedule of tasks to the console. The getNextIndependent function finds the next independent module (i.e., a module with no dependencies) that has not yet been visited.

The generateSchedule function uses a loop to find and add all independent modules to the schedule, and then updates the indegree of all modules that depend on the independent modules. This process is repeated until all modules have been added to the schedule. If at any point an independent module cannot process (i.e., there are no more independent modules), the function prints an error message.



![image](https://user-images.githubusercontent.com/91502997/229891238-f7d5a3d4-46c0-4021-b109-7cbc6558ffa2.png)
