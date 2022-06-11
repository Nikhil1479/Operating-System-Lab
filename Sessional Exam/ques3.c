#include <stdio.h>
struct process
{
    int WT, AT, BT, TAT, PT, CT;
};

struct process p[10];

int main()
{
    int n, temp[10], curr_time, count = 0, last_p;
    float total_WT = 0, total_TAT = 0, Avg_WT, Avg_TAT, total_CT;
    printf("Enter the number of the process\n");
    scanf("%d", &n);
    printf("Enter the arrival time , burst time and priority of the process\n");
    printf("Arrival Time Burst Time Priority\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &p[i].AT, &p[i].BT, &p[i].PT);

        temp[i] = p[i].BT;
    }

    p[9].PT = 9999;

    for (curr_time = 0; count != n; curr_time++)
    {
        last_p = 9;
        for (int i = 0; i < n; i++)
        {
            // Comparing Priorites of the processes
            if (p[last_p].PT > p[i].PT && p[i].AT <= curr_time && p[i].BT > 0)
            {
                last_p = i;
            }
        }

        p[last_p].BT = p[last_p].BT - 1;

        if (p[last_p].BT == 0)
        {

            count++;
            p[last_p].WT = curr_time + 1 - p[last_p].AT - temp[last_p];
            p[last_p].TAT = curr_time + 1 - p[last_p].AT;

            total_WT = total_WT + p[last_p].WT;
            total_TAT = total_TAT + p[last_p].TAT;
            p[last_p].CT = curr_time + 1;
        }
    }

    Avg_WT = total_WT / n;
    Avg_TAT = total_TAT / n;

    printf("ID\tAT\tWT\tTAT\tPR\tCT \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, p[i].AT, p[i].WT, p[i].TAT, p[i].PT, p[i].CT);
    }

    printf("Average waiting time of the process  is %f\n", Avg_WT);
    printf("Average turn around time of the process is %f\n", Avg_TAT);

    return 0;
}