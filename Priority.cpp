
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[20], p[20], ct[20], tat[20], wt[20];

    for(int i = 0; i < n; i++) {
        cout << "Enter BT and Priority of P" << i+1 << ": ";
        cin >> bt[i] >> p[i];
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(p[i] > p[j]) {
                swap(p[i], p[j]);
                swap(bt[i], bt[j]);
            }
        }
    }

    int time = 0;
    float avgWT = 0, avgTAT = 0;

    cout << "\nProcess\tBT\tPriority\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++) {
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];

        cout << "P" << i+1 << "\t"
             << bt[i] << "\t"
             << p[i] << "\t\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    cout << "\nAverage WT = " << avgWT/n;
    cout << "\nAverage TAT = " << avgTAT/n;

    return 0;
}
