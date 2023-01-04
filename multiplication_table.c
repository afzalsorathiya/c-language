#include <stdio.h>

void main()
{
    int num;
    printf("Enter Multiplication table number \n");
    scanf("%d", &num);

    for (int i = 1; i < 11; i++)
    {
        /* code */
        printf("%d X %d = %d\n", num, i, num * i);
    }
}