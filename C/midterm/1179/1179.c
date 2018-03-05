#include <stdio.h>
 
int main()
{
    int layer = 0;
    int flag = 1;
    while (scanf(" %d", &layer) != EOF)
    {
        flag = 1;
        for (int i = 0; i < layer; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                    printf("%d", flag++);
                else
                    printf(" %d", flag++);
            }
            printf("\n");
        }
    }
    return 0;
}