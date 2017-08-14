#include <stdio.h>
int main(void)
{
    int i, j, k;
    while(1)    //设置死循环
    {
        printf("line:");
        scanf("%d", &k);
        if(k < 1)   //设置死循环终止
            break;
        for(i = 1; i <= k; i++)
        {
            for(j = 0; j < (k - i); j++) //空格等于行数-1
                printf(" ");
            for(j = 1; j <= (2 * i - 1); j++)//*等于(行数*2-1)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}
