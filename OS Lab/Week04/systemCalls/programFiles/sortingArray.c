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

    if (child < 0){
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
