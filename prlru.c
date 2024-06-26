
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int pointer;
int faults ,hits;
void print(int frame_size,int frame[])
{
	int i;
	for(i=0;i<frame_size;i++)
	{
		if(frame[i]==-1)
			printf("- ");
		else
			printf("%d ",frame[i]);
	}
	printf("\n");
}

int predict(int reference_length, int references[], int page_no ,int frame_size,int frame[], int start)
{
	int pos = -1, farthest = start, i;
	for(i=0;i<frame_size;i++)
	{
		int j;
		for(j=start-1;j>=0;j--)
		{
			if(frame[i]==references[j])
			{
				if(j<farthest)
				{
					farthest=j;
					pos=i;
				}
				break;
			}
		}
		if(j==page_no)
			return i;
	}
	if(pos == -1)
		return 0;
	else
		return pos;
}

void add_reference(int frame_size,int frame[], int reference, int current_position,int reference_length, int references[])
{
	int i;
	bool allocated=false;
	for(i=0;i<frame_size;i++)
	{
		
		if(frame[i]==reference)
		{
			printf("  Hit for %d | ", reference);
			hits++;
			allocated = true;
			break;
		}
		else if(frame[i]==-1)
		{
			frame[i] = reference;
			printf("Fault for %d | ", reference);
			faults++;
			allocated = true;
			break;
		}
	}
	if(allocated==false)
	{
		int j = predict(reference_length,references,current_position,frame_size,frame,current_position+1);

		frame[j] = reference;
		printf("Fault for %d | ", reference);
		faults++;	
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
		add_reference(frame_size,frame,reference[i],i,number_of_references,reference);
	}
	printf("\nNumber of faults: %d \nNumber of hits: %d\n",faults,hits );
}

output
Enter frame size: 4
- - - - 
Enter the number of references: 14
7
Fault for 7 | 7 - - - 
0
Fault for 0 | 7 0 - - 
1
Fault for 1 | 7 0 1 - 
2
Fault for 2 | 7 0 1 2 
0
  Hit for 0 | 7 0 1 2 
3
Fault for 3 | 3 0 1 2 
0
  Hit for 0 | 3 0 1 2 
4
Fault for 4 | 3 0 4 2 
2
  Hit for 2 | 3 0 4 2 
3
  Hit for 3 | 3 0 4 2 
0
  Hit for 0 | 3 0 4 2 
3
  Hit for 3 | 3 0 4 2 
2
  Hit for 2 | 3 0 4 2 
3
  Hit for 3 | 3 0 4 2 

Number of faults: 6 
Number of hits: 8
