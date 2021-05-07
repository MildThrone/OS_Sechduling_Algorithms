#include "FCFS.h"

FCFS::FCFS() = default;

void FCFS::schedule() {
    cout << "Enter the Arrival Times " << endl;

    for (int i = 0; i < processCount; ++i) {
        cout << "P" << i+1 << ":";
        cin >> arrivalTimes[i];
    }
    cout << endl;

    cout << "Enter the Burst Times " << endl;

    cout << "### : AT : BT" << endl;
    for (int i = 0; i < processCount; ++i) {
        cout << "#P" << i+1 << " :  " << arrivalTimes[i] << " :  ";
        cin >> burstTimes[i];
    }
}

float FCFS::getAverageWaitTime() {
    float averageWaitTime;

//    Find completion times
    for (int i = 0; i < processCount; ++i) {
        if (i == 0) {
            completionTimes[i] = burstTimes[i] + arrivalTimes[i];
        } else {
            int prevBursts = 0;
            for (int j = 0; j < i; ++j) {
                prevBursts = prevBursts + burstTimes[j];
            }
            completionTimes[i] = burstTimes[i] + prevBursts;
        }

//    Find turnaround times
        turnaroundTimes[i] = completionTimes[i] - arrivalTimes[i];

//    Find wait time
        waitTimes[i] = turnaroundTimes[i] - burstTimes[i];
    }


//    Calculate total wait time
    for (int waitTime : waitTimes) {
        totalWaitTime = (float)waitTime + totalWaitTime;
    }

    averageWaitTime = (float) (totalWaitTime / processCount);

    return averageWaitTime;
}

float FCFS::getAverageTurnaroundTime() {
    float averageTurnaroundTime;

    for (int turnaroundTime : turnaroundTimes) {
        totalTurnaroundTime = (float) turnaroundTime + totalTurnaroundTime;
    }

    averageTurnaroundTime = (float) (totalTurnaroundTime / processCount);

    return averageTurnaroundTime;
}
