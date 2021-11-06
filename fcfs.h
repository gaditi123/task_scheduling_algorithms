// "Include guard" prevents multiple inclusion: 
#ifndef FCFS_H
#define FCFS_H
#include <bits/stdc++.h>
using namespace std;

// List prototypes of all functions in B.c here: 
void fcfs_function(int numberOfProcesses,  vector<int> arrivalTime, vector<int>burstTime)
{
    vector<int> processID(numberOfProcesses);
    vector<int> waitingTime(numberOfProcesses);
    vector<int> turnAroundTime(numberOfProcesses);
    float averageWaitingTime,averageTurnAroundTime;

    waitingTime[0]=0;
    averageTurnAroundTime=turnAroundTime[0]=burstTime[0];
    int btt=burstTime[0];
    int i;
    for(i=1;i<numberOfProcesses;i++){
      waitingTime[i]=btt-arrivalTime[i];
      btt+=burstTime[i];
      averageWaitingTime+=waitingTime[i];
      turnAroundTime[i]= waitingTime[i]+burstTime[i];
      averageTurnAroundTime+=turnAroundTime[i];
    }
    averageTurnAroundTime/=numberOfProcesses;
    averageWaitingTime/=numberOfProcesses;
    printf("SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n");
    for(i=0;i<numberOfProcesses;i++)
    {
    printf("%3d\t%3d\t%3d\t%3d\t%4d\n",i+1,arrivalTime[i],burstTime[i],waitingTime[i],turnAroundTime[i]);
    }

    printf("Average Waiting Time: %f\nAverage Turn Around Time:%f",averageWaitingTime,averageTurnAroundTime);
}
 
// End include guard: 
#endif 