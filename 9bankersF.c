#include <stdio.h>

int main() {
    int numProcesses, numResources;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the number of resources: ");
    scanf("%d", &numResources);

    int max[numProcesses][numResources];
    int allocation[numProcesses][numResources];
    int available[numResources];
    int need[numProcesses][numResources];

    printf("Enter maximum resources for each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter allocated resources for each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("Enter available resources:\n");
    for (int i = 0; i < numResources; i++) {
        scanf("%d", &available[i]);
    }

    // Check if the system is in a safe state
    int work[numResources];
    int finish[numProcesses];

    for (int i = 0; i < numResources; i++) {
        work[i] = available[i];
    }

    for (int i = 0; i < numProcesses; i++) {
        finish[i] = 0;
    }

    int safeSequence[numProcesses];
    int count = 0;

    while (count < numProcesses) {
        int found = 0;

        for (int i = 0; i < numProcesses; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < numResources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == numResources) {
                    for (int k = 0; k < numResources; k++) {
                        work[k] += allocation[i][k];
                    }

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("System is not in a safe state.\n");
            return 0;
        }
    }

    printf("System is in a safe state.\n");
    printf("Safe Sequence: ");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");

    return 0;
}
