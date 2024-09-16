#include <stdio.h>

int convert(char trungto[] , char stack[] , char hauto[], int n)
{
    int indexhauto=0;
    int indexstack=0;

    for(int i=0;i<n;i++)
    {
        if(trungto[i] >='0' && trungto[i] <= '9')
        {
            hauto[indexhauto] = trungto[i];
            indexhauto++;
        }
        else if(trungto[i]=='*'||trungto[i]=='/'||trungto[i]=='(')
        {
            stack[indexstack]=trungto[i];
            indexstack++;
        } else if(trungto[i]=='+'||trungto[i]=='-')
        {
            if (stack[indexstack-1]=='*'||stack[indexstack-1]=='/')
            {
                hauto[indexhauto]= stack[indexstack-1];
                indexhauto++;
                indexstack--;

            }
            stack[indexstack]=trungto[i];
            indexstack++;
        }
        else if(trungto[i]==')')
        {
            while(indexstack>0&&stack[indexstack-1]!='(')
            {
                hauto[indexhauto]= stack[indexstack-1];
                indexstack--;
                indexhauto++;
            }
            if(indexstack>0)
            {
                indexstack--;
            }
        }
    }
    while (indexstack>0)
    {
        hauto[indexhauto]= stack[indexstack-1];
        indexstack--;
        indexhauto++;
    }
    return indexhauto;
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    char stack[n];
    char trungto[n];
    char hauto[n];
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&trungto[i]);
    }
    int indexhauto= convert(trungto,stack,hauto,n);
    for(int i=0;i<indexhauto;i++)
    {
        printf("%c ",hauto[i]);
    }
}