#include <stdio.h>
int main()
{
	int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
	float avg_wt,avg_tat;
	printf("Enter no. of processes:");
	scanf("%d",&n);
	printf("Enter burst time:\n");
	for(i=0;i<n;i++)
	{
		printf("P%d:",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(bt[j]<bt[pos])
				pos=j;
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
			wt[i]+=bt[j];
	}
	total+=wt[i];
	avg_wt=(float)total/n;
	total=0;
	printf("\nProcess\tBurst time\tWaiting time\tTurn Around time");
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		total+=tat[i];
		printf("\nP%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
	avg_tat=(float)total/n;
	printf("\n\nThe average waiting time=%f",avg_wt);
	printf("\nThe average turn around time=%f\n",avg_tat);
}	


out
Enter no. of processes:2
Enter burst time:
P1:3
P2:5

Process	Burst time	Waiting time	Turn Around time
P1		3		0		3
P2		5		3		8

The average waiting time=0.000000
The average turn around time=5.500000
