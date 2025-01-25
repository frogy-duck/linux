#include <stdio.h>

struct Process {
    int pid, burst_time, remaining_time;
};

void roundRobin(struct Process p[], int n, int time_quantum) {
    int time = 0, done;
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                done = 0;
                if (p[i].remaining_time > time_quantum) {
                    time += time_quantum;
                    p[i].remaining_time -= time_quantum;
                    printf("Process %d executed for %d units. Remaining time: %d\n", p[i].pid, time_quantum, p[i].remaining_time);
                } else {
                    time += p[i].remaining_time;
                    printf("Process %d executed for %d units. Completed at time: %d\n", p[i].pid, p[i].remaining_time, time);
                    p[i].remaining_time = 0;
                }
            }
        }
    } while (!done);
}

int main() {
    int n, time_quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct Process p[n];
    
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time for process %d: ", p[i].pid);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    roundRobin(p, n, time_quantum);

    return 0;
}


//Enter number of processes: 3
//Enter burst time for process 1: 8
//Enter burst time for process 2: 4
//Enter burst time for process 3: 9
//Enter time quantum: 3
//Process 1 executed for 3 units. Remaining time: 5
//Process 2 executed for 3 units. Remaining time: 1
//Process 3 executed for 3 units. Remaining time: 6
//Process 1 executed for 3 units. Remaining time: 2
//Process 2 executed for 1 units. Completed at time: 10
//Process 3 executed for 3 units. Remaining time: 3
//Process 1 executed for 2 units. Completed at time: 15
//Process 3 executed for 3 units. Completed at time: 18
