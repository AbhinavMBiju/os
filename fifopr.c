#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
int pointer;
int faults ,hits;
void print(int frame_size,int frame[])
{
	int i;
	//printf("Printing the Frames: ");
	for(i=0;i<frame_size;i++)
	{
		if(frame[i]==-1)
			printf("- ");
		else
			printf("%d ",frame[i]);
	}
	printf("\n");
}
void add_reference(int frame_size,int frame[], int reference)
{
	int i;
	bool alloted = false;
	for(i=0;i<frame_size;i++)
	{
		if(frame[i]==reference)
		{
			alloted = true;
			printf("  Hit for %d | ", reference);
			hits++;
			break;
		}
		else if(frame[i]==-1)
		{
			alloted = true;
			frame[i] = reference;
			printf("Fault for %d | ", reference);
			faults++;
			break;
		}
	}
	if(alloted == false)
	{
		faults++;
		printf("Fault for %d | ", reference);
		frame[pointer] = reference;
		pointer = (pointer+1)%frame_size;
	}
	print(frame_size, frame);
}

int main()
{
	int frame_size,i,number_of_references;
	printf("Enter frame size: ");
	scanf("%d",&frame_size);
	int frame[frame_size];
	for(i=0;i<frame_size;i++)
	{
		frame[i] = -1;
	}

	print(frame_size,frame);
	
	printf("Enter the number of references: ");
	scanf("%d",&number_of_references);
	int reference[number_of_references];
	
	for(i=0;i<number_of_references;i++)
	{
		scanf("%d",&reference[i]);
		add_reference(frame_size,frame,reference[i]);
	}
	printf("\nNumber of faults: %d \nNumber of hits: %d\n",faults,hits );
}

output
Enter frame size: 3
- - - 
Enter the number of references: 7
1
Fault for 1 | 1 - - 
3
Fault for 3 | 1 3 - 
0
Fault for 0 | 1 3 0 
3
  Hit for 3 | 1 3 0 
5
Fault for 5 | 5 3 0 
6
Fault for 6 | 5 6 0 
3
Fault for 3 | 5 6 3 

Number of faults: 6 
Number of hits: 1
