#include <stdio.h>
#include <string.h>
#define LABEL_LEN 16
#define ATTR_NUM 30
#define TRANING_DATA_NUM 128
#define BUFFER_LEN 2048

struct Attribute {
	char label[LABEL_LEN];
	long double value;
	int match;
};

struct Data {
	char label[LABEL_LEN];
	int attr_mount;
	struct Attribute attr[ATTR_NUM];
};

int main()
{
	char temp[BUFFER_LEN] = { 0 };
	fgets(temp, BUFFER_LEN, stdin);
	do
	{
		/* Training data: */
		if(strncmp(temp, "Training data:", 13) != 0)
			break;

		/* Initial */
		struct Data trainData[TRANING_DATA_NUM];
		memset(&trainData, 0, sizeof(trainData));
		int trainData_mount = 0;
		long double _default;
		int k;
		int breakFlag = 0;

		/* Default value: */
		fgets(temp, BUFFER_LEN, stdin);
		sscanf(temp, " Default value: %Lf", &_default);

		/* Get Training Data */
		while(1)
		{
			fgets(temp, BUFFER_LEN, stdin);
			
			/* If temp isn't "Test data" */
			if(strncmp(temp, "Test data", 9))
			{
				/* Get Attr And Label */
				int attr_index = 0;
				char *attr_label = strtok(temp, " =,\n");
				char *attr_value = strtok(NULL, " =,\n");
				sscanf(attr_label, " %s", trainData[trainData_mount].attr[attr_index].label);
				sscanf(attr_value, " %Lf", &trainData[trainData_mount].attr[attr_index].value);
				attr_index += 1;
				while(1)
				{
					attr_label = strtok(NULL, " =,\n");
					attr_value = strtok(NULL, " =,\n");
					if(attr_value != NULL)
					{
						sscanf(attr_label, " %s", trainData[trainData_mount].attr[attr_index].label);
						sscanf(attr_value, " %Lf", &trainData[trainData_mount].attr[attr_index].value);
						attr_index += 1;
					}
					else
					{
						sscanf(attr_label, " %s", trainData[trainData_mount].label);
						break;
					}
				}
				trainData[trainData_mount].attr_mount = attr_index;
				trainData_mount++;
			}
			else
			{
				sscanf(temp, " Test data: K=%d", &k);
				break;
			}
		}

		/* Process Test Data */	
		while(1)
		{
			/* If this data is finally data */
			if(fgets(temp, BUFFER_LEN, stdin) == NULL)
			{
				breakFlag = 1;
				break;
			}
			
			/* If temp isn't next training data */
			if(strncmp(temp, "Training data", 13) != 0)
			{
				long double distance[TRANING_DATA_NUM] = { -1 };
				
				/* Initial */
				struct Data testData;
				memset(&testData, 0, sizeof(testData));
				strncpy(testData.label, "testData", 8);
				int attr_index = 0;

				/* Get Attr */
				char *attr_label = strtok(temp, " =,\n");
				char *attr_value = strtok(NULL, " =,\n");
				do{
					sscanf(attr_label, " %s", testData.attr[attr_index].label);
					sscanf(attr_value, " %Lf", &testData.attr[attr_index].value);
					attr_index += 1;
					if((attr_label = strtok(NULL, " =,\n")) != NULL)
						attr_value = strtok(NULL, " =,\n");
					else
						break;
				}while(1);
				testData.attr_mount = attr_index;

				/* Calculate Distance */
				for(int i = 0; i < trainData_mount; i++)
				{
					// Initial
					for(int test_i = 0; test_i < testData.attr_mount; test_i++)
					{
						testData.attr[test_i].match = 0;
					}
					for(int train_i = 0; train_i < trainData[i].attr_mount; train_i++)
					{
						trainData[i].attr[train_i].match = 0;
					}

					// For Attributes in testData
					// If find same label
					// => Mark trainData[1].match = 1
					// => Calculate distance value
					// Else
					// => Calculate distance with default
					for(int test_i = 0; test_i < testData.attr_mount; test_i++)
					{
						for(int train_i = 0; train_i < trainData[i].attr_mount; train_i++)
						{
							if(strcmp(testData.attr[test_i].label, trainData[i].attr[train_i].label) == 0)
							{
								// Mark match
								trainData[i].attr[train_i].match = 1;
								testData.attr[test_i].match = 1;

								// Calculate distance value
								distance[i] += (testData.attr[test_i].value - trainData[i].attr[train_i].value) * (testData.attr[test_i].value - trainData[i].attr[train_i].value);
								break;
							}
						}
						if(testData.attr[test_i].match == 0)
						{
							// Calculate distance value
							distance[i] += (testData.attr[test_i].value - _default) * (testData.attr[test_i].value - _default);
						}
					}

					// For Attributes in trainData
					// If match = 0
					// => Calculate distance with default
					for(int train_i = 0; train_i < trainData[i].attr_mount; train_i++)
					{
						if(trainData[i].attr[train_i].match == 0)
						{
							// Calculate distance value
							distance[i] += (_default - trainData[i].attr[train_i].value) * (_default - trainData[i].attr[train_i].value);
						}
					}
				}
				
				/* Select k Datas, and Print Out Answer */
				char rank[TRANING_DATA_NUM][LABEL_LEN] = {{ 0 }};
				int rank_value[TRANING_DATA_NUM] = { 0 };
				int rank_mount = 0;
				long long int lowest;
				int lowest_index;
				/* Get Lowest Distance for k times */
				for(int i = 0; i < k; i++)
				{
					/* Get Lowest Distance */
					int firstFlag = 1;
					for(int j = 0; j < trainData_mount; j++)
						if(firstFlag && distance[j] >= 0)
						{
							lowest = distance[j];
							lowest_index = j;
							firstFlag = 0;
						}
						else
							if(distance[j] < lowest && distance[j] >= 0)
							{
								lowest = distance[j];
								lowest_index = j;
							}

					/* Process the Lowest Distance Data */
					// Set lowest distance to -1
					// So that in next finding, it won't take part in searching
					distance[lowest_index] = -1;
					// Add to rank
					// Search if the attr.label has existed in rank array
					// If not, push it into rank
					int rank_index = 0;
					while(1)
					{
						if(rank[rank_index][0] == 0)
						{
							strncpy(rank[rank_index], trainData[lowest_index].label, (int)strlen(trainData[lowest_index].label));
							rank_value[rank_index] += 1;
							rank_mount += 1;
							break;
						}
						else if(strcmp(rank[rank_index], trainData[lowest_index].label) == 0)
						{
							rank_value[rank_index] += 1;
							break;
						}
						else
							rank_index++;
					}
				}

				// Search which value of label is most frequent
				int largest;
				int largest_index;
				for(int i = 0; i < rank_mount; i++)
				{
					if(i == 0)
					{
						largest = rank_value[i];
						largest_index = i;
					}
					else if(rank_value[i] > largest)
					{
						largest = rank_value[i];
						largest_index = i;
					}
				}
				printf("%s\n", rank[largest_index]);
			}
			else
			{
				break;
			}	
		}

		/* debuger */
		/*
		printf("Default %Lf\n", _default);
		printf("trainData_mount %d\n", trainData_mount);
		for(int i = 0; i < trainData_mount; i++)
		{
			printf("%d -----\n", i);
			printf("Label %s\n", trainData[i].label);
			printf("attr_mount %d\n", trainData[i].attr_mount);
			for(int j = 0; j < trainData[i].attr_mount; j++)
			{
				printf("%s : %Lf\n", trainData[i].attr[j].label, trainData[i].attr[j].value);
			}
		}
		printf("k %d\n", k);
		*/

		if(breakFlag)
			break;
	}while(1);
	return 0;
}
