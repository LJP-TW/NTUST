/* Thank to Tai-Ming for providing this solution */

#include <stdio.h>
#define LENGTH 2048

int main()
{
	int mount, maxNum, divisor, goOnFlag, allDoneFlag, nowNumMount;
	unsigned long long int nowNum, LCM;
	int num[10] = { 0 };
	unsigned long long int resultArray[LENGTH] = { 0 };
	int resultPointer = 0;
	while(scanf(" %d", &mount) != EOF)
	{
		/* Init */
		maxNum = 0;
		divisor = 2;
		goOnFlag = 0;
		allDoneFlag = 0;
		resultPointer = 0;
		for(int i = 0; i < LENGTH; i++)
		       resultArray[i] = 0;	

		/* Get Input */
		for(int i = 0; i < mount; i++)
		{
			scanf(" %d", &num[i]);
			if(num[i] > maxNum)
				maxNum = num[i];
		}
		
		/* Long division */
		do{
			goOnFlag = 0;
			allDoneFlag = 1;

			/* Can any num be divided ? */
			for(int i = 0; i < mount; i++)
			{
				if(num[i] > 1)
					allDoneFlag = 0;
				if(num[i] % divisor == 0)
				{
					
					goOnFlag = 1;
					break;
				}
			}
			
			if(allDoneFlag)
				break;

			/* divide nums or go to judge next divisor */
			if(goOnFlag)
			{
				resultArray[resultPointer] = divisor;
				++resultPointer;
				for(int i = 0; i < mount; i++)
				{
					if(num[i] % divisor == 0)
					{
						num[i] /= divisor;
					}
				}
			}
			else
				++divisor;
		}while(divisor <= maxNum);

		/* Output */
		LCM = 1;
		nowNum = 0;
		nowNumMount = 0;
		for(int i = 0; i < resultPointer; i++)
		{
			/* Init */
			if(nowNum == 0)
			{
				nowNum = resultArray[i];
				nowNumMount = 1;
			}
			else if(nowNum != resultArray[i])
			{
				printf("(%llu^%d)", nowNum, nowNumMount);
				nowNum = resultArray[i];
				nowNumMount = 1;
			}
			else
			{
				nowNumMount += 1;
			}

			if(i == resultPointer - 1)
			{
				printf("(%llu^%d)", nowNum, nowNumMount);
			}
			LCM *= resultArray[i];
		}	
		printf("\n");
		printf("LCM: %llu\n", LCM);
	}

	return 0;
}
