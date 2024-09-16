//
// Created by ACER on 9/10/2024.
//

#include <stdio.h>

void ADJUST(int *arr,int r, int n)
{
    int v = arr[r];
    while (2*r<=n-2)
    {
        int c = 2*r+1;
        if(c<n-1 && arr[c]<arr[c+1])
        {
            c++;
        }
        if(arr[c]<v)
        {
            break;
        }
        arr[r] = arr[c];
        r=c;
    }
    arr[r] = v;
}

void heap_sort(int *arr, int n)
{
    for (int i = (n-2)/2; i >= 0; i--)
    {
        ADJUST(arr, i, n);
    }

    for (int i = n-1; i >= 0; i--)
    {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        ADJUST(arr, 0, i);
    }

}

void printfarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[9]  = {9,6,4,5,8,7,2,1,3};
    heap_sort(arr,9);
    printfarr(arr,9);
}