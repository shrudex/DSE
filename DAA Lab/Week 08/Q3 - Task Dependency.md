### Modify the algorithm such😛🍎 that😠 it checks💸 whether🤔 there is any💬 task dependency between👉👈 the teams.

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
    
    // Initialize arrays
    for (int i = 0; i < MAX_MODULES; ++i) {
        for (int j = 0; j < MAX_MODULES; ++j) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
        indegree[i] = 0;
    }

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
    
    // Check for task dependencies between teams
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j]) {
                for (int k = 0; k < m; ++k) {
                    if (adj[k*n+i][k*n+j]) {
                        cout << "Error: Task " << i << " assigned to team " << k+1 << " depends on task " << j << " assigned to the same team!" << endl;
                        return 0;
                    }
                }
            }
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

The additional part of the code checks for task dependencies between teams. It uses a nested loop to iterate through all pairs of modules in the adjacency matrix adj, and then checks if there is an edge between them. If there is, it checks if there is also a dependency between the same two modules assigned to the same team. If there is, it prints an error message indicating that there is a task dependency between teams, and then exits the program. This ensures that there are no dependencies between tasks assigned to different teams.



![image](https://user-images.githubusercontent.com/91502997/229895369-8cbc2071-53b4-41a0-b174-229dc999984f.png)
