#include <iostream>
using namespace std;

int main() {
    int nopages, nofaults, page[20], i, count = 0;

    // Input number of pages
    cout << "\nEnter the number of pages for which you want to calculate page faults: ";
    cin >> nopages;

    // Input the reference string
    cout << "\nEnter the reference string: ";
    for (i = 0; i < nopages; i++) {
        cout << "\t";
        cin >> page[i];
    }

    // Input number of frames
    cout << "\nEnter the number of frames: ";
    cin >> nofaults;

    int frame[nofaults], fcount[nofaults];

    // Initialize frame array and frame count array
    for (i = 0; i < nofaults; i++) {
        frame[i] = -1;
        fcount[i] = 0;
    }

    i = 0;
    while (i < nopages) {
        int j = 0, flag = 0;

        // Check if page is already present in frame
        while (j < nofaults) {
            if (page[i] == frame[j]) {
                flag = 1;
                fcount[j] = i + 1;
            }
            j++;
        }

        j = 0;
        cout << "\n\t***\n";
        cout << "\t" << page[i] << "-->";

        if (flag == 0) {
            // Page fault occurred
            int min = 0, k = 0;
            while (k < nofaults - 1) {
                if (fcount[min] > fcount[k + 1]) {
                    min = k + 1;
                }
                k++;
            }

            // Replace the page with the minimum frame count
            frame[min] = page[i];
            fcount[min] = i + 1;
            count++;

            // Print the frames
            while (j < nofaults) {
                cout << "\t|" << frame[j] << "|";
                j++;
            }
        }
        i++;
    }
    cout << "\n\t***\n";
    cout << "\n\tPage Faults: " << count;
    return 0;
}
