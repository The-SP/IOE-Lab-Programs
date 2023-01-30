// Shortest Job First (SJF) CPU Scheduling Alogrithm

#include <stdio.h>

struct Process {
    int pid, bt, wt, tat;
};

int main() {
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n], temp;
    printf("Enter burst time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ",i+1);
        scanf("%d", &p[i].bt);
        p[i].pid = i+1;
    }


    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++) {
            if (p[i].bt > p[j].bt) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }


    int current_time = 0;
    float sum_wt=0, avg_wt;
    float sum_tat=0, avg_tat ;
    printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        p[i].wt = current_time;
        current_time += p[i].bt;
        p[i].tat = current_time;
        sum_wt += p[i].wt;
        sum_tat += p[i].tat;
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }

    avg_wt = sum_wt/n;
    avg_tat = sum_tat/n;
    printf("\nAverage Waiting time (AWT) = %.2f", avg_wt);
    printf("\nAverage Turnaround time (ATAT) = %.2f\n", avg_tat);

    return 0;
}