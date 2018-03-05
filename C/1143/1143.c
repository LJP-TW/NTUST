#include <stdio.h>

int main()
{
	int puz, ans, temp;
	int _puz[3], _ans[3];
	int a_count = 0, b_count = 0;
	while( scanf(" %d %d", &puz, &ans) != EOF )
	{
		a_count = 0;
		b_count = 0;
		
		if((puz / 1000) > 0 || (ans / 1000) > 0 || (puz / 100) == 0 || (ans / 100) == 0)
		{
			printf("3 digits please\n");
			continue;
		}

		_puz[0] = puz / 100;
		temp = puz % 100;
		_puz[1] = temp / 10;
		temp %= 10;
		_puz[2] = temp;
		
		_ans[0] = ans / 100;
		temp = ans % 100;
		_ans[1] = temp / 10;
		temp %= 10;
		_ans[2] = temp;
		temp = 0;

		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(i != j)
				{
					if(_puz[i] == _puz[j] || _ans[i] == _ans[j])
					{
						printf("Numbers can't be the same!\n");
						temp = 1;
						break;
					}
				}
			}
			if(temp) break;
		}
		if(temp) continue;
		
	
		for(int i = 0; i < 3; i++)	
		{
			for(int j = 0; j < 3; j++)
			{
				if(i == j)
				{
					if(_puz[i] == _ans[i])
						a_count++;
				}
				else
				{
					if(_puz[i] == _ans[j])
						b_count++;
				}
					
			}
			
		}

		printf("Puzzle: %d\n", puz);
		printf("Answer: %d\n", ans);
		printf("%dA%dB\n", a_count, b_count);
	}
	return 0;
}
