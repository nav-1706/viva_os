#include <iostream>
using namespace std;

// Function to calculate waiting time for each process
void calculateWaitingTime(int numProcesses, int burstTimes[], int waitingTimes[]) {
    waitingTimes[0] = 0;
    for (int i = 1; i < numProcesses; i++) {
        waitingTimes[i] = waitingTimes[i - 1] + burstTimes[i - 1];
    }
}

// Function to calculate turnaround time for each process
void calculateTurnaroundTime(int numProcesses, int burstTimes[], int waitingTimes[], int turnaroundTimes[]) {
    for (int i = 0; i < numProcesses; i++) {
        turnaroundTimes[i] = burstTimes[i] + waitingTimes[i];
    }
}

// Function to find average waiting time and average turnaround time
void findAverageTimes(int numProcesses, int burstTimes[]) {
    int totalTurnaroundTime = 0, totalWaitingTime = 0;
    int waitingTimes[numProcesses], turnaroundTimes[numProcesses];

    // Calculate waiting time and turnaround time
    calculateWaitingTime(numProcesses, burstTimes, waitingTimes);
    calculateTurnaroundTime(numProcesses, burstTimes, waitingTimes, turnaroundTimes);

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < numProcesses; i++) {
        totalTurnaroundTime += turnaroundTimes[i];
        totalWaitingTime += waitingTimes[i];
    }

    // Calculate and display average waiting time and average turnaround time
    cout << "Average Waiting Time: " << float(totalWaitingTime) / numProcesses << endl;
    cout << "Average Turnaround Time: " << float(totalTurnaroundTime) / numProcesses;
}

int main() {
    // Process IDs and burst times
    int processIDs[] = {1, 2, 3};
    int burstTimes[] = {10, 5, 8};
    int numProcesses = sizeof processIDs / sizeof processIDs[0];

    // Find and display average waiting time and average turnaround time
    findAverageTimes(numProcesses, burstTimes);

    return 0;
}
