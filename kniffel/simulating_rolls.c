#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROLLS  1000
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
        row[i] = (rand() % 6) + 1;   // random int 1-6
    }
    qsort(row, NUM_DICE, sizeof(int), compareInts);
}

// ─────────────────────────────────────────
// main
// ─────────────────────────────────────────

int main() {

    // seed the random number generator with current time
    // without this, rand() produces the same sequence every run
    srand(time(NULL));

    int rolls[NUM_ROLLS][NUM_DICE];

    for (int i = 0; i < NUM_ROLLS; i++) {
        rollAndSort(rolls[i]);
    }

    // print all rolls to verify
    printf("1000 simulated dice rolls (sorted ascending):\n\n");
    for (int i = 0; i < NUM_ROLLS; i++) {
        printf("Roll %4d: %d %d %d %d %d\n", i + 1,
               rolls[i][0], rolls[i][1], rolls[i][2],
               rolls[i][3], rolls[i][4]);
    }

    return 0;
}