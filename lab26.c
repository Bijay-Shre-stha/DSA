#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr1[] = {12, 11, 13, 5, 6, 7}, arr2[] = {7, 6, 5, 4, 3, 2}, arr3[] = {5, 2, 9, 1, 5, 6}, n = 6;
    heapSort(arr1, n);
    heapSort(arr2, n);
    heapSort(arr3, n);
    printf("Best case: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    printf("Worst case: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    printf("Average case: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr3[i]);
    printf("\n");
    return 0;
}
