#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Structure for process
struct P
{
    int AT, BT, WT, FT, TAT, pos;
};

int quant;

int main()
{
    int n, i, j;
    // Taking Input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct P p[n];

    printf("Enter the quantum time: ");
    scanf("%d", &quant);

    printf("Enter the process numbers: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &(p[i].pos));

    printf("Enter the Arrival times of processes: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &(p[i].AT));

    printf("Enter the Burst times of processes: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &(p[i].BT));

    // Declaring variables
    int c = n, s[n][20];
    float time = 0, mini = INT_MAX, b[n], a[n];

    // Initializing burst and arrival time arrays
    int index = -1;
    for (i = 0; i < n; i++)
    {
        b[i] = p[i].BT;
        a[i] = p[i].AT;
        for (j = 0; j < 20; j++)
        {
            s[i][j] = -1;
        }
    }

    int tot_wt = 0, tot_tat = 0;
    bool flag = false;

    while (c != 0)
    {
        mini = INT_MAX;
        flag = false;

        for (i = 0; i < n; i++)
        {
            float p = time + 0.1;
            if (a[i] <= p && mini > a[i] && b[i] > 0)
            {
                index = i;
                mini = a[i];
                flag = true;
            }
        }
        // If no process is ready, increment time
        if (!flag)
        {
            time++;
            continue;
        }

        // Calculating start time
        j = 0;
        while (s[index][j] != -1)
        {
            j++;
        }
        if (s[index][j] == -1)
        {
            s[index][j] = time;
        }

        if (b[index] <= quant)
        {
            time += b[index];
            b[index] = 0;
        }
        else
        {
            time += quant;
            b[index] -= quant;
        }

        if (b[index] > 0)
        {
            a[index] = time + 0.1;
        }

        // Calculating arrival, burst, final times
        if (b[index] == 0)
        {
            c--;
            p[index].FT = time;
            p[index].WT = p[index].FT - p[index].AT - p[index].BT;
            tot_wt += p[index].WT;
            p[index].TAT = p[index].BT + p[index].WT;
            tot_tat += p[index].TAT;
        }
    } // End of while loop

    // Printing output
    printf("\nProcess number | Arrival time | Burst time | Final time | Wait Time | TurnAround Time\n");
    printf("--------------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%-14d | %-12d | %-10d | %-10d | %-8d | %-14d\n", p[i].pos, p[i].AT, p[i].BT, p[i].FT, p[i].WT, p[i].TAT);
    }

    // Calculating average wait time and turnaround time
    double avg_wt = tot_wt / (float)n;
    double avg_tat = tot_tat / (float)n;

    // Printing average wait time and turnaround time
    printf("\nThe average wait time is: %.2lf\n", avg_wt);
    printf("The average Turnaround time is: %.2lf\n", avg_tat);

    return 0;
}
