#include <stdio.h>
#include <string.h>
 
int main()
{
    char str1[102] = { 0 };
    char str2[102] = { 0 };
    char result[102] = { 0 };
    char tempStr[102] = { 0 };
    int maxLength = 0;
    int tempLength = 0;
 
    while (fgets(str1, 102, stdin) != NULL)
    {
        fgets(str2, 102, stdin);
        for (int i = 0; i < 102; i++)
        {
            result[i] = 0;
            tempStr[i] = 0;
        }
        maxLength = 0;
        tempLength = 0;
 
        str1[(int)strlen(str1) - 1] = 0;
        str2[(int)strlen(str2) - 1] = 0;
 
        //printf("%d %d", (int)strlen(str1), (int)strlen(str2));
 
        for (int i = 0; i < (int)strlen(str1); i++)
        {
            for (int j = 0; j < (int)strlen(str2); j++)
            {
                if (str1[i] == str2[j])
                {
                    tempLength = 0;
                    for (int k = 0; k < 200; k++)
                    {
                        if (i + k < (int)strlen(str1) && j + k < (int)strlen(str2))
                        {
                            if (str1[i + k] == str2[j + k])
                            {
                                tempStr[k] = str1[i + k];
                                ++tempLength;
                            }
                            else
                            {
                                if (tempLength > maxLength)
                                {
                                    for (int l = 0; l < tempLength; l++)
                                    {
                                        result[l] = tempStr[l];
                                    }
                                    maxLength = tempLength;
                                }
                                break;
                            }
                        }
                        else
                        {
                            if (tempLength > maxLength)
                            {
                                for (int l = 0; l < tempLength; l++)
                                {
                                    result[l] = tempStr[l];
                                }
                                maxLength = tempLength;
                            }
                            break;
                        }
                    }
                }
            }
        }
 
        printf("%s\n", result);
    }
    return 0;
}