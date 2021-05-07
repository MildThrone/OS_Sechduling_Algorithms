#include <iostream>
#include "FCFS.h"
#include "SJN.h"
#include "RoundRobin.h"

using namespace std;

int main() {
    cout << "Schedule 1 : First Come First Serve" << endl;
    FCFS fcfs = FCFS();
    fcfs.schedule();
    cout << "Average Waiting Time: " << fcfs.getAverageWaitTime() << endl;
    cout << "Average Turnaround Time: " << fcfs.getAverageTurnaroundTime() << endl;


    cout << "Schedule 2 : Shortest Job Next" << endl;
    SJN sjn = SJN();
    sjn.schedule();
    cout << "Average Waiting Time: : " << sjn.getAverageWaitingTime() << endl;
    cout << "Average Turnaround Time: " << sjn.getAverageTurnaroundTime();


    cout << "Schedule 3 : Round Robin" << endl;
    RoundRobin rr = RoundRobin();
    rr.schedule();
    cout << "Average Waiting Time: : " << rr.getAverageWaitingTime() << endl;
    cout << "Average Turnaround Time: " << rr.getAverageTurnaroundTime() << endl;

    return 0;
}
