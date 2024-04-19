#include<iostream>
using namespace std;

// Function to calculate waiting time for each process
void calculateWaitingTime(int processes[], int numProcesses, int burstTime[], int waitingTime[], int quantum)
{
    int remainingBurstTime[numProcesses];
    for (int i = 0; i < numProcesses; i++)
        remainingBurstTime[i] = burstTime[i];

    int time = 0;
    while (true)
    {
        bool allDone = true;
        for (int i = 0; i < numProcesses; i++)
        {
            if (remainingBurstTime[i] > 0)
            {
                allDone = false;
                if (remainingBurstTime[i] > quantum)
                {
                    time += quantum;
                    remainingBurstTime[i] -= quantum;
                }
                else
                {
                    time += remainingBurstTime[i];
                    waitingTime[i] = time - burstTime[i];
                    remainingBurstTime[i] = 0;
                }
            }
        }
        if (allDone)
            break;
    }
}

// Function to calculate turnaround time for each process
void calculateTurnaroundTime(int processes[], int numProcesses, int burstTime[], int waitingTime[], int turnaroundTime[])
{
    for (int i = 0; i < numProcesses; i++)
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
}

// Function to find average waiting time and average turnaround time
void findAverageTimes(int processes[], int numProcesses, int burstTime[], int quantum)
{
    int waitingTime[numProcesses], turnaroundTime[numProcesses];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Calculate waiting time and turnaround time
    calculateWaitingTime(processes, numProcesses, burstTime, waitingTime, quantum);
    calculateTurnaroundTime(processes, numProcesses, burstTime, waitingTime, turnaroundTime);

    // Display process details and calculate totals
    cout << "Processes\tBurst time\tWaiting time\tTurnaround time\n";
    for (int i = 0; i < numProcesses; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        cout << processes[i] << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }

    // Calculate and display averages
    cout << "Average waiting time = " << (float)totalWaitingTime / numProcesses << endl;
    cout << "Average turnaround time = " << (float)totalTurnaroundTime / numProcesses;
}

int main()
{
    // Process IDs and burst times
    int processIDs[] = {1, 2, 3};
    int numProcesses = sizeof(processIDs) / sizeof(processIDs[0]);
    int burstTime[] = {10, 5, 8};
    int quantum = 2;

    // Find and display average waiting time and average turnaround time
    findAverageTimes(processIDs, numProcesses, burstTime, quantum);
    return 0;
}
