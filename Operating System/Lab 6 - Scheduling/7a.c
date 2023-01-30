// Round Robin Scheduling Algorithm

#include <stdio.h>

struct Process {
    int pid, bt, at, wt, rt, tat;
};

int main() {
    int n, i, j, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    struct Process p[n];
    printf("Enter burst time and arrival time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ",i+1);
        scanf("%d %d", &p[i].bt, &p[i].at);
        p[i].pid = i+1;
        p[i].rt = p[i].bt;
    }

    int current_time = 0;
    int completed_processes = 0;
    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (current_time >= p[i].at && p[i].rt > 0) {
                if (p[i].rt > quantum) {
                    current_time += quantum;
                    p[i].rt -= quantum;
                } else {
                    current_time += p[i].rt;
                    p[i].wt = current_time - p[i].at - p[i].bt;
                    p[i].tat = current_time - p[i].at;
                    p[i].rt = 0;
                    completed_processes++;
                }
            }
        }
    }


    float sum_waiting = 0, sum_turnaround = 0, avg_waiting = 0, avg_turnaround = 0;
    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].at, p[i].wt, p[i].tat);
        sum_waiting += p[i].wt;
        sum_turnaround += p[i].tat;
    }
    avg_waiting = sum_waiting/n;
    avg_turnaround = sum_turnaround/n;
    printf("\nAverage Waiting time (AWT) = %.2f", avg_waiting);
    printf("\nAverage Turnaround time (ATAT) = %.2f\n", avg_turnaround);
    return 0;
}