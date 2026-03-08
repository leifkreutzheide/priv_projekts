#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROLLS  100000000
#define NUM_DICE   5

// ─────────────────────────────────────────
// comparator for qsort
// ─────────────────────────────────────────

int compareInts(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// ─────────────────────────────────────────
// roll 5 dice and store sorted into row[]
// ─────────────────────────────────────────

void rollAndSort(int row[NUM_DICE]) {
    for (int i = 0; i < NUM_DICE; i++) {
        row[i] = (rand() % 6) + 1;
    }
    qsort(row, NUM_DICE, sizeof(int), compareInts);
}

// ─────────────────────────────────────────
// check if a sorted row contains a triple
// checks positions [0-2], [1-3], [2-4]
// ─────────────────────────────────────────

int hasTriple(int row[NUM_DICE]) {
    if (row[0] == row[1] && row[1] == row[2]) return 1;
    if (row[1] == row[2] && row[2] == row[3]) return 1;
    if (row[2] == row[3] && row[3] == row[4]) return 1;
    return 0;
}

// ─────────────────────────────────────────
// main
// ─────────────────────────────────────────

int main() {

    srand(time(NULL));

   int (*rolls)[NUM_DICE] = malloc(NUM_ROLLS * sizeof(*rolls));
if (rolls == NULL) {
    printf("malloc failed\n");
    return 1;
}
    int tripleCount = 0;

    for (int i = 0; i < NUM_ROLLS; i++) {
        rollAndSort(rolls[i]);
        if (hasTriple(rolls[i])) {
            tripleCount++;
        }
    }

    printf("Triples found in %d rolls: %d\n", NUM_ROLLS, tripleCount);
    printf("Percentage: %.4f%%\n", (double)tripleCount / NUM_ROLLS * 100);

    free(rolls);
    return 0;
}
