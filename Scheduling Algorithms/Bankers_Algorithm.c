
#include <stdio.h>
#include <stdbool.h>

struct nikhil_process_info
{
    int max_1523[10];
    int allocated_1523[10];
    int need_1523[10];
};

int no_of_process_1523, no_of_resources_1523;

void input(struct nikhil_process_info process_1523[no_of_process_1523], int available_1523[no_of_resources_1523])
{

    for (int i = 0; i < no_of_process_1523; i++)
    {
        printf("Enter process_1523[%d] info\n", i);
        printf("Enter Maximum Need: ");
        for (int j = 0; j < no_of_resources_1523; j++)
            scanf("%d", &process_1523[i].max_1523[j]);
        printf("Enter No. of Allocated Resources for this process_1523: ");
        for (int j = 0; j < no_of_resources_1523; j++)
        {
            scanf("%d", &process_1523[i].allocated_1523[j]);

            process_1523[i].need_1523[j] = process_1523[i].max_1523[j] - process_1523[i].allocated_1523[j];
        }
    }
    printf("Enter Available Resources: ");
    for (int i = 0; i < no_of_resources_1523; i++)
    {
        scanf("%d", &available_1523[i]);
    }
}

void showTheInfo(struct nikhil_process_info process_1523[no_of_process_1523])
{
    printf("\nPID\tMaximum\t\tAllocated\tNeed\n");
    for (int i = 0; i < no_of_process_1523; i++)
    {
        printf("P[%d]\t", i);
        for (int j = 0; j < no_of_resources_1523; j++)
            printf("%d ", process_1523[i].max_1523[j]);
        printf("\t\t");
        for (int j = 0; j < no_of_resources_1523; j++)
            printf("%d ", process_1523[i].allocated_1523[j]);
        printf("\t\t");
        for (int j = 0; j < no_of_resources_1523; j++)
            printf("%d ", process_1523[i].need_1523[j]);
        printf("\n");
    }
}

bool applySafetyAlgo(struct nikhil_process_info process_1523[no_of_process_1523], int available_1523[no_of_resources_1523], int safeSequence_1523[no_of_process_1523])
{
    bool finish_1523[no_of_process_1523];
    int work_1523[no_of_resources_1523];
    for (int i = 0; i < no_of_resources_1523; i++)
    {
        work_1523[i] = available_1523[i];
    }
    for (int i = 0; i < no_of_process_1523; i++)
        finish_1523[i] = false;
    bool proceed_1523 = true;
    int k = 0;
    while (proceed_1523)
    {
        proceed_1523 = false;
        for (int i = 0; i < no_of_process_1523; i++)
        {
            bool flag_1523 = true;

            if (finish_1523[i] == false)
            {

                for (int j = 0; j < no_of_resources_1523; j++)
                {

                    if (process_1523[i].need_1523[j] <= work_1523[j])
                    {
                        continue;
                    }
                    else
                    {
                        flag_1523 = false;
                        break;
                    }
                }
                if (flag_1523 == false)
                    continue;

                for (int j = 0; j < no_of_resources_1523; j++)
                    work_1523[j] = work_1523[j] + process_1523[i].allocated_1523[j];
                finish_1523[i] = true;
                safeSequence_1523[k++] = i;
                proceed_1523 = true;
            }
        }
    }

    int i;
    for (i = 0; i < no_of_process_1523 && finish_1523[i] == true; i++)
    {
        continue;
    }

    if (i == no_of_process_1523)
        return true;
    else
        return false;
}

bool isSafeState(struct nikhil_process_info process_1523[no_of_process_1523], int available_1523[no_of_resources_1523], int safeSequence_1523[no_of_process_1523])
{

    if (applySafetyAlgo(process_1523, available_1523, safeSequence_1523) == true)
        return true;
    return false;
}

int main()
{
    printf("Enter No of Process\n");
    scanf("%d", &no_of_process_1523);
    printf("Enter No of Resource Instances in system\n");
    scanf("%d", &no_of_resources_1523);
    int available_1523[no_of_resources_1523];
    int safeSequence_1523[no_of_process_1523];

    struct nikhil_process_info process_1523[no_of_process_1523];

    printf("***********Enter details of processes*************\n");

    input(process_1523, available_1523);

    showTheInfo(process_1523);
    if (isSafeState(process_1523, available_1523, safeSequence_1523))
    {

        printf("\nSystem is in SAFE State\n");
        printf("Safe Sequence is: ");
        for (int i = 0; i < no_of_process_1523; i++)
            printf("P[%d] ", safeSequence_1523[i]);
        printf("1");
    }
    else
        printf("0");
    return 0;
}