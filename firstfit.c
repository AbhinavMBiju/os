#include <stdio.h>
void implimentFirstFit(int blockSize[],int blocks,int processSize[],int processes)
{
	int allocate[processes];
	int occupied[blocks];
	for(int i=0;i<processes;i++)
		allocate[i]=-1;
	for(int i=0;i<blocks;i++)
		occupied[i]=0;
	for(int i=0;i<processes;i++)
	{
		for(int j=0;j<blocks;j++)
		{
			if(!occupied[j]&&blockSize[j]>=processSize[i])
			{
				allocate[i]=j;
				occupied[j]=1;
				break;
			}
		}
	}
	printf("\nProcess No.\tProcess Size\tBlock No.\n");
	for(int i=0;i<processes;i++)
	{
		printf("%d\t\t\t%d\t\t\t",i+1,processSize[i]);
		if(allocate[i]!=-1)
			printf("%d\n",allocate[i]+1);
		else
			printf("Not Allocated\n");
	}
}
void main()
{
	int m,n,blockSize[10],ProcessSize[10];
	printf("Enter the number of blocks:");
	scanf("%d",&m);
	printf("Enter the block sizes of each:");
	for(int i=0;i<m;i++)
		scanf("%d",&blockSize[i]);
	printf("Enter the no. of processes:");
	scanf("%d",&n);
	printf("Enter the Process size of each:");
	for(int i=0;i<n;i++)
		scanf("%d",&ProcessSize[i]);
	implimentFirstFit(blockSize,m,ProcessSize,n);
}

