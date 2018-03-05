#include <stdio.h>
 
int main()
{
    char str1[4], str2[4], temp[1024];
    int a, b;
    while(fgets(temp, 1024, stdin) != NULL)
    {
        /* Init */
        sscanf(temp, " %4s", str1);
        fgets(temp, 1024, stdin);
        sscanf(temp, " %4s", str2);
        a = 0;
        b = 0;
 
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(str1[i] == str2[j])
                {
                    if(i == j)
                        ++a;
                    else
                        ++b;
                }
            }
        }   
 
        printf("%dA%dB\n", a, b);
    }
    return 0;
}