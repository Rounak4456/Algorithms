#include<stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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

    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if(min != i)
            Swap(&arr[i], &arr[min]);
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d \t", arr[i]);    
}