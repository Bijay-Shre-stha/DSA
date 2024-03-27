#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m, L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    for (int i = 0, j = 0, k = l; k <= r; k++)
    {
        if (j >= n2 || (i < n1 && L[i] <= R[j]))
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
        printf("Array after merge: ");
        for (int i = l; i <= r; i++)
            printf("%d ", arr[i]);
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
    mergeSort(arr1, 0, n - 1);

    printf("\nWorst case scenario:\n");
    mergeSort(arr2, 0, n - 1);

    printf("\nAverage case scenario:\n");
    mergeSort(arr3, 0, n - 1);

    return 0;
}
