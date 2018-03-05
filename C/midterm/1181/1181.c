#include <stdio.h>
#include <string.h>
 
int main()
{
    char a[20], b[20];
    char result[40];
    int lenA, lenB, remove0Flag;
    while (scanf(" %s %s", a, b) != EOF)
    {
        /* Init */
        lenA = (int)strlen(a);
        lenB = (int)strlen(b);
        remove0Flag = 1;
        for (int i = 0; i < 40; i++)
        {
            result[i] = 0;
        }
 
        /* Calculate */
        for (int i = 1; i <= lenA ; i++)
        {
            for (int j = 1; j <= lenB; j++)
            {
                result[(i-1) + (j-1)] += (a[lenA - i] - '0') * (b[lenB - j] - '0');
                if (result[(i - 1) + (j - 1)] >= 10)
                {
                    result[(i - 1) + (j - 1) + 1] += (result[(i - 1) + (j - 1)] / 10);
                    result[(i - 1) + (j - 1)] %= 10;
                }
            }           
        }
 
        /* printOut*/
        for (int i = 39; i >= 0; i--)
        {
            if (remove0Flag)
            {
                if (result[i] != 0)
                {
                    remove0Flag = 0;
                    printf("%d", result[i]);
                }
            }
            else
                printf("%d", result[i]);
        }
        printf("\n");
    }
    return 0;
}