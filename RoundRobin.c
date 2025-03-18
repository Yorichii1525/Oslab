#include <stdio.h>
int main()
{
    int process[10], burstTime[10], waitingTime[10], turnaroundTime[10],
        remainingTime[10];
    int i, j, numProcesses, timeSlice, maxBurstTime;
    float avgWaitingTime = 0, avgTurnaroundTime = 0, currentTime = 0;
    printf("Enter the number of processes -- ");
    scanf("%d", &numProcesses);
    for (i = 0; i < numProcesses; i++)
    {
        printf("\nEnter Burst Time for process %d -- ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];
    }
    printf("\nEnter the size of time slice -- ");
    scanf("%d", &timeSlice);
    maxBurstTime = burstTime[0];
    for (i = 1; i < numProcesses; i++)
    {
        if (maxBurstTime < burstTime[i])
        {
            maxBurstTime = burstTime[i];
        }
    }
    for (j = 0; j < (maxBurstTime / timeSlice) + 1; j++)
    {
        for (i = 0; i < numProcesses; i++)
        {
            if (remainingTime[i] != 0)
            {
                if (remainingTime[i] <= timeSlice)
                {
                    turnaroundTime[i] = currentTime + remainingTime[i];
                    currentTime += remainingTime[i];
                    remainingTime[i] = 0;
                }
                else
                {
                    remainingTime[i] -= timeSlice;
                    currentTime += timeSlice;
                }
            }
        }
    }
    for (i = 0; i < numProcesses; i++)
    {
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
        avgTurnaroundTime += turnaroundTime[i];
        avgWaitingTime += waitingTime[i];
    }
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < numProcesses; i++)
    {
        printf("\t%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i],
               turnaroundTime[i]);
    }
    printf("\nThe Average Turnaround time is -- %f", avgTurnaroundTime /
                                                         numProcesses);
    printf("\nThe Average Waiting time is --DS %f", avgWaitingTime /
                                                        numProcesses);
    return 0;
}
