#include <iostream>
#include <climits>
using namespace std;

// Define a struct to represent a process
struct Process {
    int id;
    int burstTime;
    int arrivalTime;
};

// Function to calculate turn-around time
void calculateTurnAroundTime(Process p[], int n, int waitingTime[], int turnAroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = p[i].burstTime + waitingTime[i];
    }
}

// Function to calculate waiting time
void calculateWaitingTime(Process p[], int n, int waitingTime[]) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = p[i].burstTime;
    }

    int completed = 0, currentTime = 0, minTime = INT_MAX;
    int shortest = 0, finishTime;
    bool found = false;

    while (completed != n) {
        for (int j = 0; j < n; j++) {
            if ((p[j].arrivalTime <= currentTime) && (remainingTime[j] < minTime) && remainingTime[j] > 0) {
                minTime = remainingTime[j];
                shortest = j;
                found = true;
            }
        }

        if (!found) {
            currentTime++;
            continue;
        }

        remainingTime[shortest]--;

        minTime = remainingTime[shortest];

        if (minTime == 0) {
            minTime = INT_MAX;
        }

        if (remainingTime[shortest] == 0) {
            completed++;
            found = false;
            finishTime = currentTime + 1;
            waitingTime[shortest] = finishTime - p[shortest].burstTime - p[shortest].arrivalTime;

            if (waitingTime[shortest] < 0) {
                waitingTime[shortest] = 0;
            }
        }

        currentTime++;
    }
}

// Function to calculate average waiting time and average turn-around time
void calculateAverageTime(Process p[], int n) {
    int waitingTime[n], turnAroundTime[n];
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    calculateWaitingTime(p, n, waitingTime);
    calculateTurnAroundTime(p, n, waitingTime, turnAroundTime);

    cout << "Processes\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n";

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];

        cout << "\t" << p[i].id << "\t\t" << p[i].burstTime << "\t\t" << p[i].arrivalTime << "\t\t"
             << waitingTime[i] << "\t\t" << turnAroundTime[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << (float)totalWaitingTime / n;
    cout << "\nAverage Turn Around Time = " << (float)totalTurnAroundTime / n << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process p[n];

    cout << endl;
    
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter the details for Process " << i + 1 << ":\n";
        cout << "Enter Arrival Time: ";
        cin >> p[i].arrivalTime;
        cout << "Enter Burst Time: ";
        cin >> p[i].burstTime;
    }

    calculateAverageTime(p, n);

    cout << endl;
    return 0;
}
