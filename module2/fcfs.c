#include <stdio.h>

struct Process {
    int pid, arrival_time, burst_time, waiting_time, turnaround_time;
};

void calculateTimes(struct Process p[], int n) {
    int completion_time[n];
    completion_time[0] = p[0].arrival_time + p[0].burst_time;
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;

    for (int i = 1; i < n; i++) {
        if (p[i].arrival_time > completion_time[i - 1])
            completion_time[i] = p[i].arrival_time + p[i].burst_time;
        else
            completion_time[i] = completion_time[i - 1] + p[i].burst_time;

        p[i].waiting_time = completion_time[i - 1] - p[i].arrival_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

void displayProcesses(struct Process p[], int n) {
    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct Process p[n];
    
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", p[i].pid);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }

    calculateTimes(p, n);
    displayProcesses(p, n);

    return 0;
}


/*
Enter number of processes: 3
Enter arrival time and burst time for process 1: 0 5
Enter arrival time and burst time for process 2: 1 3
Enter arrival time and burst time for process 3: 2 8

PID	Arrival	Burst	Waiting	Turnaround
1	0	5	0	5
2	1	3	4	7
3	2	8	5	13

*/
