#include <stdio.h>
#include <stdlib.h>

void tree(int *space_count, int *output_length, int layer_height);

int main()
{
	int layer_count, flag, space_count, output_length, temp;
	printf("Input how many layer: ");
	scanf(" %d", &layer_count);
//	layer_count = 3;

	int *layer = malloc(layer_count*sizeof(int));
	int *num = malloc(layer_count*sizeof(int));
	
	while( printf("Input each growth height of the %d layers Xmas tree: ", layer_count) )
	{
		flag = 0;
		for(int i = 0; i < layer_count; i++)
			if( scanf(" %d", &num[i]) == EOF)
			{
				flag = 1;
				break;
			}
		
		if(flag)
			break;
		

		for(int i = 0; i < layer_count; i++)
			if(layer[i] + num[i] < 2)
			{
				printf("Invalid layer condition! Roll back to last status\n");
				flag = 1;
				break;
			}

		if(flag == 0)
			for(int i = 0; i < layer_count; i++)
				layer[i] += num[i];
		
		printf("Heights of %d layers: ", layer_count);
		for(int i = 0; i < layer_count - 1; i++)
			printf("%d ", layer[i]);
		printf("%d\n", layer[layer_count - 1]);

		if(flag)
			continue;

		/* print tree */
		space_count = layer[0] - 1;
		for(int i = 1; i < layer_count; i++)
			space_count += layer[i] - 2;
		output_length = 1;
		for(int i = 0; i < layer_count; i++)
		{
			tree(&space_count, &output_length, layer[i]);
			space_count += 2;
			output_length -= 4;
			//printf("space_count : %d \n output_length : %d \n", space_count, output_length);
		}
		
		/* finally */
		if(output_length == 1)
			printf(" |\n");
		else
		{
			temp = (output_length + 1 - 2) / 2;
			for(int i = 0; i < temp; i++)
			{
				printf(" ");
			}
			printf("| |\n");
		}	
	}
	free(layer);
	free(num);
	return 0;
}

void tree(int *space_count, int *output_length, int layer_height)
{
	for(int i = 0; i < layer_height; i++)
	{
		for(int i = 0; i < *space_count; i++)
			printf(" ");
		if(*output_length == 1)
			printf("*\n");
		else if(*output_length == 3)
			printf("*o*\n");
		else
		{
			printf("*o");
			for(int i = 0; i < *output_length - 4; i++)
				printf("*");
			printf("o*\n");
		}
		*space_count -= 1;
		*output_length += 2;
	}
}
