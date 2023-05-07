#include<stdio.h>
struct fcfs
{
	int pid;
	int btime;
	int wtime;
	int ttime;
}p[10];
int main()
{
	int i,n;
	int twtime=0,tttime=0;
	printf("enter the number of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i].pid=1;
		printf("enter the burst time=");
		scanf("%d",&p[i].btime);																																		
	}
	p[0].wtime=0;	
	p[0].ttime=p[0].btime;
	for(i=0;i<n;i++)
	{
		p[i].wtime=p[i-1].btime+p[i-1].wtime;
		p[i].ttime=p[i].btime+p[i].wtime;
		twtime+=p[i].wtime;
		tttime+=p[i].ttime;
	}
	printf("total waiting time=%d",twtime);
	printf("average waiting time=%d",twtime/n);
	printf("total turn around time=%d",tttime);
	printf("average turn around time=%d",tttime/n);
	return 0;
}

