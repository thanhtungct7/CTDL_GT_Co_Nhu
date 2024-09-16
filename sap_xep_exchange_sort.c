//
// Created by ACER on 9/8/2024.
//

// đây là sắp xếp kiểu đổi chỗ
// duyệt từ cuối lên
#include <stdio.h>

void exchange_sort(int arr[], int size)
{
    for (int i=0; i<size ;i++)
    {
        for(int j=size-1;j>=i;j--)
        {
            if(arr[j]<arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

void print_array(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[9] = {9,4,2,5,6,7,1,3,8};
    exchange_sort(arr, 9);
    print_array(arr, 9);
}