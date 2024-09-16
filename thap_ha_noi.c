//
// Created by ACER on 8/17/2024.
//

#include <stdio.h>

void Thap_ha_noi(int n, char A, char B, char C)
{
    if(n==1)
    {
        printf("Chuyen dia %c->%c\n",A,C);
        return ;
    } else
    {
        Thap_ha_noi(n-1,A,C,B);
        printf("Chuyen dia %d %c->%c\n",n,A,C);
        Thap_ha_noi(n-1,B,A,C);
    }
}
int main()
{
    int n;
    printf("Nhap so dia: ");
    scanf("%d",&n);
    Thap_ha_noi(n,'A','B','C');
    return 0;
}
