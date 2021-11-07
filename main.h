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

void display(vector<Process> P, int jobCount, float avgwt = 0, float avgtat = 0)
{
	sort(P.begin(),P.end(),compareById);
	cout<<"\n\n\t\t The Process Status \n\n";
	cout<<"\tProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time";
	for (int i = 0; i < jobCount; ++i)
		cout<<"\n\t\t"<<P[i].getId()<<"\t\t"<<P[i].getArrivalTime()<<"\t\t"<<P[i].getBurstTime()<<"\t\t"
		<<P[i].getCompletionTime()<<"\t\t"<<P[i].getTurnAroundTime()<<"\t\t"<<P[i].getWaitingTime();
	cout<<"\n\n\t\tAverage Waiting Time: "<<avgwt;
	cout<<"\n\t\tAverage Turn Around Time: "<<avgtat;
	cout<<"\n\n\n";

}

#endif