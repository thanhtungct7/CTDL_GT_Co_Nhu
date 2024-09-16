//
// Created by ACER on 9/8/2024.
//

// đây là kiểu sắp xếp tìm phần tử bé nhất sau vị trí i
// nếu phần tử bé nhất có vị trí lớn hơn i thì đổi chỗ 2 phần tử cho nhau

#include <stdio.h>

void selection_sort(int arr[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min = i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[min]>arr[j])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    int arr[9] = {4,5 ,7,9,8,6,3,2,1};
    selection_sort(arr, 9);
    print_array(arr,9);
}