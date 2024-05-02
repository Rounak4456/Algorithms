#include <stdio.h>

int main()
{
    int n, i, j, min;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array:  \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 1; i < n; i++)
    {
        min = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > min)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = min;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}