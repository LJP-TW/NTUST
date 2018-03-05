#include <stdio.h>
int main()
{
    int firstFlag, min, max, maxLength, tempLength, n;
    while (scanf(" %d %d", &min, &max) != EOF)
    {
        firstFlag = 1;
        maxLength = -1;
 
        for (int i = min; i <= max; i++)
        {
            n = i;
            tempLength = 0;
            do
            {
                /* step 1 */
                tempLength += 1;
 
                /* step 2 */
                if (n == 1)
                    break;
                if (n % 2)
                    n = 3 * n + 1;
                else
                    n /= 2;
            } while (1);
            if (tempLength > maxLength)
                maxLength = tempLength;
        }
         
        printf("%d %d %d\n", min, max, maxLength);
    }
    return 0;
}