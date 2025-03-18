#include <stdio.h>
#include <conio.h>
int main()
{
    int process[20], burstTime[20], waitingTime[20], turnaroundTime[20];
    int i, j, numProcesses, temp;
    float avgWaitingTime, avgTurnaroundTime;
    printf("\nEnter the number of processes -- ");
    scanf("%d", &numProcesses);
    for (i = 0; i < numProcesses; i++)
    {
        process[i] = i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &burstTime[i]);
    }
    for (i = 0; i < numProcesses; i++)
    {
        for (j = i + 1; j < numProcesses; j++)
        {
            if (burstTime[i] > burstTime[j])
            {
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }
    waitingTime[0] = avgWaitingTime = 0;
    turnaroundTime[0] = avgTurnaroundTime = burstTime[0];
    for (i = 1; i < numProcesses; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
        turnaroundTime[i] = turnaroundTime[i - 1] + burstTime[i];
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < numProcesses; i++)
    {
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", process[i], burstTime[i], waitingTime[i],
               turnaroundTime[i]);
    }
    printf("\nAverage Waiting Time -- %f", avgWaitingTime / numProcesses);
    printf("\nAverage Turnaround Time -- %f", avgTurnaroundTime / numProcesses);
    return 0;
}
