#ifndef LAB3_V2_FCFS_H
#define LAB3_V2_FCFS_H

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class FCFS {
public:
    FCFS();
    void schedule();
    float getAverageWaitTime();
    float getAverageTurnaroundTime();

//  TODO:: Switch from arrays to vectors and remove the fixed processCount
private:
//    Change the processCount if you want. Default : 4
    static const int processCount = 4;
    int arrivalTimes[processCount];
    int burstTimes[processCount];
    int waitTimes[processCount];
    int completionTimes[processCount];
    int turnaroundTimes[processCount];
    float totalWaitTime = 0, totalTurnaroundTime = 0;


/*
 *  Completion time = Current burst time + Sum(previous burst times)
 *  Turnaround time = Completion time - Arrival time
 *  Waiting time = Turnaround time - Burst time
 *  Average waiting time = Total waiting time / Number of processes
 */

};


#endif //LAB3_V2_FCFS_H
