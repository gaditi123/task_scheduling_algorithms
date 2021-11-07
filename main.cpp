#include <bits/stdc++.h>
#include "fcfs.h"
#include "sjf.h"
#include "main.h"

using namespace std;

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

    fcfs_function(processes, numberOfProcesses);

    cout << "\nMade with <3 by Aditi (B19EE003), Darshit (B19EE024), and Harsh (B19EE036)";

    return 0;
}