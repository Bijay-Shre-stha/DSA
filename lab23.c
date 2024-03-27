#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        printf("Array after outer loop iteration %d: ", i + 1);
        for (int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
        if (swapped == 0)
            break;
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {4, 3, 2, 1};
    int arr3[] = {3, 1, 4, 2};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("Best case scenario:\n");
    bubbleSort(arr1, n);

    printf("\nWorst case scenario:\n");
    bubbleSort(arr2, n);

    printf("\nAverage case scenario:\n");
    bubbleSort(arr3, n);

    return 0;
}
