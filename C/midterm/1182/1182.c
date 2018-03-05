#include <stdio.h>
#include <string.h>
void sortCard();
void printCard();
char handCard[5][2] = {{ 0 }};	// [ranks, suits]

int main()
{
	char input[17];
	char ranks[13] = { 0 };	// 2 3 4 5 6 7 8 9 t j q k a
	char suits[4] = { 0 };	// c d h s
	int temp = 0;
	int illegalFlag = 0, duplicateFlag = 0;
	int straightFlag = 0;
	int flushFlag = 0;
	int aKindFlag = 0;
	int threeFlag = 0;
	int pairFlag = 0;

	while(fgets(input, 17, stdin) != NULL)
	{
		/* Init */
		for(int i = 0; i < 13; i++)
			ranks[i] = 0;
		for(int i = 0; i < 4; i++)
			suits[i] = 0;
		illegalFlag = 0;
		duplicateFlag = 0;
		straightFlag = 0;
		flushFlag = 0;
		aKindFlag = 0;
		threeFlag = 0;
		pairFlag = 0;

		/* Restrict Input Format */
		for(int i = 0; i < 5; i++)
		{
			/* ranks */
			/*
			if(i*3 >= (int)strlen(input))
			{
				illegalFlag = 1;
				break;
			}
			*/
			switch(input[i*3])
			{
				case 'a':
				case 'A':
					handCard[i][0] = 13 - 1;
					break;
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					handCard[i][0] = input[i*3] - '0' - 2;
					break;
				case 't':
				case 'T':
					handCard[i][0] = 10 - 2;
					break;
				case 'j':
				case 'J':
					handCard[i][0] = 11 - 2;
					break;
				case 'q':
				case 'Q':
					handCard[i][0] = 12 - 2;
					break;
				case 'k':
				case 'K':
					handCard[i][0] = 13 - 2;
					break;
				default:
					illegalFlag = 1;
			}
			/* suits */
			/*
			if(i*3 + 1 >= (int)strlen(input))
			{
				illegalFlag = 1;
				break;
			}
			*/
			switch(input[i*3 + 1])
			{
				case 'c':
				case 'C':
					handCard[i][1] = 0;
					break;
				case 'd':
				case 'D':
					handCard[i][1] = 1;
					break;
				case 'h':
				case 'H':
					handCard[i][1] = 2;
					break;
				case 's':
				case 'S':
					handCard[i][1] = 3;
					break;
				default:
					illegalFlag = 1;
			}

			/* Duplicating Check */
			for(int j = 0; j < i; j++)
			{
				if(handCard[i][0] == handCard[j][0] &&
				   handCard[i][1] == handCard[j][1])
				{
					duplicateFlag = 1;
					break;
				}

			}
		}
		if(illegalFlag && duplicateFlag)
		{
			printf("Illegal and Duplicate cards\n");
			continue;
		}
		else if(illegalFlag)
		{
			printf("Illegal card\n");
			continue;
		}
		else if(duplicateFlag)
		{
			printf("Duplicate card\n");
			continue;
		}

		/* Judge card shape */
		for(int i = 0; i < 5; i++)
		{
			ranks[handCard[i][0]] += 1;
			suits[handCard[i][1]] += 1;
		}

		/* Debug */
		/*
		printf("ranks: ");
		for(int i = 0; i < 13; i++)
			printf("%d ", ranks[i]);		
		printf("\n");
		printf("suits: ");
		for(int i = 0; i < 4; i++)
			printf("%d ", suits[i]);
		printf("\n");
		*/

		/* Judge Flush */
		for(int i = 0; i < 4; i++)
		{
			if(suits[i] == 5)
			{
				flushFlag = 1;
				break;
			}
		}	

		/* Judge Straight */
		temp = 0;
		if(ranks[12] == 1)
			temp += 1;
		for(int i = 0; i < 12; i++)
		{
			if(ranks[i] > 1)
				break;
			if(temp != 0 && ranks[i] == 0)
				break;
			if(ranks[i] == 1)
				temp += 1;
			if(temp == 5)
			{
				straightFlag = 1;
				break;
			}
		}
		/* A Special Situation of Straight */
		if(ranks[12] == 1)
		for(int i = 8; i < 12; i++)
		{
			if(ranks[i] != 1)
				break;
			if(i == 11)
				straightFlag = 1;
		}

		/* Judge Four Of a Kind */
		/* Judge Three Of a Kind and Pair */ 
		for(int i = 0; i < 13; i++)
		{
			if(ranks[i] == 4)
			{
				aKindFlag = 1;
				break;
			}
			if(ranks[i] == 3)
			{
				threeFlag = 1;
			}
			if(ranks[i] == 2)
			{
				pairFlag += 1;
			}
		}

		/* Debug */
		/*
		printf("Flags:\n");
		if(straightFlag)
			printf("straightFlag\n");
		if(flushFlag)
			printf("flushFlag\n");
		if(aKindFlag)
			printf("aKindFlag\n");
		if(threeFlag)
			printf("threeFlag\n");
		if(pairFlag)
			printf("pairFlag %d\n", pairFlag);
		*/

		/* Sorting handCard */
		sortCard();
		
		/* Printing handCard shape */
		if(straightFlag && flushFlag)
			printf("Straight Flush");
		else if(aKindFlag)
			printf("Four-Of-A-Kind");
		else if(threeFlag && pairFlag)
			printf("Full House");
		else if(flushFlag)
			printf("Flush");
		else if(straightFlag)
			printf("Straight");
		else if(threeFlag)
			printf("Three-Of-A-Kind");
		else if(pairFlag == 2)
			printf("Two Pairs");
		else if(pairFlag)
			printf("Pair");
		else
			printf("High Card");

		/* Printing handCard */
		printCard();
		printf("\n");
		
	}

	return 0;
}

void sortCard()
{
	int temp;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 1; j < 5 - i; j++)
		{
			if(handCard[j - 1][0] > handCard[j][0])
			{
				temp = handCard[j - 1][0];
				handCard[j - 1][0] = handCard[j][0];
				handCard[j][0] = temp;
				temp = handCard[j - 1][1];
				handCard[j - 1][1] = handCard[j][1];
				handCard[j][1] = temp;
			}
			else if(handCard[j - 1][0] == handCard[j][0])
			{
				if(handCard[j - 1][1] > handCard[j][1])
				{
					temp = handCard[j - 1][0];
					handCard[j - 1][0] = handCard[j][0];
					handCard[j][0] = temp;
					temp = handCard[j - 1][1];
					handCard[j - 1][1] = handCard[j][1];
					handCard[j][1] = temp;
				}
			}
			
		}
	}
}

void printCard()
{
	for(int i = 0; i < 5; i++)
	{
		printf(" ");
		switch(handCard[i][0])
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				printf("%d", handCard[i][0] + 2);
				break;
			case 8:
				printf("t");
				break;
			case 9:
				printf("j");
				break;
			case 10:
				printf("q");
				break;
			case 11:
				printf("k");
				break;
			case 12:
				printf("a");
				break;

		}
		switch(handCard[i][1])
		{
			case 0:
				printf("c");
				break;
			case 1:
				printf("d");
				break;
			case 2:
				printf("h");
				break;
			case 3:
				printf("s");
				break;
		}
	}
}
