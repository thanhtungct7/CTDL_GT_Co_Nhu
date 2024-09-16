//
// Created by ACER on 9/8/2024.
//

// đây là phương pháp sắp xếp dựa trên cách sắp xếp của bộ bài
// tìm vị trí mà phần tử sau có thể chèn vào để sắp xếp

#include <stdio.h>

void insert_sort(int *array, int length)
{
    for(int i=1;i<length;i++)
    {
        int key = array[i];
        int j = i-1;
        while (j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void print_array(int *array, int length)
{
    for(int i=0;i<length;i++)
    {
        printf("%d ",array[i]);
    }
}

int main()
{
    int array[9] = {4,2,3,5,7,9,8,1,6};
    insert_sort(array, 9);
    print_array(array, 9);
}