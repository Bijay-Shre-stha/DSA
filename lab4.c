#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr;
    
    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for 'n' integers
    arr = (int *)malloc(n * sizeof(int));
    
    // Check if memory allocation is successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit the program with an error code
    }
    
    // Input 'n' numbers from the user
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Calculate sum, average, max, and min
    int sum = 0, max = arr[0], min = arr[0];
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    // Calculate average
    double average = (double)sum / n;
    
    // Display results
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    
    // Free dynamically allocated memory
    free(arr);
    
    return 0;
}
