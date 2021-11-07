// "Include guard" prevents multiple inclusion: 
#ifndef SJF_H
#define SJF_H
#include <bits/stdc++.h>
using namespace std;

void sjf_function(int numberOfProcesses,  vector<int>processID, vector<int> arrivalTime, vector<int>burstTime)
{
    vector<int> waitingTime(numberOfProcesses);
    vector<int> turnAroundTime(numberOfProcesses);
    float averageWaitingTime,averageTurnAroundTime;

   	float wavg=0,tavg=0,tsum=0,wsum=0;
 	int i,j,temp,sum=0,ta=0;
	 for(i=0;i<numberOfProcesses;i++)
	{
		for(j=0;j<numberOfProcesses;j++)
		{
		if(arrivalTime[i]<arrivalTime[j])
		{
		temp=processID[j];
		processID[j]=processID[i];
		processID[i]=temp;

		temp=arrivalTime[j];
		arrivalTime[j]=arrivalTime[i];
		arrivalTime[i]=temp;

		temp=burstTime[j];
		burstTime[j]=burstTime[i];
		burstTime[i]=temp;
		}
	}
}

int btime=0,min,k=1;
for(j=0;j<numberOfProcesses;j++)
{
    btime=btime+burstTime[j];
    min=burstTime[k];
    for(i=k;i<numberOfProcesses;i++){
        if (btime>=arrivalTime[i] && burstTime[i]<min)
        {
            temp=processID[k];
            processID[k]=processID[i];
            processID[i]=temp;
            temp=arrivalTime[k];
            arrivalTime[k]=arrivalTime[i];
            arrivalTime[i]=temp;
            temp=burstTime[k];
            burstTime[k]=burstTime[i];
            burstTime[i]=temp;
        }
    }
    k++;
}
waitingTime[0]=0;
for(i=1;i<numberOfProcesses;i++)
{
    sum=sum+burstTime[i-1];
    waitingTime[i]=sum-arrivalTime[i];
    wsum=wsum+waitingTime[i];
}

averageWaitingTime=(wsum/numberOfProcesses);

for(i=0;i<numberOfProcesses;i++)
{
    ta=ta+burstTime[i];
    turnAroundTime[i]=ta-arrivalTime[i];
    tsum=tsum+turnAroundTime[i];
}

averageTurnAroundTime=(tsum/numberOfProcesses);

printf("\nShortest Job First\n");

printf("SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n");
    for(i=0;i<numberOfProcesses;i++){
    printf("%3d\t%3d\t%3d\t%3d\t%4d\n",i+1,arrivalTime[i],burstTime[i],waitingTime[i],turnAroundTime[i]);
    }


printf("Average Waiting Time: %f\nAverage Turn Around Time:%f\n",averageWaitingTime,averageTurnAroundTime);
}
 
// End include guard: 
#endif 