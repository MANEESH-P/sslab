#include<stdio.h>
void main()
{	char c;
	do
	{
	int  bt[20],wt[20],tat[20],pr[20], i, j,p[20],k,ch,temp,pos;
	float avwt=0,avtat=0 ,n;
	
	
	printf("select the scheduling method \n 1.FCFS\n 2.SJFS\n 3.PRIORITY \n 4.ROUND_ROBIN\n");
	scanf("%d" ,&ch);
	switch(ch)
	{
		case 1:
		{
			printf("enter the  number of processes(less than 20) :");
			scanf("%f", &n);
			for(i=0 ;i<n;i++)
			{
				printf("\nP[%d]\n",i);
				printf("Burst Time:");
				scanf("%d" ,&bt[i]);
			}
		
			wt[0]=0;
			for(i=0 ;i<n;i++)
			{
				wt[i]=0;
				for(j=0 ;j<i;j++)
					wt[i]+=bt[j];
				avwt+=wt[i];
			
			}
			avwt=(avwt/n);
			printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
		    	for(k=0;k<n;k++)
		    		{
					tat[k]=bt[k]+wt[k]; 	
					avtat+=tat[k];
					printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",k,bt[k],wt[k],tat[k]);
				}
			
			avtat=(avtat/n);
			printf("\naverage waiting time :%f\n", avwt);
			printf("average turnaround time :%f\n", avtat);
		}break;
		case 2:
		{
			printf("enter the  number of processes(less than 20) :");
			scanf("%f", &n);
			for(i=0 ;i<n;i++)
			{
				printf("\nP[%d]\n",i);
				printf("Burst Time:");
				scanf("%d" ,&bt[i]);
				p[i]=i;
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
			for(i=0 ;i<n;i++)
			{
				wt[i]=0;
				for(j=0 ;j<i;j++)
					wt[i]+=bt[j];
				avwt+=wt[i];
			
			}
			avwt=(avwt/n);
			printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
			for(k=0;k<n;k++)
		    		{
					tat[k]=bt[k]+wt[k]; 	
					avtat+=tat[k];
					printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",k,bt[k],wt[k],tat[k]);
				}
			
			avtat=(avtat/n);
			printf("\naverage waiting time :%f\n", avwt);
			printf("average turnaround time :%f\n", avtat);
		}break;
		case 3:
		{
		printf("enter the  number of processes(less than 20) :");
			scanf("%f", &n);
			for(i=0 ;i<n;i++)
			{
				printf("\nP[%d]\n",i);
				printf("Burst Time:");
				scanf("%d" ,&bt[i]);
				printf("Priority :");
				scanf("%d" ,&pr[i]);
				p[i]=i;
			}
			for(i=0;i<n;i++)
			{
				pos=i;
				for(j=i+1;j<n;j++)
				{
					if(pr[j]<pr[pos])
						pos=j;
				}
				temp=bt[i];
				bt[i]=bt[pos];
				bt[pos]=temp;
				
				temp=pr[i];
				pr[i]=pr[pos];
				pr[pos]=temp;
				
				temp=p[i];
				p[i]=p[pos];
				p[pos]=temp;
			}
			wt[0]=0;
			for(i=0 ;i<n;i++)
			{
				wt[i]=0;
				for(j=0 ;j<i;j++)
					wt[i]+=bt[j];
				avwt+=wt[i];
			
			}
			avwt=(avwt/n);
			printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
			for(k=0;k<n;k++)
		    		{
					tat[k]=bt[k]+wt[k]; 	
					avtat+=tat[k];
					printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",k,bt[k],wt[k],tat[k]);
				}
			
			avtat=(avtat/n);
			printf("\naverage waiting time :%f\n", avwt);
			printf("average turnaround time :%f\n", avtat);
		}break;
		case 4:
		{
			int count,j,n,time,remain,flag=0,time_quantum; 
			int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
			  
			  printf("Enter Total Process:\t "); 
			  scanf("%d",&n); 
			  remain=n; 
			  for(count=0;count<n;count++) 
			  { 
			    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
			    scanf("%d",&at[count]); 
			    scanf("%d",&bt[count]); 
			    rt[count]=bt[count]; 
			  } 
			  printf("Enter Time Quantum:\t"); 
			  scanf("%d",&time_quantum); 
			  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
			  for(time=0,count=0;remain!=0;) 
			  { 
			    if(rt[count]<=time_quantum && rt[count]>0) 
			    { 
			      time+=rt[count]; 
			      rt[count]=0; 
			      flag=1; 
			    } 
			    else if(rt[count]>0) 
			    { 
			      rt[count]-=time_quantum; 
			      time+=time_quantum; 
			    } 
			    if(rt[count]==0 && flag==1) 
			    { 
			      remain--; 
			      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
			      wait_time+=time-at[count]-bt[count]; 
			      turnaround_time+=time-at[count]; 
			      flag=0; 
			    } 
			    if(count==n-1) 
			      count=0; 
			    else if(at[count+1]<=time) 
			      count++; 
			    else 
			      count=0; 
			  } 
			  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
			  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
			  
			
		}break;
		default:{printf("enter valid choice\n");}break;
 			
				
		
 	}
 	printf("do you want to continue(y/n)");
 	scanf("%s" ,&c);
 	
 }while(c =='y');
 }
