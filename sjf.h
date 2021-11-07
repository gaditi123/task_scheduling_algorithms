#ifndef SJF_H
#define SJF_H
#include "main.h"
#include <bits/stdc++.h>

using namespace std;

void sjf_function(vector<Process> processes, int numberOfProcesses)
{
	cout << "\n\t*** Shortest Job First ***\n";

	int executedCount = 0;

	float averageWaitingTime = 0, averageTurnAroundTime = 0, averageResponseTime = 0;

	vector<bool> processActive(numberOfProcesses, false);
	vector<Process> processInQueue;

	unordered_map<int, int> store;

	for (int time = 0; executedCount < numberOfProcesses;)
	{

		for (int i = 0; i < numberOfProcesses; i++)
		{
			if (!processActive[processes[i].getId() - 1] && processes[i].getArrivalTime() <= time)
			{											//To check if process is executed before and also whether it has arrived or not
				processInQueue.push_back(processes[i]); // Pushed to Process Arrived Vector
				processActive[processes[i].getId() - 1] = true;
			}
		}

		if (processInQueue.size() != 0)
		{
			vector<Process>::iterator minPosition = min_element(processInQueue.begin(),
																processInQueue.end(), compareByBurst);
			Process processMinBurstTime = *minPosition;
			time += processMinBurstTime.getBurstTime();
			store[processMinBurstTime.getId()] = time;
			executedCount++;
			processInQueue.erase(minPosition);
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

    display(processes, numberOfProcesses, averageWaitingTime, averageTurnAroundTime, averageResponseTime);
}

#endif