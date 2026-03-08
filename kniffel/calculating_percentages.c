#include <stdio.h>
#include <stdlib.h>

void getDigits(int n, int possibilities[5]);

//---------------- all subsets and their counters
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

//--------------------- arrays and such
int possibilities[252];
int arr²[252][5]; // arr²[row][column]. arr²[i] gives a 5 digit array that lies at the i-th row
int i = 0;

//----------------------- function declarations

void printHowManyElementsPerSubset(int k, int gs, int ks, int fh, int t, int q, int o);

void printProbabilitiesOfEachSubsetOccuring(int k, int gs, int ks, int fh, int t, int q, int o, int numberOfPossibilities);

void printAllElements(int *kniffel, int k, int *großeStraße, int gs, int *kleineStraße, int ks,
                      int *fullHouse, int fh, int *quad, int q, int *triple, int t, int *other, int o);

void sortingIntoSubsets(int arr²[][5], int j,
                        int *kniffel,  int *k,
                        int *großeStraße, int *gs,
                        int *kleineStraße, int *ks,
                        int *fullHouse, int *fh,
                        int *quad, int *q,
                        int *triple, int *t,
                        int *other, int *o);

//-------------------------- main ()

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

    sortingIntoSubsets(arr², j, kniffel, &k, großeStraße, &gs, kleineStraße, &ks,
                   fullHouse, &fh, quad, &q, triple, &t, other, &o);
    }

//---------------------------- different printing options

    //printHowManyElementsPerSubset(k, gs, ks, fh, t, q, o);
    printProbabilitiesOfEachSubsetOccuring(k, gs, ks, fh, t, q, o, numberOfPossibilities);
    //printAllElements(kniffel, k, großeStraße, gs, kleineStraße, ks, fullHouse, fh, quad, q, triple, t, other, o);

return 0;
}


//-------------------------------------- function bodies

void getDigits(int n, int possibilities[252]) { // getDigits take in an int n (the to-be-chopped-up int) and an Array to which the chopped parts will be passed to (passed by reference automatically bc its an array).
    for (int i = 4; i >= 0; i--) { // i is last index from the Array. 
        possibilities[i] = n % 10; // possibilities[i] = ... writes directly into my original array. with the modulo operator % -->  Dividing any integer by 10 always leaves the rightmost digit as the remainder
        n = n/10; //n = n/10 chops of the right most digit entierly (remainders are discarded)
    }
}



void printHowManyElementsPerSubset(int k, int gs, int ks, int fh, int t, int q, int o) {
    printf("there are %d elements in kniffel[]\n", k);
    printf("there are %d elements in großeStraße[]\n", gs);
    printf("there are %d elements in kleineStraße[]\n", ks);
    printf("there are %d elements in fullhouse[]\n", fh);
    printf("there are %d elements in triple[]\n", t);
    printf("there are %d elements in quad[]\n", q);
    printf("there are %d elements in other[]\n", o);}


void printProbabilitiesOfEachSubsetOccuring(int k, int gs, int ks, int fh, int t, int q, int o, int numberOfPossibilities) {
    printf("\nall probalities are given as percent of that given type occuring if all 5 die are rolled\n");
    printf("kniffel has a probability of: %.2f\n",       ((double)k  / numberOfPossibilities) * 100);
    printf("große Straße has a probability of: %.2f\n",  ((double)gs / numberOfPossibilities) * 100);
    printf("kleine Straße has a probability of: %.2f\n", ((double)ks / numberOfPossibilities) * 100);
    printf("full house has a probability of: %.2f\n",    ((double)fh / numberOfPossibilities) * 100);
    printf("4er pasch has a probability of: %.2f\n",     ((double)q  / numberOfPossibilities) * 100);
    printf("3er pasch has a probability of: %.2f\n",     ((double)t  / numberOfPossibilities) * 100);
    printf("other has a probability of: %.2f\n",         ((double)o  / numberOfPossibilities) * 100); }


