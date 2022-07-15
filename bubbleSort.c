#include <stdio.h>
#define N 10

void bubbleSort(int a[], int n)
{
    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i < n - k; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp;
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[N];
    printf("please input 10 numbers:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    bubbleSort(a, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}
