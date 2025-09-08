#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_INPUTS 8

struct entry {
    int response_num;
    double rating;
};

int comp(const void* a, const void* b);

int main(void) {
    while (1) {
        // prompts for rating for 1 2 3 4 5 6 7 8
        // prints out those ratings in Order of rating
        struct entry *entry_arr = malloc(NUM_OF_INPUTS * sizeof(struct entry));

        for (int i = 0; i < NUM_OF_INPUTS; i++) {
            entry_arr[i].response_num = i + 1;
            printf("Rate response     %d: ", i + 1);
            scanf(" %lf", &(entry_arr[i].rating));
            if (entry_arr[i].rating == -1) {
                return 0;
            }
        }

        qsort(entry_arr, 8, sizeof(struct entry), comp);
        printf("\n\n__________Sorted____________________________________\n\n");

        for (int i = 0; i < NUM_OF_INPUTS; i++) {
            printf("Response %d has rating %.1lf\n", entry_arr[i].response_num, entry_arr[i].rating);
        }

        printf("\n\n__________Prompt____________________________________\n\n");
    }
}

// Custom comparator
int comp(const void* a, const void* b) {

  	// If a is smaller, positive value will be returned
    return (((struct entry*)b)->rating- ((struct entry*)a)->rating);
}