#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    // Create a child process
    pid_t child_pid = fork();

    // Check if fork failed
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    // Parent process
    else if (child_pid > 0) {
        cout << "Printed from parent process with PID: " << getpid() << endl;
    }
    // Child process
    else {
        cout << "Printed from child process with PID: " << getpid() << endl;
    }

    return 0;
}
