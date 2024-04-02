#include <stdio.h>

void implimentBestFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
    int allocation[proccesses];
    int occupied[blocks];
    for(int i = 0; i < proccesses; i++){
        allocation[i] = -1;
    }
    
    for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
    for (int i = 0; i < proccesses; i++)
    {
        
        int indexPlaced = -1;
        for (int j = 0; j < blocks; j++) { 
            if (blockSize[j] >= processSize[i] && !occupied[j])
            {
                if (indexPlaced == -1)
                    indexPlaced = j;
                else if (blockSize[j] < blockSize[indexPlaced])
                    indexPlaced = j;
            }
        }
	if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1;
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < proccesses; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
int main()
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
	implimentBestFit(blockSize,m,ProcessSize,n);
}

