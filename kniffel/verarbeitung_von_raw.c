// current = 10000*a + 1000*b + 100*c + 10*d + e;
            // AllPossibilitiesNoRepeats[count - 1] = current;
            // count = count + 1;

#include <stdio.h>
#include <stdlib.h>

int i = 0;
int howManyTimesWrittenIntoArray;
int AllPossibilities[7776]; 
int AllPossibilitiesSorted[7776]; 
int AllPossibilitiesNoRepeats[300];
int count;

void getDigits();
int compareInts();

int main() {

    FILE *raw = fopen("raw_data.txt", "r");
        if (raw == NULL) {
            printf("failed to open file + youre fat\n");
            return 1;
        }

    while (fscanf(raw, "%d", &AllPossibilities[i]) == 1) // "while fscanf reads %d one line at a time and stores them at &AllPossib. at the index i is still working/true/1 then i++"
    {
        i++;
    }
    
    fclose(raw);

//------------------------ sorting rolls (small to big)


    int digits[5];                                // for storing als übergang
    
    // transfers ints from AllPoss. to AllpossSorted and sorts them smallest --> along the way
    for (int n = 0; n < 7776; n++){
        int current = AllPossibilities[n];
        getDigits(current, digits);
        qsort(digits, 5, sizeof(int), compareInts);
        // array digits is now sorted from smallest to largest
        current = digits[0]*10000 + digits[1]*1000 + digits[2]*100 + digits[3]*10 + digits[4];
        AllPossibilitiesSorted[n] = current; 

    }

//------------------------ sorting dupes out


    AllPossibilitiesNoRepeats[0] = AllPossibilitiesSorted[0];     // must have a starting "value" to compare the second one to. 11111 doesnt repeat anyway
    howManyTimesWrittenIntoArray = 1;                             // we only need to check for repeats this many times
 

    // var is n-th Possibilitiy and duplicate Flag is set to 1, if a dupe is found
   for (int n = 0; n < 7776; n++) {
    int var = AllPossibilitiesSorted[n];
    int isDuplicateFlag = 0;

    for (int j = 0; j < howManyTimesWrittenIntoArray; j++) {
        if (var == AllPossibilitiesNoRepeats[j]) {
            isDuplicateFlag = 1;
            break;  // no need to check further if a dupe is found
        }
    }

    if (!isDuplicateFlag) {
        AllPossibilitiesNoRepeats[howManyTimesWrittenIntoArray] = var;
        howManyTimesWrittenIntoArray++;
    }
}

//------------------------ printing results/writing them into a file

    FILE *notraw = fopen("possibilities_no_repeats", "w");
    if (notraw == NULL) {
        printf("failed to open file but your mum still loves you (lets not talk bout dad)");
        return 1;
    }

    for (int i = 0; i < howManyTimesWrittenIntoArray; i++)
    {
        fprintf(notraw, "%d\n", AllPossibilitiesNoRepeats[i]);
    }

    
return 0;    
}



//------------------------ functions

void getDigits(int n, int digits[5]) {
    for (int i = 4; i >= 0; i--) {
        digits[i] = n % 10;
        n /= 10;
    }
}


int compareInts(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}