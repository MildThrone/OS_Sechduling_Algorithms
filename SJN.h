#ifndef LAB3_V2_SJN_H
#define LAB3_V2_SJN_H

#include <iostream>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

class SJN {
public:
    SJN();
    void schedule();
    float getAverageWaitingTime();
    float getAverageTurnaroundTime();


private:
//    Using a map with the bursts as the keys
    map<int, int> processes;
    int processCount = 0;
    vector<int> turnaroundTimes, waitingTimes;
    vector<int> completionTimes;

    float totalWaitTime = 0, totalTurnaroundTime = 0;


/*
 *  Completion time = Current burst time + Sum(previous burst times)
 *  Turnaround time = Completion time - Arrival time
 *  Waiting time = Turnaround time - Burst time
 *  Average waiting time = Total waiting time / Number of processes
 */
};


#endif //LAB3_V2_SJN_H
