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
		int a=p[i],m=i;
		for(int j=i;j<n;j++)
		{
			if(p[j] > a)
			{
				a=p[j];
				m=j;
			}
		 }
		swap(&p[i], &p[m]);
		swap(&b[i], &b[m]);
		swap(&index[i],&index[m]);
	}
	int t=0;
	printf("Order of process Execution is\n");
	for(int i=0;i<n;i++)
	{
		printf("P%d is executed from %d to %d\n",index[i],t,t+b[i]);
		t+=b[i];
	}
	printf("\n");
	printf("Process Id     Burst Time   Wait Time    TurnAround Time\n");
	int wait_time=0;
	for(int i=0;i<n;i++)
	{
		printf("P%d          %d          %d          %d\n",index[i],b[i],wait_time,wait_time + b[i]);
		wait_time += b[i];
	}
	return 0;
}


out
Enter Number of Processes: 3
Enter Burst Time and Priority Value for Process 1: 5
7
Enter Burst Time and Priority Value for Process 2: 6
4
Enter Burst Time and Priority Value for Process 3: 9
1
Order of process Execution is
P1 is executed from 0 to 5
P2 is executed from 5 to 11
P3 is executed from 11 to 20

Process Id     Burst Time   Wait Time    TurnAround Time
P1          5          0          5
P2          6          5          11
P3          9          11          20
