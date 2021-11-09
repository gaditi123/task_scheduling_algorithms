#include "./scheduing algorithms/main.h"
#include "./scheduing algorithms/fcfs.h"
#include "./scheduing algorithms/sjf.h"
#include "./scheduing algorithms/sjrf.h"
#include "./scheduing algorithms/rr.h"
#include "./scheduing algorithms/ambrr.h"
#include "./scheduing algorithms/an.h"
#include "./scheduing algorithms/isbrr.h"
#include "./scheduing algorithms/mbrr.h"

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "\tTask Scheduling Algorithms!\n\n";

    int numberOfProcesses, tempInput, timeQuantum;
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

    cout << "\nEnter the Time Quantum for Round Robin Algorithm:\n";
    cin >> timeQuantum;

    // First Come First Served
    fcfs_function(processes, numberOfProcesses);
    
    // Shortest Job First
    sjf_function(processes, numberOfProcesses);

    // Shortest Job Remaining First
    sjrf_function(processes, numberOfProcesses);

    // Round Robin
    rr_function(processes, numberOfProcesses, timeQuantum);

    // Alternating Median Based Round Robin
    ambrr_function(processes, numberOfProcesses);

    // AN Algorithm
    an_function(processes, numberOfProcesses);

    // Improved Shortest Remaining Burst Round Robin
    isbrr_function(processes, numberOfProcesses);

    // Modulus Based Round Robin
    mbrr_function(processes, numberOfProcesses);
    
    cout << "\nMade with <3 by Aditi (B19EE003), Darshit (B19EE024), and Harsh (B19EE036)";

    return 0;
}