#include <iostream>
using namespace std;

int main() {
    int burstTime[20], priority[20], waitingTime[20], turnaroundTime[20], processID[20], i, j, numProcesses;
    int totalWaitingTime = 0, totalTurnaroundTime = 0, pos, temp, avgWaitingTime, avgTurnaroundTime;

    cout << "Enter total number of processes: ";
    cin >> numProcesses;

    // Input burst time and priority for each process
    cout << "\nEnter burst time and priority for each process:\n";
    for (i = 0; i < numProcesses; i++) {
        cout << "\nProcess P[" << i + 1 << "]:\n";
        cout << "Burst Time: ";
        cin >> burstTime[i];
        cout << "Priority: ";
        cin >> priority[i];
        processID[i] = i + 1;
    }

    // Sorting processes based on priority
    for (i = 0; i < numProcesses; i++) {
        pos = i;
        for (j = i + 1; j < numProcesses; j++) {
            if (priority[j] < priority[pos])
                pos = j;
        }
        temp = priority[i];
        priority[i] = priority[pos];
        priority[pos] = temp;
        temp = burstTime[i];
        burstTime[i] = burstTime[pos];
        burstTime[pos] = temp;
        temp = processID[i];
        processID[i] = processID[pos];
        processID[pos] = temp;
    }

    // Calculating waiting time for each process
    waitingTime[0] = 0;
    for (i = 1; i < numProcesses; i++) {
        waitingTime[i] = 0;
        for (j = 0; j < i; j++)
            waitingTime[i] += burstTime[j];
        totalWaitingTime += waitingTime[i];
    }

    avgWaitingTime = totalWaitingTime / numProcesses;
    totalWaitingTime = 0;

    // Calculating turnaround time for each process
    cout << "\nProcess\t Burst Time\t Waiting Time\t Turnaround Time\n";
    for (i = 0; i < numProcesses; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        cout << "P[" << processID[i] << "]\t\t " << burstTime[i] << "\t\t " << waitingTime[i] << "\t\t\t" << turnaroundTime[i] << endl;
    }

    avgTurnaroundTime = totalTurnaroundTime / numProcesses;

    // Displaying average waiting time and average turnaround time
    cout << "\nAverage Waiting Time = " << avgWaitingTime << endl;
    cout << "Average Turnaround Time = " << avgTurnaroundTime << endl;

    return 0;
}
