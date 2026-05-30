#include <stdio.h>
#include <stdlib.h>

// Structure to represent an event
typedef struct {
    int start;
    int end;
} Event;

// Comparator function for sorting by end time
int compare(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;
    return e1->end - e2->end;
}

int main() {
    int n;

    printf("Enter number of events: ");
    scanf("%d", &n);

    Event events[n];

    printf("Enter start and end time of each event:\n");

    // Input with validation
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &events[i].start, &events[i].end);

        // Fix invalid input automatically
        if (events[i].start > events[i].end) {
            printf("Invalid event (%d, %d). Swapping values.\n",
                   events[i].start, events[i].end);

            int temp = events[i].start;
            events[i].start = events[i].end;
            events[i].end = temp;
        }
    }

    // Step 1: Sort events by end time
    qsort(events, n, sizeof(Event), compare);

    // Step 2: Select non-overlapping events
    int count = 0;
    int last_end = -1;

    printf("\nSelected events:\n");

    for (int i = 0; i < n; i++) {
        if (events[i].start >= last_end) {
            printf("(%d, %d)\n", events[i].start, events[i].end);
            last_end = events[i].end;
            count++;
        }
    }

    printf("\nMaximum number of non-overlapping events: %d\n", count);

    return 0;
}