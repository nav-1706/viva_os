#include<iostream>
using namespace std;

// Function declarations
void executeAlgorithm();
void initialize();

// Global variables
int allocation[10][3], need[10][3], Max[10][3], available[10][3];
bool executed[10], deadlock;
int p, current[3]; // Declaration of missing variables

// Main function
int main() {
    int keepGoing = 1;

    // Input number of processes
    cout << "Enter number of processes: ";
    cin >> p; // Assign the input to 'p'
    cout << "\n";

    // Input current resources
    cout << "Enter the current resources: ";
    cin >> current[0] >> current[1] >> current[2]; // Assign the inputs to 'current'

    // Input details for each process
    for (int i = 0; i < p; ++i) {
        cout << "\n\n\t\t\tProcess P" << i + 1 << " Details\n";
        cout << "Enter Allocation: ";
        cin >> allocation[i][0] >> allocation[i][1] >> allocation[i][2];
        cout << "Enter Max: ";
        cin >> Max[i][0] >> Max[i][1] >> Max[i][2];

        // Calculate need for each process
        need[i][0] = Max[i][0] - allocation[i][0];
        need[i][1] = Max[i][1] - allocation[i][1];
        need[i][2] = Max[i][2] - allocation[i][2];
    }

    // Display table for Banker's Algorithm
    cout << "\n\n\t\t\tTable for Banker's Algorithm\n\n";
    cout << "Initial Resources: " << current[0] << " " << current[1] << " " << current[2] << "\n\n";
    cout << "Process\tMax\tAllocation\tNeed\n";
    for (int i = 0; i < p; ++i) {
        cout << " P" << i + 1 << "\t";
        cout << " " << Max[i][0] << " " << Max[i][1] << " " << Max[i][2] << "\t";
        cout << " " << allocation[i][0] << " " << allocation[i][1] << " " << allocation[i][2] << "\t";
        cout << " " << need[i][0] << " " << need[i][1] << " " << need[i][2];
        cout << "\n";
    }
    cout << "\n\n";

    // Execute algorithm
    executeAlgorithm();

    // Perform operations based on user input
    while (keepGoing) {
        int choice, process;

        // Menu for operations
        cout << "\n\nSelect Below Operations:\n\n";
        cout << "1. Change Max of a process\n";
        cout << "2. Change Allocation of a process\n";
        cout << "3. Change Initial Resources\n";
        cout << "4. Exit\n\n";
        cin >> choice;

        // Perform selected operation
        switch (choice) {
            case 1:
                cout << "\n\nEnter Process No: ";
                cin >> process;
                cout << "\nEnter New Max: ";
                cin >> Max[process - 1][0] >> Max[process - 1][1] >> Max[process - 1][2];
                break;
            case 2:
                cout << "\n\nEnter Process No: ";
                cin >> process;
                cout << "\nEnter New Allocation: ";
                cin >> allocation[process - 1][0] >> allocation[process - 1][1] >> allocation[process - 1][2];
                break;
            case 3:
                cout << "\nEnter Initial Resources: ";
                cin >> current[0] >> current[1] >> current[2];
                break;
            case 4:
                keepGoing = 0;
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }

        // Execute algorithm after each operation
        executeAlgorithm();
    }

    return 0;
}

// Function to execute Banker's Algorithm
void executeAlgorithm() {
    initialize();
    int i, j;

    for (i = 0; i < p; ++i) {
        for (j = 0; j < p; ++j) {
            while (executed[j] && j < p - 1) {
                j++;
            }

            if (need[j][0] <= current[0] && need[j][1] <= current[1] && need[j][2] <= current[2]) {
                if (!executed[j]) {
                    executed[j] = true;
                    current[0] += allocation[j][0];
                    current[1] += allocation[j][1];
                    current[2] += allocation[j][2];
                    cout << "\nProcess P" << j + 1;
                    cout << "\nCurrent: " << current[0] << " " << current[1] << " " << current[2] << "\n";
                    cout << "\nProcess executed without deadlock";
                }
            }
        }
        deadlock = true;
        break;

        if (!deadlock) {
            cout << "\n\t\t\tDeadlock\n\n";
            break;
        } else {
            deadlock = false;
        }
    }
}

// Function to initialize variables
void initialize() {
    deadlock = false;
    for (int i = 0; i < 10; ++i) {
        executed[i] = false;
    }
}
