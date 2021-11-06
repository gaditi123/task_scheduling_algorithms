#include <bits/stdc++.h>
#include "fcfs.h"
#include "sjf.h"

using namespace std;

int main()
{
    cout << "Task Scheduling Algorithms!n\n";

    int numberOfProcesses;
    cout << "Please enter the number of processes:\n";
    cin >> numberOfProcesses;

    vector<int> processID(numberOfProcesses);
    vector<int> arrivalTime(numberOfProcesses);
    vector<int> burstTime(numberOfProcesses);

    for (int i = 0; i < numberOfProcesses; i++)
    {
        processID[i] = i + 1;
        cout << "Enter the Arrival Time for Process " << i + 1 << ":\n";
        cin >> arrivalTime[i];
        cout << "Enter the Burst Time for Process " << i + 1 << ":\n";
        cin >> burstTime[i];
    }

// Changing the arrival time of different processes
    int a=arrivalTime[0];
 	int i;
 	for(i=0;i<numberOfProcesses;i++){
 		if(arrivalTime[i]<a)
 			a=arrivalTime[i];
	 }
	 if(a!=0){
	 	for(i=0;i<numberOfProcesses;i++)
	 		arrivalTime[i]=arrivalTime[i]-a;
	 }

     fcfs_function(numberOfProcesses, arrivalTime,burstTime);
     sjf_function(numberOfProcesses, processID, arrivalTime, burstTime);

     cout << "\nMade with <3 by Aditi (B19EE003), Darshit (B19EE024), and Harsh (B19EE036)";

     return 0;
}