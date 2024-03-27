#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
        printf("Array after partitioning with pivot %d: ", arr[pi]);
        for (int i = low; i <= high; i++) printf("%d ", arr[i]);
        printf("\n");
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 1};
    int arr3[] = {3, 1, 4, 2, 5};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("Best case scenario:\n");
    quickSort(arr1, 0, n - 1);

    printf("\nWorst case scenario:\n");
    quickSort(arr2, 0, n - 1);

    printf("\nAverage case scenario:\n");
    quickSort(arr3, 0, n - 1);

    return 0;
}
