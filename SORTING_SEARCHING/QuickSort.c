#include <stdio.h>

void QuickSort(int arr[], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (arr[i] <= arr[pivot])
            {
                i++;
            }
            while (arr[j] > arr[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        QuickSort(arr, first, j - 1);
        QuickSort(arr, j + 1, last);
    }
}

    void printArray(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

int main()
{
    int size, i;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    QuickSort(arr, 0, size - 1);
    printArray(arr, size);
}
