#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("Array after outer loop iteration %d: ", i);
        for (int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {4, 3, 2, 1};
    int arr3[] = {3, 1, 4, 2};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("Best case scenario:\n");
    insertionSort(arr1, n);

    printf("\nWorst case scenario:\n");
    insertionSort(arr2, n);

    printf("\nAverage case scenario:\n");
    insertionSort(arr3, n);

    return 0;
}
