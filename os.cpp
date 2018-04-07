#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char process[10][5],temp[5];
	int a,b,process_time[10],wt[10],totwt=0,priority[10],temp1,n;
	float avgwt;
	printf("enter the number of processes:");
	scanf("%d",&n);
	for(a=0;a<n;a++)
	{
		printf("enter the process %d name:",a+1);
  		scanf("%s",&process[a]);
		printf("enter the process time:");
		scanf("%d",&process_time[a]);
		printf("enter the priority:");
		scanf("%d",&priority[a]);
	}
  	for(a=0;a<n-1;a++)
	{
		for(b=a+1;b<n;b++)
		{
			if(priority[a]>priority[b])
			{
				temp1=priority[a];
				priority[a]=priority[b];
				priority[b]=temp1;
				temp1=process_time[a];
				process_time[a]=process_time[b];
				process_time[b]=temp1;
				strcpy(temp,process[a]);
				strcpy(process[a],process[b]);
				strcpy(process[b],temp);
			}
		}
	}
	wt[0]=0;
	for(a=1;a<n;a++)
	{
		wt[a]=wt[a-1]+wt[a-1];
		totwt=totwt+wt[a];
	}
	avgwt=(float)totwt/n;
	printf("p_name\t p_time\t priority\t w_time\n");
	for(a=0;a<n;a++)
	{
	   printf(" %s\t %d\t %d\t %d\n" ,process[a],process_time[a],priority[a],wt[a]);
	}
	printf("total waiting time=%d\n avg waiting time=%f",totwt,avgwt);
	
	int ts,pid[10],need[10],wt1[10],turn_around_time[10],a1,b1,n2,n1;
	int bt[10],flag[10],ttat=0,twt=0;
	float awt,atat;
	printf("\nEnter the number of Processors \n");
	scanf("%d",&n);
	n1=n;
	printf("\n Enter the Timeslice \n");
 	scanf("%d",&ts);
 	for(a=1;a<=n;a++)
	{
   		printf("\n Enter the process ID %d",a);
		scanf("%d",&pid[a]);
   		printf("\n Enter the Burst Time for the process");
   		scanf("%d",&bt[a]);
   		need[a]=bt[a];
 	}
 	for(a=1;a<=n;a++)
	{
		flag[a]=1;
  		wt[a]=0;
 	}
 	while(n!=0)
	{
   		for(a=1;a<=n;a++)
   		{
     		if(need[a]>=ts)
     		{
       			for(b=1;b<=n;b++)
				{
	  				if((a!=b)&&(flag[a]==1)&&(need[b]!=0))
	  				wt[b]+=ts;
       			}
      			need[a]-=ts;
      			if(need[a]==0)
      			{
	 				flag[a]=0;
	 				n--;
       			}
     		}
     		else
    		{
       			for(b=1;b<=n;b++)
       			{
	  				if((a!=b)&&(flag[a]==1)&&(need[b]!=0))
	  				wt[b]+=need[a];
       			}
       			need[a]=0;
       			n--;
       			flag[a]=0;
  			}
 		}
	}
	for(a=1;a<=n1;a++)
	{
  		turn_around_time[a]=wt[a]+bt[a];
  		twt=twt+wt[a];
  		ttat=ttat+turn_around_time[a];
	}
	awt=(float)twt/n1;
	atat=(float)ttat/n1;
	printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
	for(a=1;a<=n1;a++)
	{ 
 		printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", ts,pid[a],bt[a],wt[a],turn_around_time[a]);
	}
	printf("\n The average Waiting Time=4.2f",awt);
	printf("\n The average Turn around Time=4.2f",atat);
}

