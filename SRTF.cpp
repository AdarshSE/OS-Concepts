#include <iostream>
using namespace std;

int main()
{
    int n, max = 100;
    cout << "Enter number of processes: ";
    cin >> n;

    if(n > max)
    {
        cout << "Maximum 100 processes allowed.";
        return 0;
    }

    int AT[100], BT[100], RT[100], FT[100], TAT[100], WT[100];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter AT and BT of P" << i + 1 << ": ";
        cin >> AT[i] >> BT[i];
        RT[i] = BT[i];
    }

    int currentTime = 0;
    int completedProcesses = 0;

    while(completedProcesses < n)
    {
        int shortestProcess = -1;

        for(int i = 0; i < n; i++)
        {
            if(AT[i] <= currentTime && RT[i] > 0)
            {
                if(shortestProcess == -1 || RT[i] < RT[shortestProcess])
                {
                    shortestProcess = i;
                }
            }
        }

        if(shortestProcess == -1)
        {
            currentTime++;
        }
        else
        {
            RT[shortestProcess]--;
            currentTime++;

            if(RT[shortestProcess] == 0)
            {
                FT[shortestProcess] = currentTime;
                completedProcesses++;
            }
        }
    }

    int totalWT = 0;
    int totalTAT = 0;

    for(int i = 0; i < n; i++)
    {
        TAT[i] = FT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];

        totalWT = totalWT + WT[i];
        totalTAT = totalTAT + TAT[i];
    }

    cout << "\nP\tAT\tBT\tFT\tTAT\tWT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t"
             << AT[i] << "\t"
             << BT[i] << "\t"
             << FT[i] << "\t"
             << TAT[i] << "\t"
             << WT[i] << endl;
    }

    cout << "\nAverage WT = " << (float)totalWT / n;
    cout << "\nAverage TAT = " << (float)totalTAT / n;

    return 0;
}
