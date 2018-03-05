#include <stdio.h>

int main()
{
	int n[2];
	int m[2], d[2], y[2];
	int m_c[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31 ,30 ,31};
	int m2_c[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31 ,30 ,31};
	int continue_flag = 0;
	while(scanf(" %d/%d/%d %d/%d/%d", &m[0], &d[0], &y[0], &m[1], &d[1], &y[1]) != EOF)
	{
		if( m[0] <= 0 || m[1] <= 0 || m[0] > 12 || m[1] > 12)
		{
			printf("Month Error!\n");
			continue;
		}
		
		if( d[0] <= 0 || d[1] <= 0)
		{
			printf("Day Error!\n");
			continue;
		}
		
		continue_flag = 0;
		for(int i = 0; i <= 1; i++)
		{
			if(y[i] % 4)
			{
				if(d[i] > m_c[m[i] - 1])
				{
					printf("Day Error!\n");
					continue_flag = 1;
					break;
				}
			}
			else
			{
				if(d[i] > m2_c[m[i] - 1])
				{
					printf("Day Error!\n");
					continue_flag = 1;
					break;
				}
			}
			n[i] = y[i] * 10000 + m[i] * 100 + d[i];
		}
		if(continue_flag) continue;

		(n[0] > n[1]) ? printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d\n", m[1], d[1], y[1], m[0], d[0], y[0])
			      : printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d\n", m[0], d[0], y[0], m[1], d[1], y[1]);

	}
	return 0;
}
