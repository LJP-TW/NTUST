#include <stdio.h>
#include <string.h>
#include <math.h>
 
int armstrong_num(int);
 
int main()
{
    int min, max, flag;
    while (scanf(" %d %d", &min, &max) != EOF)
    {
        flag = 1;
        for (int i = min; i <= max; i++)
        {
            if (armstrong_num(i))
            {
                if (flag)
                {
                    printf("%d", i);
                    flag = 0;
                }
                else
                    printf(", %d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
 
int armstrong_num(int n)
{
    int temp = n;
    int digits = 1;
    int sum = 0;
 
    while (temp >= 10)
    {
        temp /= 10;
        ++digits;
    }
 
    temp = n;
 
    for (int i = 0; i < digits; i++)
    {
        sum += pow(temp % 10, digits);
        temp -= temp % 10;
        temp /= 10;
    }
 
    if (sum == n)
        return 1;
    else
        return 0;
}