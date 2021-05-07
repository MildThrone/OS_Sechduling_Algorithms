#include "RoundRobin.h"

RoundRobin::RoundRobin() = default;

void RoundRobin::schedule() {
    for(int i=0;i<processCount;i++){
        printf("Enter the CPU burst time of Process %d: ",(i+1));
        cin >> burstTimes[i];
        printf("Enter the CPU Arrival time of Process %d: ",(i+1));
        cin >> arrivalTimes[i];
    }
    cout<<"Enter the time slice: ";
    cin >> timeSlice;
}

float RoundRobin::getAverageWaitingTime() {
    float averageWaitTime;

    for(int i = 0; i < processCount; i++)
        pauseTimes[i]=arrivalTimes[i];
    cpuTimeline=arrivalTimes[0];

    while(process_done < processCount){
        for(int i = 0; i < processCount; i++) {
    //Don't run process if it is yet to arrive
            if(arrivalTimes[i] > cpuTimeline)continue;

            waitingTimes[i] += cpuTimeline - pauseTimes[i];
            totalWaitTime += cpuTimeline = pauseTimes[i];
            if (burstTimes[i] > (float) timeSlice) {
                cpuTimeline += (float) timeSlice;
                burstTimes[i] -= (float) timeSlice;
            } else if (burstTimes[i] > 0) {
                cpuTimeline += burstTimes[i];
                burstTimes[i] = 0;
                process_done++;
                cout<<"Process "<<(i+1)<<" done.\n";
            }
            pauseTimes[i] = cpuTimeline;
        }

    }

    averageWaitTime = totalWaitTime / (float) processCount;

    return averageWaitTime;
}

float RoundRobin::getAverageTurnaroundTime() {
    float averageTurnaroundTime;

    for (int i = 0; i < 4; i++) {
        turn_around += ( waitingTimes[i] + burstTimes[i] );
    }
    averageTurnaroundTime = turn_around / (float) processCount;

    return averageTurnaroundTime;
}
