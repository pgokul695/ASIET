#include <stdio.h>

void prfr(int frames[], int frame) {
    int i;
    printf("\tCurrent status of Frames: ");
    for (i = 0; i < frame; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n");
}

void lru(int frame, int page[], int n) {
    int i, j;
    int frames[frame];
    int last_used[frame];
    for (i = 0; i < frame; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    float pagefaults = 0, hits = 0;
    int found, lru_index;

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < frame; j++) {
            if (page[i] == frames[j]) {
                found = 1;
                hits++;
                last_used[j] = i;
                printf("Page %d is already in the frames: ", page[i]);
                prfr(frames, frame);
                break;
            }
        }

        if (!found) {
            pagefaults++;
            lru_index = 0;
            for (j = 1; j < frame; j++) {
                if (last_used[j] < last_used[lru_index]) {
                    lru_index = j;
                }
            }
            frames[lru_index] = page[i];
            last_used[lru_index] = i;
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

    lru(frame, page, n);
    return 0;
}

