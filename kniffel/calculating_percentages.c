#include <stdio.h>
#include <stdlib.h>

void getDigits(int n, int possibilities[5]);

// all subsets and their counters
int kniffel[6] = {0};
int k = 0; 
int großeStraße[50] = {0};
int gs = 0; 
int kleineStraße[50] = {0};
int ks = 0; 
int fullHouse[60] = {0};
int fh = 0; 
int triple[250] = {0};
int t = 0; 
int quad[60] = {0};
int q = 0; 
int other[200] = {0};
int o = 0; 
double numberOfPossibilities = 252;

int possibilities[252];
int arr²[252][5]; // arr²[row][column]. arr²[i] gives a 5 digit array that lies at the i-th row
int i = 0;

int main() {

//----------------------------- reading possibilities out of file

FILE *ptr = fopen("possibilities_no_repeats.txt", "r");
        if (ptr == NULL) {
            printf("failed to open file + youre fat\n");
            return 1; }

    while (fscanf(ptr, "%d", &possibilities[i]) == 1) // "while (fscanf reads %d (one line at a time) and stores them @ &possibilites at index i) is still working/true/1 then i++"
    {
        i++;
    } fclose(ptr);

//----------------------------- creating a 2D array out of a 1D array

for (int n = 0; n < 252; n++) {
    getDigits(possibilities[n], arr²[n]);
}

//----------------------------- sorting all possibilities into their subsets

for (int j = 0; j < 252; j++){

    int otherFlag = 1;

    // kniffel (all the same)
    if (arr²[j][0] == arr²[j][1] && arr²[j][1] == arr²[j][2] && arr²[j][2] == arr²[j][3] && arr²[j][3] == arr²[j][4]) {
        kniffel[k] = 10000*arr²[j][0] + 1000*arr²[j][1] + 100*arr²[j][2] + 10*arr²[j][3] + arr²[j][4];
        k++;
        otherFlag = 0; }

    // große Straße (5 in ascending order)
    if (arr²[j][0] + 1 == arr²[j][1] && arr²[j][1] + 1  == arr²[j][2] && arr²[j][2] + 1  == arr²[j][3] && arr²[j][3] + 1 == arr²[j][4]) {
        großeStraße[gs] = 10000*arr²[j][0] + 1000*arr²[j][1] + 100*arr²[j][2] + 10*arr²[j][3] + arr²[j][4];
        gs++;
        otherFlag = 0; }

    // kleine Straße  (4 in ascending order)
     if ((arr²[j][0] + 1 == arr²[j][1] && arr²[j][1] + 1  == arr²[j][2] && arr²[j][2] + 1  == arr²[j][3]) || (arr²[j][1] + 1  == arr²[j][2] && arr²[j][2] + 1  == arr²[j][3] && arr²[j][3] + 1 == arr²[j][4])) {
        kleineStraße[gs] = 10000*arr²[j][0] + 1000*arr²[j][1] + 100*arr²[j][2] + 10*arr²[j][3] + arr²[j][4];
        ks++; 
        otherFlag = 0; }

    // full house (xxyyy)
    if ((arr²[j][0] == arr²[j][1] && arr²[j][1] != arr²[j][2] && arr²[j][2] == arr²[j][3] && arr²[j][3] == arr²[j][4])  ||  (arr²[j][0] == arr²[j][1] && arr²[j][1] == arr²[j][2] && arr²[j][2] != arr²[j][3] && arr²[j][3] == arr²[j][4])){
        fullHouse[fh] = 10000*arr²[j][0] + 1000*arr²[j][1] + 100*arr²[j][2] + 10*arr²[j][3] + arr²[j][4];
        fh++;
        otherFlag = 0; }

    // 4er Pasch (quad/4 of a kind)
    if ((arr²[j][0] == arr²[j][1] && arr²[j][1] == arr²[j][2] && arr²[j][2] == arr²[j][3])  ||
        (arr²[j][1] == arr²[j][2] && arr²[j][2] == arr²[j][3] && arr²[j][3] == arr²[j][4]) ) {
        quad[q] = 10000*arr²[j][0] + 1000*arr²[j][1] + 100*arr²[j][2] + 10*arr²[j][3] + arr²[j][4];
        q++;
        otherFlag = 0; }

    // 3er Pasch (triple/3 of a kind)
    if ((arr²[j][0] == arr²[j][1] && arr²[j][1] == arr²[j][2])  ||
        (arr²[j][1] == arr²[j][2] && arr²[j][2] == arr²[j][3])  ||
        (arr²[j][2] == arr²[j][3] && arr²[j][3] == arr²[j][4])  ) {
        triple[t] = 10000*arr²[j][0] + 1000*arr²[j][1] + 100*arr²[j][2] + 10*arr²[j][3] + arr²[j][4];
        t++;
        otherFlag = 0; }

    // if of no relevance
    if (otherFlag)
    {
        other[o] = 10000*arr²[j][0] + 1000*arr²[j][1] + 100*arr²[j][2] + 10*arr²[j][3] + arr²[j][4];
        o++;
    } else {
        continue;
    }

    // could add an if for a pair because they are common and it is common to "build" up from them; but since they have no game scored i will disregard atm atm
    
    
}

    /*
    printf("there are %d elements in kniffel[]\n", k);
    printf("there are %d elements in großeStraße[]\n", gs);
    printf("there are %d elements in kleineStraße[]\n", ks);
    printf("there are %d elements in fullhouse[]\n", fh);
    printf("there are %d elements in triple[]\n", t);
    printf("there are %d elements in quad[]\n", q);
    printf("there are %d elements in other[]\n", o);
    printf("that brings the total number of elements to: k + gs + ks + fh + t + q + o = %d\n", (k + gs + ks + fh + t + q + o));
    //printf("%d%d%d%d%d\n", kniffel[0], kniffel[0][1], kniffel[0][2], kniffel[0][3], kniffel[0][4]); 
    */

    printf("double k = %d and numberofposs. = %d", (double)k, numberOfPossibilities);
    printf("\nkniffel has a possibility of: %d.6f\n", (((double)k / numberOfPossibilities))*100);
    printf("große Straße has a possibility of: %d.6f\n", (((double)gs / numberOfPossibilities))*100);
    printf("kleine Straße has a possibility of: %d.6f\n", (((double)ks / numberOfPossibilities))*100);
    printf("full house has a possibility of: %d.6f\n", (((double)fh / numberOfPossibilities))*100);
    printf("4er pasch has a possibility of: %d.6f\n", (((double)q / numberOfPossibilities))*100);
    printf("3er pasch has a possibility of: %d.6f\n", (((double)t / numberOfPossibilities))*100);
    printf("all other irrelevant rolls have a possibility of: %d.6f\n", (((double)o / numberOfPossibilities))*100);

    /*
    printf("\nall würfel possibilities for kniffel (%d):\n", k);
    for (int i = 0; i < k; i++) {
    printf("%d\n", kniffel[i]);}

    printf("\all würfel possibilities for große Straße (%d):\n", gs);
    for (int i = 0; i < gs; i++) {
    printf("%d\n", großeStraße[i]);}

    printf("\nall würfel possibilities for kleine Straße (%d): \n", ks);
    for (int i = 0; i < ks; i++) {
    printf("%d\n", kleineStraße[i]);}

    printf("\nall würfel possibilities for full house (%d): \n", fh);
    for (int i = 0; i < fh; i++) {
    printf("%d\n", fullHouse[i]);}

    printf("\nall würfel possibilities for 4er pasch (%d): \n", q);
    for (int i = 0; i < q; i++) {
    printf("%d\n", quad[i]);

    printf("\nall würfel possibilities for 3er pasch (%d):\n", t);
    for (int i = 0; i < t; i++) {
    printf("%d\n", triple[i]);}

    printf("\nall other würfel possibilities (%d): \n", o);
    for (int i = 0; i < o; i++) {
    printf("%d\n", other[i]);}
    */

return 0;
}





// getDigits take in an int n (the to-be-chopped-up int) and an Array to which the chopped parts will be passed to (passed by reference automatically bc its an array).
// i is last index from the Array. 
// digits[i] = ... writes directly into my original array.
// digits are extraced right to left. LSB to MSB
// with the modulo operator % -->  Dividing any integer by 10 always leaves the rightmost digit as the remainder:
// n = n/10 chops of the right most digit entierly (remainders are discarded)
//
//

void getDigits(int n, int possibilities[252]) {
    for (int i = 4; i >= 0; i--) {
        possibilities[i] = n % 10;
        n = n/10;
    }
}