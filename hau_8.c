//
// Created by ACER on 8/17/2024.
//

#include <stdio.h>

int a[8]={1,1,1,1,1,1,1,1};
int b[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int c[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int x=0;
void in_mang(int *arr)
{
    for(int i=0;i<8;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void try(int j, int *arr)
{
    for(int i=0;i<8;i++)
    {
        if(a[i]&&b[i+j]&&c[i-j+7])
        {
            arr[j]=i+1;
            a[i]=0;
            b[i+j]=0;
            c[i-j+7]=0;
            if(j<7)
            {
                try(j+1,arr);
            }
            else
            {
                in_mang(arr);
                printf("%d\n",x++);
            }
            a[i]=1;
            b[i+j]=1;
            c[i-j+7]=1;
        }
    }
}
int main()
{
    int arr[8];
    try(0,arr);
}