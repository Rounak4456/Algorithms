#include<stdio.h>

void Merge(int arr[], int l, int m, int r) 
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[m + 1+ j];

    int i=0, j=0, k = l;

    while (i < n1 && j < n2) 
    {
        if (L[i] <= M[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) 
{
    if ( l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        Merge(arr, l , m, r);
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

    mergeSort(arr, 0, n-1);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d \t", arr[i]);  
}