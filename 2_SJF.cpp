#include <iostream>
using namespace std;

// Define a constant for the maximum number of processes
const int MAX_PROCESSES = 10;

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to arrange processes based on arrival time
void arrangeArrival(int num, int mat[][6]) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (mat[j][1] > mat[j + 1][1]) {
                for (int k = 0; k < 5; k++)
                    swap(mat[j][k], mat[j + 1][k]);
            }
        }
    }
}

// Function to calculate completion time, waiting time, and turnaround time
void completionTime(int num, int mat[][6]) {
    int temp, val;
    mat[0][3] = mat[0][1] + mat[0][2];
    mat[0][5] = mat[0][3] - mat[0][1];
    mat[0][4] = mat[0][5] - mat[0][2];
    
    for (int i = 1; i < num; i++) {
        temp = mat[i - 1][3];
        int low = mat[i][2];
        
        for (int j = i; j < num; j++) {
            if (temp >= mat[j][1] && low >= mat[j][2]) {
                low = mat[j][2];
                val = j;
            }
        }
        
        mat[val][3] = temp + mat[val][2];
        mat[val][5] = mat[val][3] - mat[val][1];
        mat[val][4] = mat[val][5] - mat[val][2];
        
        for (int k = 0; k < 6; k++)
            swap(mat[val][k], mat[i][k]);
    }
}

int main() {
    int num;
    cout << "Enter the number of processes: ";
    cin >> num;
    cout << "\n";

    // Declare an array to store process information
    int mat[MAX_PROCESSES][6];

    // Input process details
    for (int i = 0; i < num; i++) {
        cout << "Process P(" << i + 1 << "):\n";
        cout << "Enter ID: ";
        cin >> mat[i][0];
        cout << "Enter Arrival Time: ";
        cin >> mat[i][1];
        cout << "Enter Burst Time: ";
        cin >> mat[i][2];
    }

    // Display processes before arranging
    cout << "\nBefore Arranging:\n";
    cout << "Process ID\tArrival Time\tBurst Time\n";
    for (int i = 0; i < num; i++) {
        cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t" << mat[i][2] << "\n";
    }

    // Arrange processes based on arrival time
    arrangeArrival(num, mat);

    // Calculate completion time, waiting time, and turnaround time
    completionTime(num, mat);

    // Display result
    cout << "\nResult:\n";
    cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < num; i++) {
        cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t" << mat[i][2] << "\t\t"
             << mat[i][4] << "\t\t" << mat[i][5] << "\n";
    }

    return 0;
}
