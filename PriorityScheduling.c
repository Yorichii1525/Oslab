#include <stdio.h>

int main() {
    int process[20], burstTime[20], priority[20], waitingTime[20], turnaroundTime[20];
    int i, j, numProcesses, temp;
    float avgWaitingTime = 0, avgTurnaroundTime = 0;

    // Taking input for number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    // Taking burst time and priority for each process
    for (i = 0; i < numProcesses; i++) {
        process[i] = i + 1;  // Process IDs start from 1
        printf("Enter Burst Time & Priority of Process %d: ", i + 1);
        scanf("%d %d", &burstTime[i], &priority[i]);
    }

    // Sorting based on Priority (Ascending Order)
    for (i = 0; i < numProcesses - 1; i++) {
        for (j = i + 1; j < numProcesses; j++) {
            if (priority[i] > priority[j]) {  // Lower number = higher priority
                // Swap Process ID
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;

                // Swap Burst Time
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                // Swap Priority
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }

    // Calculating Waiting & Turnaround Time
    waitingTime[0] = 0;
    turnaroundTime[0] = burstTime[0];
    avgTurnaroundTime = turnaroundTime[0];

    for (i = 1; i < numProcesses; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }

    // Printing Results
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < numProcesses; i++) {
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d", 
            process[i], priority[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    // Printing Averages
    printf("\nAverage Waiting Time: %.2f", avgWaitingTime / numProcesses);
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime / numProcesses);

    return 0;
}
