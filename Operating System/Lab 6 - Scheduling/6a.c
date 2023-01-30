// First Come First Serve (FCFS) CPU Scheduling Alogrithm

#include <stdio.h>

struct Process {
    int pid, bt, at, wt, tat;
};

int main() {
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n], temp;
    printf("Enter burst time and arrival time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ",i+1);
        scanf("%d %d", &p[i].bt, &p[i].at);
        p[i].pid = i+1;
    }


    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (p[j].at > p[j+1].at) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }


    int current_time = 0;
    float sum_wt=0, avg_wt;
    float sum_tat=0, avg_tat ;
    printf("Process\t\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        p[i].wt = current_time;
        current_time += p[i].bt;
        p[i].tat = current_time-p[i].at;
        sum_wt += p[i].wt;
        sum_tat += p[i].tat;
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].at, p[i].wt, p[i].tat);
    }

    avg_wt = sum_wt/n;
    avg_tat = sum_tat/n;
    printf("\nAverage Waiting time (AWT) = %.2f", avg_wt);
    printf("\nAverage Turnaround time (ATAT) = %.2f\n", avg_tat);

    return 0;
}