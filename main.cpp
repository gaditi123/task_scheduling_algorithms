#include <bits/stdc++.h>
#include "fcfs.h"
#include "sjf.h"
#include "rr.h"

using namespace std;

class Process
{
private:
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

int main()
{
    cout << "\tTask Scheduling Algorithms!\n\n";

    int numberOfProcesses, tempInput;
    cout << "Please enter the number of processes:\n";
    cin >> numberOfProcesses;

    vector<Process> processes(numberOfProcesses);

    for (int i = 0; i < numberOfProcesses; i++)
    {
        processes[i].setId(i + 1);
        cout << "Enter the Arrival Time for Process " << i + 1 << ":\n";
        cin >> tempInput;
        processes[i].setArrivalTime(tempInput);
        cout << "Enter the Burst Time for Process " << i + 1 << ":\n";
        cin >> tempInput;
        processes[i].setBurstTime(tempInput);
    }

    cout << "\nMade with <3 by Aditi (B19EE003), Darshit (B19EE024), and Harsh (B19EE036)";

    return 0;
}