#ifndef FCFS_H
#define FCFS_H
#include "main.h"
#include <bits/stdc++.h>

using namespace std;

void fcfs_function(vector<Process> processes, int numberOfProcesses)
{
	cout << "\n\t*** First Come First Served ***\n";

	float averageWaitingTime = 0, averageTurnAroundTime = 0;

	// Sorting the processes according to Arrival Time
	sort(processes.begin(), processes.end(), compareByArrival);

	int currentTime = processes[0].getArrivalTime(), previousProcessEndingTime = 0;

	for (int i = 0; i < numberOfProcesses; i++)
	{
		processes[i].setCompletionTime(max(previousProcessEndingTime, processes[i].getArrivalTime()) + processes[i].getBurstTime());
		processes[i].setTurnAroundTime(processes[i].getCompletionTime() - processes[i].getArrivalTime());
		processes[i].setWaitingTime(processes[i].getTurnAroundTime() - processes[i].getBurstTime());
		processes[i].setResponseTime(currentTime - processes[i].getArrivalTime());
		currentTime = currentTime + processes[i].getBurstTime();
		previousProcessEndingTime = processes[i].getCompletionTime();
		averageWaitingTime += processes[i].getWaitingTime();
		averageTurnAroundTime += processes[i].getTurnAroundTime();
	}

	averageWaitingTime = (float)averageWaitingTime / numberOfProcesses;
	averageTurnAroundTime = (float)averageTurnAroundTime / numberOfProcesses;

	display(processes, numberOfProcesses, averageWaitingTime, averageTurnAroundTime);
}

#endif