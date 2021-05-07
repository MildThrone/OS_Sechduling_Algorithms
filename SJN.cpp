#include "SJN.h"

SJN::SJN() = default;

void SJN::schedule() {
    cout << "State the number of processes: ";
    cin >> processCount;

    int burstTime, arrivalTime;
    for (int i = 0; i < processCount; ++i) {
        cout << "Enter the Arrival Time" << endl;
        cout << "P" << i+1 << ":";
        cin >> arrivalTime;

        cout << "Enter the Burst Time" << endl;
        cout << "P" << i+1 << ":";
        cin >> burstTime;

        processes.insert(pair<int, int>(burstTime, arrivalTime));
    }
}

float SJN::getAverageWaitingTime() {
    map<int, int> :: iterator iterator;
    int pos = 0;
    float averageWaitingTime;
    int burstTimes[processCount], arrivalTimes[processCount];

    for (iterator = processes.begin(); iterator != processes.end(); iterator++) {
        burstTimes[pos] = iterator->first;
        arrivalTimes[pos] = iterator->second;
        pos++;
    }

//    Find completion times
    for (int i = 0; i <= processCount; i++) {
        if (pos == 0) {
            completionTimes.push_back( burstTimes[i] + arrivalTimes[i] );
            pos++;
        } else {
            int prevBursts = 0;
            for (int i = 0; i < pos; ++i) {
                prevBursts = prevBursts + burstTimes[i];
            }
            completionTimes.push_back( burstTimes[i] + prevBursts );
        }
    }

    for (int i = 0; i < processCount; ++i) {
//   Find turnaround times
        turnaroundTimes.push_back( completionTimes[i] - iterator->second );

//   Find waiting times
        waitingTimes.push_back( turnaroundTimes[i] - iterator->first );
        iterator++;
    }

//    Calculating total waiting time
    for (int waitingTime : waitingTimes) {
        totalWaitTime = totalWaitTime + (float) waitingTime;
        cout << waitingTime << " ";
    }

//    Calculate turnaround times
    for (int i = 0; i < processCount; ++i) {
        turnaroundTimes.push_back(completionTimes[i] - burstTimes[i]);
    }

    averageWaitingTime = totalWaitTime / (float) processCount;

    return averageWaitingTime;
}

float SJN::getAverageTurnaroundTime() {
    totalTurnaroundTime = (float) accumulate(turnaroundTimes.begin(), turnaroundTimes.end(), 0);

    return totalTurnaroundTime / (float ) processCount;
}
