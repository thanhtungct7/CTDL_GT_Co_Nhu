//
// Created by ACER on 9/8/2024.
//

// đây là phương pháp cải tiến của phương pháp đổi chỗ
// chọn 1 phần tử ngẫu nhiên của mảng là "chốt" mọi phần tử trước "chốt" phải nhỏ hơn chốt
// các phần tử sau "chốt" thì phải lớn hơn chốt
// lặp lại đến khi mỗi đoạn còn 1 phần tử

#include <stdio.h>

int parition(int *arr,int indexlatch, int length)
{
    int pivot = arr[indexlatch];
    int i = indexlatch+1;
    int j = length;
    do
    {
        while (i<=j && arr[i] < pivot)
        {
            i++;
        }
        while (i<=j && arr[j] > pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i<=j);
    int temp = arr[indexlatch];
    arr[indexlatch] = arr[j];
    arr[j] = temp;

    return j;
}

void quick_sort(int *arr,int indexlatch, int length)
{
    if(indexlatch<length)
    {
        int j = parition(arr,indexlatch,length);
        quick_sort(arr,j+1,length);
        quick_sort(arr,indexlatch,j-1);

    }
}

void display(int *arr,int length)
{
    for(int i=0;i<length;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[7] = {12,7,30,40,8,38,35};
    quick_sort(arr,0,6);
    display(arr,7);
}


