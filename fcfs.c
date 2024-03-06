#include <stdio.h>
void findWaitingTime(int processes[],int n,int bt[],int wt[])
{
	wt[0]=0;
	for(int i=1;i<n;i++)
		wt[i]=bt[i-1]+wt[i-1];
}
void findTurnAroundTime(int processes[],int n,int bt[],int wt[],int tat[])
{
	for(int i=0;i<n;i++)
		tat[i]=bt[i]+wt[i];
}
void findAvgTime(int processes[],int n,int bt[])
{
	int wt[n],tat[n],total_wt=0,total_tat=0;
	findWaitingTime(processes,n,bt,wt);
	findTurnAroundTime(processes,n,bt,wt,tat);
	printf("Process\tBurstTime\tWaitingTime\tTurnAroundTime \n");
	for(int i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		printf("%d\t",(i+1));
		printf("%d\t",bt[i]);
		printf("%d\t",wt[i]);
		printf("%d\t",tat[i]);
	}
	float s=(float)total_wt/(float)n;
	float t=(float)total_tat/(float)n;
	printf("\nAverage Waiting Time=%f",s);
	printf("\n");
	printf("\nAverage Turn Around Time=%f",t);
}
int main()
{
	int processes[]={1,2,3};
	int n=sizeof processes/sizeof processes[0];
	int burst_time[]={0,5,8};
	findAvgTime(processes,n,burst_time);
	return 0;
}	


out
Process	BurstTime	WaitingTime	TurnAroundTime 
1	0	0	0	2	5	0	5	3	8	513	
Average Waiting Time=1.666667

Average Turn Around Time=6.000000
