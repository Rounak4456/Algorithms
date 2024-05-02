#include <stdio.h>

void binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            printf("Element is found at index: %d\n", mid);
            return; 
        }
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    printf("Element was not found\n");
}
int main()
{
    int n, key;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("The array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    printf("\n");
    printf("Enter the element to be found: ");
    scanf("%d", &key);

    binarySearch(arr, 0, n - 1, key);
    return 0;
}