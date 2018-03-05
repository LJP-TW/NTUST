#include <stdio.h>
void scoreCalculate(int);
double score;
int n;

int main()
{
	int p;
	int s;
	int r;
	char lastStep[2];
	
	while(scanf(" %d", &n) != EOF)
	{
		/* Init */
		score = 0;
		p = 0;
		s = 0;
		r = 0;
		
		/* Main Algorithm */
		for(int i = 1; i <= n; i++)
		{
			if(i == 1)
			{
				/* AI Move Will Be Paper */
				s += 1;
				lastStep[0] = 's';
				lastStep[1] = 1;
				printf("S");

				/* Get score */
				scoreCalculate(i);
				continue;
			}
			
			/* AI Move Will Be Scissors */
			if((p > s && p > r) || (lastStep[0] == 'p' && lastStep[1] == 2) || (p > r && s > r && p == s))
			{
				r += 1;
				/* If next round can't be predicted && this round isn't final round */
				if(r == p && r == s && lastStep[0] != 'r' && i != n)
				{
					/* Go back */
					r -= 1;

					/* p == s */
					/* Make a tie */
					s += 1;
					if(lastStep[0] == 's')
						lastStep[1] += 1;
					else
					{
						lastStep[0] = 's';
						lastStep[1] = 1;
					}
					printf("S");

					/* No Score at this round */
				}
				else
				{
					/* Win */
					if(lastStep[0] == 'r')	
						lastStep[1] += 1;
					else
					{
						lastStep[0] = 'r';
						lastStep[1] = 1;
					}
					printf("R");

					/* Get score */
					scoreCalculate(i);
				}
			}
			/* AI Move Will Be Rock */
			else if((s > p && s > r) || (lastStep[0] == 's' && lastStep[1] == 2) || (r > p && s > p && r == s))
			{
				p += 1;
				/* If next round can't be predicted && this round isn't final round */
				if(p == s && p == r && lastStep[0] != 'p' && i != n)
				{
					/* Go back */
					p -= 1;

					/* p == s */
					/* Make a tie */
					r += 1;
					if(lastStep[0] == 'r')
						lastStep[1] += 1;
					else
					{
						lastStep[0] = 'r';
						lastStep[1] = 1;
					}
					printf("R");

					/* No Score at this round */
				}
				else
				{
					/* Win */
					if(lastStep[0] == 'p')	
						lastStep[1] += 1;
					else
					{
						lastStep[0] = 'p';
						lastStep[1] = 1;
					}
					printf("P");

					/* Get score */
					scoreCalculate(i);
				}
			}
			/* AI Move Will Be Paper */
			else if((r > p && r > s) || (lastStep[0] == 'r' && lastStep[1] == 2) || (p > s && r > s && p == r))
			{
				s += 1;
				/* If next round can't be predicted && this round isn't final round */
				if(s == p && s == r && lastStep[0] != 's' && i != n)
				{
					/* Go back */
					s -= 1;

					/* p == s */
					/* Make a tie */
					p += 1;
					if(lastStep[0] == 'p')
						lastStep[1] += 1;
					else
					{
						lastStep[0] = 'p';
						lastStep[1] = 1;
					}
					printf("P");

					/* No Score at this round */
				}
				else
				{
					/* Win */
					if(lastStep[0] == 's')	
						lastStep[1] += 1;
					else
					{
						lastStep[0] = 's';
						lastStep[1] = 1;
					}
					printf("S");

					/* Get score */
					scoreCalculate(i);
				}
			}

			/* Debug */
			/*
			printf("\n");
			printf("p: %d\n", p);
			printf("s: %d\n", s);
			printf("r: %d\n", r);
			*/
			
		}
		
		/* Print score */
		printf(" %.3f\n", score);
	}

	return 0;
}

void scoreCalculate(int i)
{
	score += 1 + 0.1 * (double)(n - i + 1) / (double)n;
}
