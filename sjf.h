#ifndef SJF_H
#define SJF_H
#include <bits/stdc++.h>
#include "main.h"
using namespace std;

void sjf_function(vector<Process> processes, int numberOfProcesses)
{
   	cout<<"\n\t*** SJF ***\n";

	int executedCount = 0;
    vector<bool> processActive(numberOfProcesses, false);
	vector <Process> processInQueue;
	map<int, int> id_complete;
	for(int time = 0; executedCount<numberOfProcesses;) {
        
		for(int i=0; i<numberOfProcesses; i++) {
			if(!processActive[processes[i].getId()-1] && processes[i].getArrivalTime()<=time){ 		//To check if process is executed before and also whether it has arrived or not
				processInQueue.push_back(processes[i]);				// Pushed to Process Arrived Vector
				processActive[processes[i].getId()-1] = true;
			}
		}

		if(processInQueue.size()!=0) {
			vector<Process>::iterator minPosition = min_element(processInQueue.begin(),
			processInQueue.end(), compareByBurst);
			Process processMinBurstTime = *minPosition;
			time += processMinBurstTime.getBurstTime();
			id_complete[processMinBurstTime.getId()] = time;
			executedCount++;
			processInQueue.erase(minPosition);

		} 
        
        else {
			time++;
		}
	}

	float avgWaitTime=0, avgTurnAroundTime=0;

	for (int i = 0; i < numberOfProcesses; i++)
	{
		processes[i].setCompletionTime(id_complete[processes[i].getId()]);
		processes[i].setTurnAroundTime(processes[i].getCompletionTime() - processes[i].getArrivalTime());
		processes[i].setWaitingTime(processes[i].getTurnAroundTime() - processes[i].getBurstTime());
        processes[i].setResponseTime(processes[i].getCompletionTime() - processes[i].getBurstTime() - processes[i].getArrivalTime());
		avgWaitTime+=processes[i].getWaitingTime();
		avgTurnAroundTime+=processes[i].getTurnAroundTime();
	}

    avgWaitTime = (float)avgWaitTime/numberOfProcesses;
	avgTurnAroundTime = (float)avgTurnAroundTime/numberOfProcesses;

    display(processes,numberOfProcesses,avgWaitTime,avgTurnAroundTime);
}
 
#endif 