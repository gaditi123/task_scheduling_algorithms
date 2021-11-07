#ifndef SJRF_H
#define SJRF_H
#include "main.h"
#include <bits/stdc++.h>

using namespace std;

void sjrf_function(vector<Process> processes, int numberOfProcesses)
{
	cout << "\n\t*** Shortest Job Remaining First ***\n";

	int time = 0, processesCompleted = 0;

	float averageTurnAroundTime = 0, averageWaitingTime = 0, averageResponseTime = 0;

	vector<Process> processInQueue;
	vector<bool> alreadyInQueue(numberOfProcesses, false);

	unordered_map<int, int> store;

	while (processesCompleted != numberOfProcesses)
	{
		for (int i = 0; i < numberOfProcesses; i++)
		{
			if ((processes[i].getArrivalTime() <= time) && (alreadyInQueue[i] == false))
			{
				processInQueue.push_back(processes[i]);
				alreadyInQueue[i] = true;
			}
		}

		if (processInQueue.size() != 0)
		{
			vector<Process>::iterator minPosition = min_element(processInQueue.begin(),
																processInQueue.end(), compareByBurst);
			(*minPosition).setBurstTime((*minPosition).getBurstTime() - 1);
			time++;
			if ((*minPosition).getBurstTime() == 0)
			{
				store[(*minPosition).getId()] = time;
				processesCompleted++;
				processInQueue.erase(minPosition);
			}
		}
		else
		{
			time++;
		}
	}

	for (int i = 0; i < numberOfProcesses; i++)
	{
		processes[i].setCompletionTime(store[processes[i].getId()]);
		processes[i].setTurnAroundTime(processes[i].getCompletionTime() - processes[i].getArrivalTime());
		processes[i].setWaitingTime(processes[i].getTurnAroundTime() - processes[i].getBurstTime());
		processes[i].setResponseTime(processes[i].getCompletionTime() - processes[i].getBurstTime() - processes[i].getArrivalTime());
		averageWaitingTime += processes[i].getWaitingTime();
		averageTurnAroundTime += processes[i].getTurnAroundTime();
		averageResponseTime = averageResponseTime + processes[i].getResponseTime();
	}
	
	averageWaitingTime = (float)averageWaitingTime / numberOfProcesses;
	averageTurnAroundTime = (float)averageTurnAroundTime / numberOfProcesses;
    averageResponseTime = (float)averageResponseTime / numberOfProcesses;
	int numberOfContextSwitches = processes.size() - 1;

	display(processes, numberOfProcesses, averageWaitingTime, averageTurnAroundTime, averageResponseTime,numberOfContextSwitches);
}
#endif