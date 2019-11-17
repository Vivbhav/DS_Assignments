#include <stdio.h>
#define MAX 16
int current[MAX][MAX], maximum_claim[MAX][MAX], available[MAX];
int allocation[MAX], need[MAX];
int maxres[MAX], running[MAX], safe = 0;
int counter = 0, i, j, exec, resources, processes, k = 1;

int main()
{
	for(i = 0; i < MAX; i++)
		allocation[i] = 0;

	printf("Enter number of processes: \n");
	scanf("%d", &processes);

	for (i = 0; i < processes; i++)
	{
		running[i] = 1;
		counter++;
	}

	printf("Enter number of resources: \n");
	scanf("%d", &resources);

	printf("Enter instances Vector : \n");
	for (i = 0; i < resources; i++)
	{
		scanf("%d", &maxres[i]);
	}

	printf("\nEnter Allocated Resource Table:\n");
	for (i = 0; i < processes; i++)
	{
		for(j = 0; j < resources; j++)
		{
			scanf("%d", &current[i][j]);
		}
	}

	printf("\nEnter Maximum Claim Table:\n");
	for (i = 0; i < processes; i++)
	{
		for(j = 0; j < resources; j++)
		{
			scanf("%d", &maximum_claim[i][j]);
		}
	}
	printf("\nEnter the process that is requesting for resources:\n");
	int processNo;
	scanf("%d", &processNo);
	printf("\nEnter the need of that process\n");
	for (i = 0; i < resources; i++) {
		scanf("%d", &need[i]);
	}
	printf("\nThe Claim Vector is: ");
	for (i = 0; i < resources; i++)
	{
		printf("\t%d", maxres[i]);
	}

	printf("\nThe Allocated Resource Table:\n");
	for (i = 0; i < processes; i++)
	{
		for (j = 0; j < resources; j++)
		{
			printf("\t%d", current[i][j]);
			if (i == processNo) {
				current[i][j] += need[j];
			}
		}
		printf("\n");
	}

	printf("\nThe Maximum Claim Table:\n");
	for (i = 0; i < processes; i++)
	{
		for (j = 0; j < resources; j++)
		{
			printf("\t%d", maximum_claim[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < processes; i++)
	{
		for (j = 0; j < resources; j++)
		{
			allocation[j] += current[i][j];
		}
	}

	printf("\nAllocated resources:");
	for (i = 0; i < resources; i++)
	{
		printf("\t%d", allocation[i]);
	}

	for (i = 0; i < resources; i++)
	{
		available[i] = maxres[i] - allocation[i];
		available[i] -= need[i];
	}

	printf("\nAvailable resources:");
	for (i = 0; i < resources; i++)
	{
		printf("\t%d", available[i]);
	}
	printf("\n");

	while (counter != 0)
	{
		safe = 0;
		for (i = 0; i < processes; i++)
		{
			if (running[i])
			{
				exec = 1;
				for (j = 0; j < resources; j++)
				{
					if (maximum_claim[i][j] - current[i][j] > available[j])
					{
						exec = 0;
						break;
					}
				}
				if (exec)
				{
					printf("\nProcess%d is executing\n", i + 1);
					running[i] = 0;
					counter--;
					safe = 1;

					for (j = 0; j < resources; j++)
					{
						available[j] += current[i][j];
					}
					break;
				}
			}
		}
		if (!safe)
		{
			printf("\nThis need will result in deadlock state.\n");
			break;
		}
		else
		{
			printf("\nThis need will not result in deadlock state");
			printf("\nAvailable vector:");

			for (i = 0; i < resources; i++)
			{
				printf("\t%d", available[i]);
			}

			printf("\n");
		}
	}
	return 0;
}
