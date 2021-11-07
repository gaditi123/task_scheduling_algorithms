#ifndef MAIN_H
#define MAIN_H
#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    bool visited = false;
    int id;
    int burstTime;
    int arrivalTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int responseTime;

public:
    bool isVisited()
    {
        return visited;
    }
    int getId()
    {
        return id;
    }
    int getBurstTime()
    {
        return burstTime;
    }
    int getArrivalTime()
    {
        return arrivalTime;
    }
    int getCompletionTime()
    {
        return completionTime;
    }
    int getTurnAroundTime()
    {
        return turnAroundTime;
    }
    int getWaitingTime()
    {
        return waitingTime;
    }
    int getResponseTime()
    {
        return responseTime;
    }
    void setVisited()
    {
        this->visited = true;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setBurstTime(int burstTime)
    {
        this->burstTime = burstTime;
    }
    void setArrivalTime(int arrivalTime)
    {
        this->arrivalTime = arrivalTime;
    }
    void setCompletionTime(int completionTime)
    {
        this->completionTime = completionTime;
    }
    void setTurnAroundTime(int turnAroundTime)
    {
        this->turnAroundTime = turnAroundTime;
    }
    void setWaitingTime(int waitingTime)
    {
        this->waitingTime = waitingTime;
    }
    void setResponseTime(int responseTime)
    {
        this->responseTime = responseTime;
    }
};

// Utility Functions

bool compareByArrival(Process p, Process q)
{
    return p.getArrivalTime() < q.getArrivalTime();
}

bool compareByBurst(Process p, Process q)
{
    return p.getBurstTime() < q.getBurstTime();
}

bool compareById(Process p, Process q)
{
    return p.getId() < q.getId();
}

void display(vector<Process> processes, int numberOfProcesses, float averageWaitingTime = 0, float averageTurnAroundTime = 0, float averageResponseTime = 0)
{
    // Sort processes according to ID for ease of displaying
    sort(processes.begin(), processes.end(), compareById);

    cout << "ID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time";
    for (int i = 0; i < numberOfProcesses; i++)
        cout << "\n"
             << processes[i].getId() << "\t\t" << processes[i].getArrivalTime() << "\t\t" << processes[i].getBurstTime() << "\t\t"
             << processes[i].getCompletionTime() << "\t\t" << processes[i].getTurnAroundTime() << "\t\t" << processes[i].getWaitingTime() << "\t\t" << processes[i].getResponseTime();
    cout << "\n\n\tAverage Waiting Time: " << averageWaitingTime;
    cout << "\n\tAverage Turn Around Time: " << averageTurnAroundTime;
    cout << "\n\tAverage Response Time: " << averageResponseTime;
    cout << "\n\n";
}

#endif