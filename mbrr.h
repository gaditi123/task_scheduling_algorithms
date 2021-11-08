#ifndef MBRR_H
#define MBRR_H
#include "main.h"
#include <bits/stdc++.h>

using namespace std;

int modulusTimeQuantum(int numberOfProcesses, vector<Process> processes){
    int timeQuantum = 0;
    float avgBurst = 0, medianBurst = 0;
    for (int i = 0; i < numberOfProcesses;i++)
    {
        avgBurst += processes[i].burstTime;
    }
    avgBurst = (float)avgBurst / numberOfProcesses;
    vector<Process> temp = processes;
    sort(temp.begin(), temp.end(), compareByBurst);
    if(numberOfProcesses%2!=0){
        int median = ceil(numberOfProcesses / 2);
        medianBurst = processes[median].burstTime;
    }
    else{
        int median = numberOfProcesses / 2;
        medianBurst = (float)(processes[median].burstTime + processes[median + 1].burstTime) / 2;
    }

    timeQuantum = sqrt((pow(avgBurst, 2) + pow(medianBurst, 2)) / 2);

    return timeQuantum;
}

void mbrr_function(vector<Process> processes, int numberOfProcesses)
{

    cout << "\n\t*** Modulus Based Round Robin ***\n";

    int processesCompleted = 0, currentTime = 0, cycle = 0, processesInReadyQueue, timeQuantum, numberOfContextSwitches =0;

    vector<bool> alreadyInQueue(numberOfProcesses, false);
    vector<Process> tempProcesses = processes;
    sort(tempProcesses.begin(), tempProcesses.end(), compareByBurst);
    currentTime = tempProcesses[0].getArrivalTime();

    queue<Process> readyQueue;

    unordered_map<int, int> store;

    for (int i = 0; i < numberOfProcesses; i++)
    {
        if (!alreadyInQueue[processes[i].getId() - 1] && processes[i].getArrivalTime() == currentTime)
        {
            readyQueue.push(processes[i]);
            alreadyInQueue[processes[i].getId() - 1] = true;
        }
    }

    do
    {
        if (!readyQueue.empty())
        {

            if (!(cycle > 0))
            {
                tempProcesses.clear();
                while (!readyQueue.empty())
                {
                    tempProcesses.push_back(readyQueue.front());
                    readyQueue.pop();
                }
                sort(tempProcesses.begin(), tempProcesses.end(), compareByBurst);
                for (auto process : tempProcesses)
                {
                    readyQueue.push(process);
                }
            }

            processesInReadyQueue = readyQueue.size();

            while (processesInReadyQueue > 0)
            {
                Process currentProcess = readyQueue.front();
                readyQueue.pop();

                if (!currentProcess.isVisited())
                {
                    // Response time is: Time at which the process was allocated CPU for the first time - Arrival Time
                    currentProcess.setResponseTime(currentTime - currentProcess.getArrivalTime());
                    currentProcess.setVisited();
                    processes[currentProcess.getId() - 1].setResponseTime(currentTime - currentProcess.getArrivalTime());
                    processes[currentProcess.getId() - 1].setVisited();
                }

                //calculating time quantum-
                timeQuantum = modulusTimeQuantum(processesInReadyQueue, tempProcesses);
                numberOfContextSwitches++;

                int usedQuanta = min(timeQuantum, currentProcess.getBurstTime());
                currentTime += usedQuanta;
                currentProcess.setBurstTime(currentProcess.getBurstTime() - usedQuanta);

                processesInReadyQueue--;

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

            cycle++;

            // Check if any process arrived during the execution of the current process
            for (int i = 0; i <= currentTime; i++)
            {
                for (int j = 0; j < numberOfProcesses; j++)
                {
                    if (!alreadyInQueue[processes[j].getId() - 1] && processes[j].getArrivalTime() == i)
                    {
                        readyQueue.push(processes[j]);
                        alreadyInQueue[processes[j].getId() - 1] = true;
                        cycle = 0;
                    }
                }
            }
        }
        else
        {
            break;
        }
    } while (!readyQueue.empty());

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

   
    display(processes, numberOfProcesses, averageWaitingTime, averageTurnAroundTime, averageResponseTime, numberOfContextSwitches);
}

#endif