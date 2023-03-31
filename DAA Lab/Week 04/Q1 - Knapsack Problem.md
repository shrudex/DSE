### Write📝 a program📺 to solve the Knapsack⚖️ problem.

```
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int calcMaxVal(unsigned int *wt, unsigned int *val, unsigned int num, unsigned int cap) {
    int i, t;
    int max = 0, seq = 0;
    int total_wt, total_val;
    int index = 0;

    // Generate bit array
    for (i = 1; i < pow(2, num); i++) {
        // Compute total weight and total value of current item combination
        t = i;
        total_wt = total_val = 0;
        index = 0;
        while (t) {
            if (t & 0x1) {
                total_wt += wt[index];
                total_val += val[index];
            }
            index++;
            t = t >> 1;
        }

        // Update maximum value and maximum value bit mask if current combination is valid and yields greater value
        if (total_wt <= cap && total_val > max) {
            max = total_val;
            seq = i;
        }
    }

    return seq;
}

int main() {
    int *val, *wt, num, cap, knap, i;

    // Read input values
    cout << "Enter the number of items: ";
    cin >> num;
    val = new int[num];
    wt = new int[num];
    cout << "Please enter the weights of the items: ";
    for (i = 0; i < num; i++) {
        cin >> wt[i];
    }
    cout << "Please enter the values of the items: ";
    for (i = 0; i < num; i++) {
        cin >> val[i];
    }
    cout << "Please enter the knapsack capacity: ";
    cin >> cap;

    // Compute maximum value and the items that yield the maximum value
    knap = calcMaxVal(wt, val, num, cap);

    // Print the items that yield the maximum value
    cout << "Knapsack contains the following items:\n";
    i = 0;
    while (knap) {
        if (knap & 0x1) {
            cout << "Item " << (i + 1) << " value " << val[i] << "\n";
        }
        i++;
        knap = knap >> 1;
    }
    return 49;
}
```
