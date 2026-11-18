
#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10] = {0}, safe[10];

    cout << "Enter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "Enter Maximum Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> max[i][j];

    cout << "Enter Available Resources:\n";
    for(int j = 0; j < m; j++)
        cin >> avail[j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int count = 0;

    while(count < n) {
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int j;

                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j])
                        break;
                }

                if(j == m) {
                    for(int k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }

        if(!found) {
            cout << "\nSystem is not in safe state.";
            return 0;
        }
    }

    cout << "\nSystem is in safe state.";
    cout << "\nSafe Sequence: ";

    for(int i = 0; i < n; i++)
        cout << "P" << safe[i] << " ";

    return 0;
}
