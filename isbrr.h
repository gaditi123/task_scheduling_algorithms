#ifndef ISBRR_H
#define ISBRR_H
#include "main.h"
#include <bits/stdc++.h>
using namespace std;

int time_quantum(vector<Process> processes, int numberOfProcesses){
    int i=0;
    int sum=0;
    float k=0;
    float m=0;
    for(i=0;i<numberOfProcesses;i++){
        sum= sum + processes[i].getBurstTime()*processes[i].getBurstTime();
    }
    m=sum/numberOfProcesses;
    k=sqrt(m);
    return(ceil(k));
}

void isbrr_function(vector<Process> processes, int numberOfProcesses)
{
	cout<<"\n\t*** Improved Shortest Remaining Burst Round Robin ***\n";
	int time = 0;
    int tmp=0;
    int temp=0;
    int executedCount = 0;
	float avgTurnAroundTime = 0;
    float avgWaitTime = 0;
    float avgResponseTime =0;
    int context_count =0;
	vector <Process> processInQueue;
    vector<bool> inQueue(numberOfProcesses, false);
	map<int,int> pid_complete;
	while(executedCount!=numberOfProcesses)
	{
		for(int i=0; i<numberOfProcesses; i++)
		{
			if((processes[i].getArrivalTime()<=time)&&(inQueue[i]==false))
			{
				processInQueue.push_back(processes[i]);
				inQueue[i]=true;
			}

		}
        // for(int i=0; i<numberOfProcesses; i++){
        //     for(int j=i+1; j<numberOfProcesses; j++){
        //         if (processInQueue[i].getBurstTime()>processInQueue[j].getBurstTime()){
        //             tmp = processInQueue[i].getBurstTime();
        //             processInQueue[i].setBurstTime(processInQueue[j].getBurstTime());
        //             processInQueue[j].setBurstTime(tmp);
        //         }
        //     }
        // }
		if(processInQueue.size()!=0){
			vector<Process>::iterator minPosition = min_element(processInQueue.begin(),
				processInQueue.end(), compareByBurst);
            temp = time_quantum(processInQueue,processInQueue.size());
            if((*minPosition).getBurstTime()==0){
				pid_complete[(*minPosition).getId()]=time;
				executedCount++;
				processInQueue.erase(minPosition);
                //context_count++;
			}
			if((*minPosition).getBurstTime()<=temp){
                time=time+(*minPosition).getBurstTime();
                pid_complete[(*minPosition).getId()]=time;
				executedCount++;
				processInQueue.erase(minPosition);
                //context_count++;
            }
            else{
                time = time + temp;
                (*minPosition).setBurstTime((*minPosition).getBurstTime() - temp);
                temp = (*minPosition).getBurstTime() - temp;
            }
        }
        else {
            time++;
		}
	}
	for(int i=0; i<numberOfProcesses ; i++){
		processes[i].setCompletionTime(pid_complete[processes[i].getId()]);
		processes[i].setTurnAroundTime(processes[i].getCompletionTime() - processes[i].getArrivalTime());
		processes[i].setWaitingTime(processes[i].getTurnAroundTime() - processes[i].getBurstTime());
        processes[i].setResponseTime(processes[i].getCompletionTime() - processes[i].getBurstTime() - processes[i].getArrivalTime());
		avgWaitTime+=processes[i].getWaitingTime();
		avgTurnAroundTime+=processes[i].getTurnAroundTime();
        avgResponseTime+=processes[i].getResponseTime();
	}
	avgWaitTime = (float)avgWaitTime/numberOfProcesses;
	avgTurnAroundTime = (float)avgTurnAroundTime/numberOfProcesses;
    avgResponseTime = (float)avgResponseTime/numberOfProcesses;
    //context_count =context_count - 1;
 	display(processes,numberOfProcesses,avgWaitTime,avgTurnAroundTime, avgResponseTime, context_count);

}
#endif 