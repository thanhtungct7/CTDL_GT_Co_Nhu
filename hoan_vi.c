#include<stdio.h>

void in_ket_qua(int *arr, int r)
{
    for(int i=0;i<r;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
void hoan_vi(int *arr, int l, int r)
{
    if(l==r)
    {
        in_ket_qua(arr,r+1);
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            // hoán đổi phần tử hiện tại với phần tử bắt đầu
            int temp=arr[l];
            arr[l]=arr[i];
            arr[i]=temp;

            // gọi đệ quy cho phần tử tiếp theo
            hoan_vi(arr,l+1,r);

            // hoán đổi phần tử hiện tại với phần từ bắt đầu 1 lần nữa
            temp=arr[l];
            arr[l]=arr[i];
            arr[i]=temp;
        }
    }
}

int main()
{
    int n ;
    printf("Hay nhap so phan tu cua mang: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    hoan_vi(arr,0,n-1);
}