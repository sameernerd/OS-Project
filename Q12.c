#include<stdio.h>
#define N 10000
int check(int,int,int)
int gang[N];
void main(){
	int n;
	scanf("%d",&n);
	int process_id[n];
    int start_time[n];
    int burst_time[n];
    int time_left[n];
    int completion_time[n];
	int i=0;
	for(i=0;i<n;i++)
		scanf("%d",process_id[i]);
	for(i=0;i<n;i++)
		scanf("%d",start_time[i]);
	for(i=0;i<n;i++){
	    scanf("%d",burst_time[i]);
		time_left[i]=burst_time[i];	
	}
	int index;
	int cnt=0;
	do{
		index=check(n,time_left,process_id);
		gang[cnt]=process_id[index];
		time_left[index]--;
		if(time_left[index]==0){
		   completion_time[index]=start_time[index]-completion_time[index];
		}
		cnt++;
	}while(index!=-1);
	//Calculation of turn around time
	long turn_around_time=0;
	double avgtat=0;
	for(int i=0;i<n;i++)
		turn_around_time+=completion_time[i];
	avgtat=((double)turn_around_time)/n;
	printf("%d",avgtat);
}

int check(int n,int time_left[],int process_id[]){
	int max_time=0,index=0,p=INT_MAX;
	int i;
	for(i=0;i<n;i++){
		if(time_left[i]>max_time){
			max_time=time_left[i];
			p=process_id[i];
		}
		else if(time_left[i]==max_time&&process_id[i]<p){
			max_time=time_left[i];
			p=process_id[i];
		}
	}
	if(max_time==0)return -1;
	else return index;
}

/*
I have to implement Longest Remaining Time First
So basic idea will be check at ever second which process
has the longest remaining time first.
Arrival Time:       Time at which the process arrives in the ready queue.
Completion Time:    Time at which process completes its execution.
Burst Time:         Time required by a process for CPU execution.
Turn Around Time:   Time Difference between completion time and arrival time.          
     Turn Around Time = Completion Time - Arrival Time

Waiting Time(W.T): Time Difference between turn around time and burst time.
     Waiting Time = Turn Around Time - Burst Time
*/
