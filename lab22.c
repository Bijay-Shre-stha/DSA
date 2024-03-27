#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
        {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
        printf("Array after outer loop iteration %d: ", i + 1);
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
    selectionSort(arr1, n);

    printf("\nWorst case scenario:\n");
    selectionSort(arr2, n);

    printf("\nAverage case scenario:\n");
    selectionSort(arr3, n);

}
