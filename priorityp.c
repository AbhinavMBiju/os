#include <stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int n;
	printf("Enter Number of Processes: ");
	scanf("%d",&n);
	int b[n],p[n],index[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
		scanf("%d %d",&b[i],&p[i]);
		index[i]=i+1;
	}
	for(int i=0;i<n;i++)
	{
		int temp=p[i],m=i;
		for(int j=i;j<n;j++)
		{
			if(p[j] > temp)
			{
				temp=p[j];
				m=j;
			}
		 }
		swap(&p[i], &p[m]);
		swap(&b[i], &b[m]);
		swap(&index[i],&index[m]);
	}
	int current_time=0;
	int remaining_burst[n];
	for(int i=0;i<n;i++)
		remaining_burst[i]=b[i];
	printf("Order of process Execution is\n");
	while(1)
	{
		int highest_priority_process_index=-1;
		for(int i=0;i<n;i++)
		{
			if(remaining_burst[i]>0&&current_time>=p[i])
			{
				if(highest_priority_process_index==-1||p[i]>p[highest_priority_process_index])
				{
					highest_priority_process_index=1;
				}
			}
		}
		if(highest_priority_process_index==-1)
			break;
		printf("P%d is executed from %d to",index[highest_priority_process_index],current_time);
		current_time++;
		remaining_burst[highest_priority_process_index]--;
		printf("%d\n",current_time);
	}
	printf("\n");
	printf("Process id\tBurst time\twait time\n");
	int total_wait_time=0;
	for(int i=0;i<n;i++)
	{
		int wait_time=p[i]-b[i];
		printf("P%d\t\t%d\t\t%d\n",index[i],b[i],wait_time);
		total_wait_time+=wait_time;
	}
	float avg_wait_time=(float)total_wait_time/n;
	printf("Average waiting time is %f\n",avg_wait_time);
	int total_turn_around=0;
	for(int i=0;i<n;i++)
		total_turn_around+=b[i];
	float avg_turn_around=(float)total_turn_around/n;
	printf("Average Turn around time is %f\n",avg_turn_around);
	return 0;
}		
		
