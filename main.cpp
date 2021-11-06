#include <bits/stdc++.h>

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
    vector<int> waitingTime(numberOfProcesses);
    vector<int> turnAroundTime(numberOfProcesses);

    for (int i = 0; i < numberOfProcesses; i++)
    {
        processID[i] = i + 1;
        cout << "Enter the Arrival Time for Process " << i + 1 << ":\n";
        cin >> arrivalTime[i];
        cout << "Enter the Burst Time for Process " << i + 1 << ":\n";
        cin >> burstTime[i];
    }

    cout<<"\nMade with <3 by Aditi (B19EE003), Darshit (B19EE024), and Harsh (B19EE036)";

    return 0;
}