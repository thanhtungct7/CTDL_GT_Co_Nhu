//
// Created by ACER on 8/18/2024.
//
#include <stdbool.h>
#include <stdio.h>

int phan_cong_viec(int n, int a[][n], int person, int use_job[n])
{
    if(person == n+1)
    {
        return 0;
    }
    int max_job = 0;
    for(int i=0;i<n;i++)
    {
        if(use_job[i]==0)
        {
            use_job[i]=1;
            int sum_job = a[person][i] + phan_cong_viec(n,a,person+1,use_job);
            use_job[i] = 0;
            if(sum_job>max_job)
            {
                max_job = sum_job;
            }
        }
    }
    return max_job;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int use_job[n];
    for(int i=0;i<n;i++)
    {
        use_job[i] = 0;
    }
    printf("Tong so cong viec lon nhat cua moi nguoi la: %d",phan_cong_viec(n,a,0,use_job));
    return 0;
}