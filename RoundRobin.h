#ifndef LAB3_V2_ROUNDROBIN_H
#define LAB3_V2_ROUNDROBIN_H

#include <iostream>

using namespace std;

class RoundRobin {
public:
    RoundRobin();
    void schedule();
    float getAverageWaitingTime();
    float getAverageTurnaroundTime();


private:
    int processCount;
    int timeSlice;
    int process_done;

    float totalWaitTime;
    float turn_around;
    float cpuTimeline;
    float pauseTimes[4];
    float burstTimes[4];
    float arrivalTimes[4];
    float waitingTimes[4];


/*
 *  Completion time = Current burst time + Sum(previous burst times)
 *  Turnaround time = Completion time - Arrival time
 *  Waiting time = Turnaround time - Burst time
 *  Average waiting time = Total waiting time / Number of processes
 */
};


#endif //LAB3_V2_ROUNDROBIN_H
