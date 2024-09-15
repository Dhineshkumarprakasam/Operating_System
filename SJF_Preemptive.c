#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int job;  // Process ID
    int at;   // Arrival time
    int bt;   // Burst time
    int ft;   // Finish time (completion time)
    int tat;  // Turnaround time
    int wat;  // Waiting time
    int remaining_bt; // Remaining burst time
} Process;

void calculate_sjf_preemptive_scheduling(Process processes[], int num_processes) {
    int current_time = 0;
    int total_tat = 0;
    int total_wat = 0;
    int completed = 0;

    while (completed < num_processes) {
        int min_burst_time_index = -1;
        int min_burst_time = 10000;

        // Find the process with the minimum remaining burst time
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].at <= current_time && processes[i].remaining_bt > 0 && processes[i].remaining_bt < min_burst_time) {
                min_burst_time = processes[i].remaining_bt;
                min_burst_time_index = i;
            }
        }

        // If no process is available at the current time, increment the time
        if (min_burst_time_index == -1) {
            current_time++;
            continue;
        }

        // Execute the process with the minimum burst time for 1 unit of time
        processes[min_burst_time_index].remaining_bt--;
        current_time++;

        // If the process is completed
        if (processes[min_burst_time_index].remaining_bt == 0) {
            processes[min_burst_time_index].ft = current_time; // Completion time
            processes[min_burst_time_index].tat = processes[min_burst_time_index].ft - processes[min_burst_time_index].at; // TAT = CT - AT
            processes[min_burst_time_index].wat = processes[min_burst_time_index].tat - processes[min_burst_time_index].bt; // WT = TAT - BT
            total_tat += processes[min_burst_time_index].tat;
            total_wat += processes[min_burst_time_index].wat;
            completed++;
        }
    }

    // Print the table with process details
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].job, processes[i].at, processes[i].bt, processes[i].ft, processes[i].tat, processes[i].wat);
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / num_processes);
    printf("Average Waiting Time: %.2f\n", (float)total_wat / num_processes);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process processes[num_processes];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].at);
        printf("Burst Time: ");
        scanf("%d", &processes[i].bt);
        processes[i].job = i + 1;
        processes[i].ft = 0;
        processes[i].tat = 0;
        processes[i].wat = 0;
        processes[i].remaining_bt = processes[i].bt;
    }

    calculate_sjf_preemptive_scheduling(processes, num_processes);

    return 0;
}
