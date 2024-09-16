//
// Created by ACER on 9/12/2024.
//

#include <stdio.h>

void print_arr(int K[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", K[i]);
    }
    printf("\n");
}

void merger(int K[], int X[], int b, int m, int n)
{
    int i = b, j = m + 1, t = b;
    while (i <= m && j <= n)
    {
        if (K[i] < K[j])
        {
            X[t++] = K[i++];
        }
        else
        {
            X[t++] = K[j++];
        }
    }
    while (i <= m)
    {
        X[t++] = K[i++];
    }
    while (j <= n)
    {
        X[t++] = K[j++];
    }
}

void MPass(int K[], int X[], int n, int h)
{
    int i = 0;
    while (i + 2 * h <= n)
    {
        merger(K, X, i, i + h - 1, i + 2 * h - 1);
        i += 2 * h;
    }
    if (i + h < n)
    {
        merger(K, X, i, i + h - 1, n - 1);
    }
    else
    {
        for (; i < n; i++)
        {
            X[i] = K[i];
        }
    }
}

void straight_Msort(int K[], int X[], int n)
{
    int h = 1;
    while (h < n)
    {
        MPass(K, X, n, h);
        h *= 2;
        MPass(X, K, n, h);
        h *= 2;
    }
}

int main()
{
    int K[11] = {50, 10, 15, 40, 60, 5, 20, 25, 35, 4, 30};
    int X[11];
    straight_Msort(K, X, 11);
    printf("Mảng đã sắp xếp:\n");
    print_arr(K, 11);
    return 0;
}
