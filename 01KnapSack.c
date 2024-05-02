#include <stdio.h>

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
}

int knapSack(int W, int wt[], int val[], int n) 
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) 
    {
        for (w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() 
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    int profit[n], weight[n];
    printf("Enter the weights:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &weight[i]);
    }
    
    printf("Enter the profits:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &profit[i]);
    }

    int W;
    printf("Enter the max weight: ");
    scanf("%d", &W);
    
    printf("Result: %d\n", knapSack(W, weight, profit, n));
    return 0;
}