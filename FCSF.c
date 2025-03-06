#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], waiting[n], turnaround[n], completion[n];
    
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    int currentTime = 0;
    float totalWaiting = 0, totalTurnaround = 0;

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        if (currentTime < arrival[i])
            currentTime = arrival[i];  

        completion[i] = currentTime + burst[i];
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];

        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];

        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, arrival[i], burst[i], waiting[i], turnaround[i]);

        currentTime = completion[i];  
    }

    printf("\nAverage Waiting Time: %.2f", totalWaiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaround / n);

    return 0;
}