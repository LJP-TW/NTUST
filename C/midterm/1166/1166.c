#include <stdio.h>
#include <string.h>
#define LENGTH 5800
void factorial();
 
char Num[LENGTH] = { 0 };
char resultNum[LENGTH] = { 0 };
int numDigits = 1;
int resultDigits = 1;
char tempNum[LENGTH] = { 0 };
 
int main()
{
    int n = 0;
 
    while (scanf(" %d", &n) != EOF)
    {
        for (int i = 0; i < LENGTH; i++)
        {
            Num[i] = 0;
        }
        Num[0] = 1;
        resultNum[0] = 1;
        numDigits = 1;
        resultDigits = 1;
 
        for (int i = 0; i < n; i++)
        {
            factorial();
            Num[0] += 1;
            for (int i = 0; i < numDigits; i++)
            {
                if (Num[i] >= 10)
                {
                    Num[i + 1] += 1;
                    Num[i] -= 10;
                }
            }
            // check numDigits
            for (int i = LENGTH - 1; i >= 0; i--)
            {
                if (Num[i] == 0)
                    continue;
                else
                {
                    numDigits = i + 1;
                    break;
                }
            }
        }
 
        for (int i = resultDigits - 1; i >= 0; i--)
            printf("%c", resultNum[i] + '0');
        printf("\n");
    }
    return 0;
}

void factorial()
{
    // Init
    int rd = resultDigits;
    int nd = numDigits;
 
    for (int i = 0; i < LENGTH; i++)
        tempNum[i] = 0;
 
 
    // Calculate
    for (int i = 0; i < rd; i++)
    {
        for (int j = 0; j < nd; j++)
        {
            tempNum[i + j] += resultNum[i] * Num[j];
 
            while (tempNum[i + j] >= 10)
            {
                tempNum[i + j + 1] += 1;
                tempNum[i + j] -= 10;
            }
        }
    }
 
    // check resultDigits
    for (int i = LENGTH - 1; i >= 0; i--)
    {
        if (tempNum[i] == 0)
            continue;
        else
        {
            resultDigits = i+1;
            break;
        }
    }
 
    // result = temp
    for (int i = 0; i < resultDigits; i++)
        resultNum[i] = tempNum[i];
}
