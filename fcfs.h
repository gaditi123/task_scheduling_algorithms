// "Include guard" prevents multiple inclusion: 
#ifndef FCFS_H
#define FCFS_H
#include <bits/stdc++.h>
#include "main.h"
using namespace std;

// bool compareByArrival(Process p, Process q)
// {
//     return p.getArrivalTime() < q.getArrivalTime();
// }

void fcfs_function(vector<Process> processes, int numberOfProcesses)
{
    cout<<"\n\t*** FCFS ***\n";

    float avgWaitTime=0, avgTurnAroundTime=0;

    sort(processes.begin(), processes.end(), compareByArrival); // Sorting the processes according to Arrival Time

	for(int i = 0, prevEnd =0 ;i < numberOfProcesses; i++){
		processes[i].setCompletionTime(max(prevEnd, processes[i].getArrivalTime()) + processes[i].getBurstTime());
		processes[i].setTurnAroundTime(processes[i].getCompletionTime() - processes[i].getArrivalTime());
		processes[i].setWaitingTime(processes[i].getTurnAroundTime() - processes[i].getBurstTime());
		prevEnd = processes[i].getCompletionTime();

		avgWaitTime+=processes[i].getWaitingTime();
		avgTurnAroundTime+=processes[i].getTurnAroundTime();
	}

	avgWaitTime = (float)avgWaitTime/numberOfProcesses;
	avgTurnAroundTime = (float)avgTurnAroundTime/numberOfProcesses;

    display(processes,numberOfProcesses,avgWaitTime,avgTurnAroundTime);
}
 
// End include guard: 
#endif 