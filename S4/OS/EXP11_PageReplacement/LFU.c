#include <stdio.h>

void prfr(int frames[], int frame) {
    int i;
    printf("\tCurrent status of Frames: ");
    for (i = 0; i < frame; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n");
}

void lfu(int frame, int page[], int n) {
    int i, j;
    int frames[frame];
    int frequency[frame];
    int last_used[frame];

    for (i = 0; i < frame; i++) {
        frames[i] = -1;
        frequency[i] = 0;
        last_used[i] = -1;
    }

    float pagefaults = 0, hits = 0;
    int found, lfu_index;

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < frame; j++) {
            if (page[i] == frames[j]) {
                found = 1;
                hits++;
                frequency[j]++;
                last_used[j] = i;
                printf("Page %d is already in the frames: ", page[i]);
                prfr(frames, frame);
                break;
            }
        }

        if (!found) {
            pagefaults++;
            lfu_index = 0;
            for (j = 1; j < frame; j++) {
                if (frequency[j] < frequency[lfu_index] || (frequency[j] == frequency[lfu_index] && last_used[j] < last_used[lfu_index])) {
                    lfu_index = j;
                }
            }
            frames[lfu_index] = page[i];
            frequency[lfu_index] = 1;
            last_used[lfu_index] = i;
            printf("Page %d loaded into frames: ", page[i]);
            prfr(frames, frame);
        }
    }

    printf("Total Page Faults: %.0f\n", pagefaults);
    printf("Total Hits: %.0f\n", hits);
    printf("Miss Ratio: %.2f\n", pagefaults / n);
    printf("Hit Ratio: %.2f\n", hits / n);
}

int main() {
    int i, n, frame, page[100];
    printf("Enter the Number of Frames: ");
    scanf("%d", &frame);

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string (space-separated): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    lfu(frame, page, n);
    return 0;
}

