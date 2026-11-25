
#include <iostream>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[20], rem[20], ct[20], tat[20], wt[20];

    cout << "Enter burst time:\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> bt[i];
        rem[i] = bt[i];
    }

    cout << "Enter time quantum: ";
    cin >> tq;

    int time = 0, done;

    do {
        done = 1;

        for(int i = 0; i < n; i++) {
            if(rem[i] > 0) {
                done = 0;

                if(rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                }
                else {
                    time += rem[i];
                    rem[i] = 0;
                    ct[i] = time;
                }
            }
        }
    } while(done == 0);

    float avgWT = 0, avgTAT = 0;

    cout << "\nProcess\tBT\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];

        cout << "P" << i+1 << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    cout << "\nAverage WT = " << avgWT/n;
    cout << "\nAverage TAT = " << avgTAT/n;

    return 0;
}
