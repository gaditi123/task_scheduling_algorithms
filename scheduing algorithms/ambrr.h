#ifndef AMBRR_H
#define AMBRR_H
#include "./main.h"

#include <bits/stdc++.h>

using namespace std;

int findMedian(vector<Process> processes)
{
    int n = processes.size();
    if (n % 2 != 0)
    {
        return processes[n / 2].getBurstTime();
    }
    int index = n / 2;
    float res = processes[index].getBurstTime() + processes[index - 1].getBurstTime();
    res = res / 2;
    return ceil(res);
}

int findDifference(vector<Process> processes)
{
    int n = processes.size();
    return (processes[n - 1].getBurstTime() - findMedian(processes));
}

void ambrr_function(vector<Process> processes, int numberOfProcesses)
{

    cout << "\n\t*** Alternating Median Based Round Robin ***\n";

    int processesCompleted = 0, currentTime = 0, cycle = 0, processesInReadyQueue, timeQuantum, m, d, g, s;

    vector<bool> alreadyInQueue(numberOfProcesses, false);
    vector<Process> tempProcesses = processes;
    sort(tempProcesses.begin(), tempProcesses.end(), compareByArrival);
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
                m = findMedian(tempProcesses);
                cout << "\n(Median) m: " << m << endl;
                d = findDifference(tempProcesses);
                cout << "(Difference b/w median and the largest burst time) d: " << d << endl << endl;
                if (m > d)
                {
                    g = m;
                    s = d;
                }
                else
                {
                    g = d;
                    s = m;
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

                if (cycle % 2 == 0)
                {
                    timeQuantum = g;
                }
                else
                {
                    timeQuantum = s;
                }

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

    display(processes, numberOfProcesses, averageWaitingTime, averageTurnAroundTime, averageResponseTime);
}

#endif