void printAllElements(int *kniffel, int k, int *großeStraße, int gs, int *kleineStraße, int ks,
                      int *fullHouse, int fh, int *quad, int q, int *triple, int t, int *other, int o) {

    printf("\nall würfel possibilities for kniffel (%d):\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d\n", kniffel[i]); }

    printf("\nall würfel possibilities for große Straße (%d):\n", gs);
    for (int i = 0; i < gs; i++) {
        printf("%d\n", großeStraße[i]); }

    printf("\nall würfel possibilities for kleine Straße (%d):\n", ks);
    for (int i = 0; i < ks; i++) {
        printf("%d\n", kleineStraße[i]); }

    printf("\nall würfel possibilities for full house (%d):\n", fh);
    for (int i = 0; i < fh; i++) {
        printf("%d\n", fullHouse[i]); }

    printf("\nall würfel possibilities for 4er pasch (%d):\n", q);
    for (int i = 0; i < q; i++) {
        printf("%d\n", quad[i]); }

    printf("\nall würfel possibilities for 3er pasch (%d):\n", t);
    for (int i = 0; i < t; i++) {
        printf("%d\n", triple[i]); }

    printf("\nall other würfel possibilities (%d):\n", o);
    for (int i = 0; i < o; i++) {
        printf("%d\n", other[i]); }       }

void sortingIntoSubsets(int arr²[][5], int j,
                        int *kniffel,  int *k,
                        int *großeStraße, int *gs,
                        int *kleineStraße, int *ks,
                        int *fullHouse, int *fh,
                        int *quad, int *q,
                        int *triple, int *t,
                        int *other, int *o) {

    int otherFlag = 1;
    int val = 10000*arr²[j][0] + 1000*arr²[j][1] + 100*arr²[j][2] + 10*arr²[j][3] + arr²[j][4];

    // kniffel (all the same)
    if (arr²[j][0] == arr²[j][1] && arr²[j][1] == arr²[j][2] &&
        arr²[j][2] == arr²[j][3] && arr²[j][3] == arr²[j][4]) {
        kniffel[(*k)++] = val;
        otherFlag = 0; }

    // große Straße (5 ascending)
    if (arr²[j][0]+1 == arr²[j][1] && arr²[j][1]+1 == arr²[j][2] &&
        arr²[j][2]+1 == arr²[j][3] && arr²[j][3]+1 == arr²[j][4]) {
        großeStraße[(*gs)++] = val;
        otherFlag = 0; }

    // kleine Straße (4 ascending)
    if ((arr²[j][0]+1 == arr²[j][1] && arr²[j][1]+1 == arr²[j][2] && arr²[j][2]+1 == arr²[j][3]) ||
        (arr²[j][1]+1 == arr²[j][2] && arr²[j][2]+1 == arr²[j][3] && arr²[j][3]+1 == arr²[j][4])) {
        kleineStraße[(*ks)++] = val;
        otherFlag = 0; }

    // full house (xxyyy or xxxxy)
    if ((arr²[j][0] == arr²[j][1] && arr²[j][1] != arr²[j][2] &&
         arr²[j][2] == arr²[j][3] && arr²[j][3] == arr²[j][4]) ||
        (arr²[j][0] == arr²[j][1] && arr²[j][1] == arr²[j][2] &&
         arr²[j][2] != arr²[j][3] && arr²[j][3] == arr²[j][4])) {
        fullHouse[(*fh)++] = val;
        otherFlag = 0; }

    // 4er Pasch
    if ((arr²[j][0] == arr²[j][1] && arr²[j][1] == arr²[j][2] && arr²[j][2] == arr²[j][3]) ||
        (arr²[j][1] == arr²[j][2] && arr²[j][2] == arr²[j][3] && arr²[j][3] == arr²[j][4])) {
        quad[(*q)++] = val;
        otherFlag = 0; }

    // 3er Pasch
    if ((arr²[j][0] == arr²[j][1] && arr²[j][1] == arr²[j][2]) ||
        (arr²[j][1] == arr²[j][2] && arr²[j][2] == arr²[j][3]) ||
        (arr²[j][2] == arr²[j][3] && arr²[j][3] == arr²[j][4])) {
        triple[(*t)++] = val;
        otherFlag = 0; }

    // other
    if (otherFlag) {
        other[(*o)++] = val;
    }   }