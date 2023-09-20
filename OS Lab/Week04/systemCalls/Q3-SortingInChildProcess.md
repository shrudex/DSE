## Q3 - Accept an array of integers. Display the unsorted array in the parent process. Create a child process. Sort and display the sorted array in the child process.

### C program - **sortingArray.c**
```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int n;

    printf("Enter the n of the array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &nums[i]);

    pid_t child = fork();

    if (child < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (child == 0) {
        int temp, i, j;
        
        //bubble sort algorithm
        for (i = 0; i < n - 1; ++i) {
            for (j = 0; j < n - i - 1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }

        printf("Sorted array (in child process): ");
        for (i = 0; i < n; ++i)
            printf("%d ", nums[i]);
        
        printf("\n");
    	} 
    else {
        printf("Unsorted array (in parent process): ");
       	for (int i = 0; i < n; i++)
        	printf("%d ", nums[i]);
        printf("\n");
    }
    return 49;
}
```

### Command to compile the C program
```
gcc -o sortingArray sortingArray.c
```

### Command to run the program
```
./sortingArray
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/7c1c3417-1ec9-46b9-8934-e04fcd774ea8)
![image](https://github.com/shrudex/DSE/assets/91502997/5779bc2c-2a60-49f3-870d-3be48535dfe8)

