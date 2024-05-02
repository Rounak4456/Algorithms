#include<stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(arr, low, high);

        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }
}


int main()
{
    int n, i, j, min;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array:  \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, 0, n-1);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d \t", arr[i]);   
    
}