#include <stdio.h>
#include <stdlib.h>

void printSeekSequence(int sequence[], int n, int init) {
    int i;
    printf("Seek Sequence: ");
    printf("%d -> ",init);
    for (i = 0; i < n - 1; i++) {
        printf("%d -> ", sequence[i]);
    }
    printf("%d\n", sequence[n - 1]);
}

void fcfs(int tracks[], int n, int initial, int totalCylinders) {
    int totalSeekDistance = 0, i;
    int seekSequence[n];
    int current = initial;
    seekSequence[0] = current;

    for (i = 0; i < n; i++) {
        if (tracks[i] < 0 || tracks[i] >= totalCylinders) {
            printf("Error: Disk request %d is out of bounds (valid range: 0 to %d).\n", tracks[i], totalCylinders - 1);
            return;
        }
    }

    for (i = 0; i < n; i++) {
        totalSeekDistance += abs(current - tracks[i]);
        current = tracks[i];
        seekSequence[i] = current;
    }

    float avgSeekDistance = (float)totalSeekDistance / n;

    printf("Total Seek Distance: %d\n", totalSeekDistance);
    printf("Average Seek Distance: %.2f\n", avgSeekDistance);
    printSeekSequence(seekSequence, n,initial);
}

int main() {
    int n, initial, totalCylinders, i;

    printf("Enter the number of cylinders: ");
    scanf("%d", &totalCylinders);

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int tracks[n];

    printf("Enter the disk requests (space-separated): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    if (initial < 0 || initial >= totalCylinders) {
        printf("Error: Initial head position is out of bounds (valid range: 0 to %d).\n", totalCylinders - 1);
        return 1;
    }

    fcfs(tracks, n, initial, totalCylinders);
    return 0;
}

