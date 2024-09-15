#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int job;
    int at;
    int bt;
    int priority;
    int ft;
    int tat;
    int wat;
    int remaining_bt;
} Process;

void calculate_priority_preemptive_scheduling(Process processes[], int num_processes) {
    int current_time = 0;
    int total_tat = 0;
    int total_wat = 0;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        int max_priority_index = -1;
        int max_priority = -1;

        // Find the process with the highest priority
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].at <= current_time && processes[i].remaining_bt > 0 && processes[i].priority > max_priority) {
                max_priority = processes[i].priority;
                max_priority_index = i;
            }
        }

        if (max_priority_index == -1) {
            current_time++;
            continue;
        }

        // Execute the process with the highest priority for 1 unit of time
        processes[max_priority_index].remaining_bt--;
        current_time++;

        if (processes[max_priority_index].remaining_bt == 0) {
            processes[max_priority_index].ft = current_time;
            processes[max_priority_index].tat = processes[max_priority_index].ft - processes[max_priority_index].at;
            processes[max_priority_index].wat = processes[max_priority_index].tat - processes[max_priority_index].bt;
            total_tat += processes[max_priority_index].tat;
            total_wat += processes[max_priority_index].wat;
            completed_processes++;
        }
    }

    // Printing output table
    printf("\nJob | Arrival Time | Burst Time | Priority | Finish Time | Turnaround Time | Waiting Time\n");
    printf("--------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%-3d | %-12d | %-10d | %-8d | %-11d | %-15d | %-12d\n",
               processes[i].job,
               processes[i].at,
               processes[i].bt,
               processes[i].priority,
               processes[i].ft,
               processes[i].tat,
               processes[i].wat);
    }

    // Calculating and printing average wait time and turnaround time
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / num_processes);
    printf("Average Waiting Time: %.2f\n", (float)total_wat / num_processes);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process processes[num_processes];

    printf("\nFor each process, enter the following details:\n");
    printf("1. Arrival Time\n");
    printf("2. Burst Time\n");
    printf("3. Priority\n\n");

    for (int i = 0; i < num_processes; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].at);
        printf("Burst Time: ");
        scanf("%d", &processes[i].bt);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].job = i + 1;
        processes[i].ft = 0;
        processes[i].tat = 0;
        processes[i].wat = 0;
        processes[i].remaining_bt = processes[i].bt;
        printf("\n");
    }

    calculate_priority_preemptive_scheduling(processes, num_processes);

    return 0;
}
