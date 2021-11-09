#ifndef RR_H
#define RR_H
#include "./main.h"

#include <bits/stdc++.h>

using namespace std;

void rr_function(vector<Process> processes, int numberOfProcesses, int timeQuantum)
{

    cout << "\n\t*** Round Robin ***\n";

    int processesCompleted = 0, currentTime = 0;

    vector<bool> alreadyInQueue(numberOfProcesses, false);

    queue<Process> readyQueue;

    unordered_map<int, int> store;

    do
    {
        for (int i = 0; i < numberOfProcesses; i++)
        {
            if (!alreadyInQueue[processes[i].getId() - 1] && processes[i].getArrivalTime() == currentTime)
            {
                readyQueue.push(processes[i]);
                alreadyInQueue[processes[i].getId() - 1] = true;
            }
        }

        if (!readyQueue.empty())
        {
            Process currentProcess = readyQueue.front();
            readyQueue.pop();

            // Process is allocated CPU for the first time
            if (!currentProcess.isVisited())
            {
                // Response time is: Time at which the process was allocated CPU for the first time - Arrival Time
                currentProcess.setResponseTime(currentTime - currentProcess.getArrivalTime());
                currentProcess.setVisited();
                processes[currentProcess.getId() - 1].setResponseTime(currentTime - currentProcess.getArrivalTime());
                processes[currentProcess.getId() - 1].setVisited();
            }

            int usedQuanta = min(timeQuantum, currentProcess.getBurstTime());
            currentProcess.setBurstTime(currentProcess.getBurstTime() - usedQuanta);

            // Check if any process arrived during the execution of the current process
            for (int i = currentTime + 1; i <= currentTime + usedQuanta; ++i)
            {
                for (int j = 0; j < numberOfProcesses; ++j)
                {
                    if (!alreadyInQueue[processes[j].getId() - 1] && processes[j].getArrivalTime() == i)
                    {
                        readyQueue.push(processes[j]);
                        alreadyInQueue[processes[j].getId() - 1] = true;
                    }
                }
            }

            currentTime += usedQuanta;

            if (currentProcess.getBurstTime() == 0)
            {
                processesCompleted++;
                currentProcess.setCompletionTime(currentTime);
                store[currentProcess.getId()] = currentProcess.getCompletionTime();
            }
            else
            {
                readyQueue.push(currentProcess);
            }
        }
        else
        {
            currentTime++;
        }
    } while (processesCompleted != numberOfProcesses);

    float averageWaitingTime = 0, averageTurnAroundTime = 0, averageResponseTime = 0;

    for (int i = 0; i < numberOfProcesses; i++)
    {
        processes[i].setCompletionTime(store[processes[i].getId()]);
        processes[i].setTurnAroundTime(processes[i].getCompletionTime() - processes[i].getArrivalTime());
        processes[i].setWaitingTime(processes[i].getTurnAroundTime() - processes[i].getBurstTime());
        averageWaitingTime = averageWaitingTime + processes[i].getWaitingTime();
        averageTurnAroundTime = averageTurnAroundTime + processes[i].getTurnAroundTime();
        averageResponseTime = averageResponseTime + processes[i].getResponseTime();
    }

    averageWaitingTime = (float)averageWaitingTime / numberOfProcesses;
    averageTurnAroundTime = (float)averageTurnAroundTime / numberOfProcesses;
    averageResponseTime = (float)averageResponseTime / numberOfProcesses;

    int totalBurstTime = 0, numberOfContextSwitches = 0;
    for (int i = 0; i < numberOfProcesses; i++)
        totalBurstTime += processes[i].burstTime;
    numberOfContextSwitches = ceil(totalBurstTime / timeQuantum) - 1;

    display(processes, numberOfProcesses, averageWaitingTime, averageTurnAroundTime, averageResponseTime, numberOfContextSwitches);
}

#endif