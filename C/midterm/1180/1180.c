#include <stdio.h>
#include <string.h>
 
int main()
{
    char bin[100] = { 0 };
    int length = 0;
    int dec = 0;
    int value = 1;
    while (scanf(" %s", bin) != EOF)
    {
        length = (int)strlen(bin);
        dec = 0;
        value = 1;
        for (int i = length - 1; i >= 0; i--)
        {
            if (bin[i] == '1')
                dec += value;
            value *= 2;
        }
        printf("%d\n", dec);
    }
    return 0;
}