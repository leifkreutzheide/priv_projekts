#include <stdio.h>
#include <stdlib.h>

#define allPossibilities 7776

int arr[allPossibilities] = {0};
int arrSorted[allPossibilities] = {0};
int twoDimArr[allPossibilities][5] = {0}; // 2Darr[row][column]. 2Darr[i] gives a 5 digit array that lies at the i-th row

int i = 0;
// int n = 0;
int kniffel = 0;
int großeStraße = 0;
int kleineStraße = 0;
int fullHouse = 0;
int triple = 0;
int quad = 0;
int other = 0;
int pair = 0;


void getDigits();
int compareInts();
void checkingWhatRoleWhatIs(int twoDimArr[allPossibilities][5], int n, int *kniffel, int *großeStraße, int *kleineStraße, int *fullHouse, int *triple, int *quad, int *other);

void main() {

    FILE *ptr = fopen("raw_data.txt", "r");
        if (ptr == NULL) {
            printf("failed to open file + youre fat\n");
             }

    while (fscanf(ptr, "%d", &arr[i]) == 1) // "while (fscanf reads %d (one line at a time) and stores them @ &possibilites at index i) is == working/true/1 then i++"
    {
        i++;
    } fclose(ptr);

    
//------------------------ sorting rolls (small to big)
    int digits[5];     // for storing als übergang
    
    // transfers ints from AllPoss[] to AllpossSorted[] and sorts digits smallest --> largest along the way
    for (int n = 0; n < 7776; n++){
        int current = arr[n];
        getDigits(current, digits);
        qsort(digits, 5, sizeof(int), compareInts);
        // array digits is now sorted from smallest to largest
        current = digits[0]*10000 + digits[1]*1000 + digits[2]*100 + digits[3]*10 + digits[4];
        arrSorted[n] = current; 

    }

    printf("%d\n", arrSorted[0]);
    printf("%d\n", arrSorted[7775]);
    printf("%d%d%d%d%d\n", twoDimArr[1][0], twoDimArr[1][1], twoDimArr[1][2], twoDimArr[1][3], twoDimArr[1][4]); 

//------------------------ transfering sorted rolls into 2D array (for easier access to single digits)

    for (int n = 0; n < allPossibilities; n++) {
    getDigits(arrSorted[n], twoDimArr[n]);
}

    printf("%d\n", arrSorted[0]);
    printf("%d\n", arrSorted[7775]);
    printf("%d%d%d%d%d\n", twoDimArr[2][0], twoDimArr[2][1], twoDimArr[2][2], twoDimArr[2][3], twoDimArr[2][4]);

//------------------------ checking what role what is and counting how many of each there are
    for (int n = 0; n < allPossibilities; n++)
    {
        checkingWhatRoleWhatIs(twoDimArr, n, &kniffel, &großeStraße, &kleineStraße, &fullHouse, &triple, &quad, &other);
    }
    
    
    printf("\nkniffel occurrences: %d (%.3f%%)\n", kniffel, (float)kniffel / allPossibilities * 100);
    printf("große Straße: %d (%.3f%%)\n", großeStraße, (float)großeStraße / allPossibilities * 100);
    printf("kleine Straße: %d (%.3f%%)\n", kleineStraße, (float)kleineStraße / allPossibilities * 100);
    printf("full house: %d (%.3f%%)\n", fullHouse, (float)fullHouse / allPossibilities * 100);
    printf("quad: %d (%.3f%%)\n", quad, (float)quad / allPossibilities * 100);
    printf("triple: %d (%.3f%%)\n", triple, (float)triple / allPossibilities * 100);
    printf("other: %d (%.3f%%)\n", other, (float)other / allPossibilities * 100);
    printf("total rolls: %d\n", kniffel + großeStraße + kleineStraße + fullHouse + triple + quad + other);

  
} //---------------------- end main 


//------------------------ function bodies

void getDigits(int n, int digits[5]) {
    for (int i = 4; i >= 0; i--) {
        digits[i] = n % 10; // get the last digit
        n /= 10;
    }
}

int compareInts(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void checkingWhatRoleWhatIs(int twoDimArr[][5], int n, int *kniffel, int *großeStraße, int *kleineStraße, int *fullHouse, int *triple, int *quad, int *other) {

    int otherFlag = 1;
    // int role = 10000*twoDimArr[n][0] + 1000*twoDimArr[n][1] + 100*twoDimArr[n][2] + 10*twoDimArr[n][3] + twoDimArr[n][4];

    // kniffel (all the same)
    if (twoDimArr[n][0] == twoDimArr[n][1] && twoDimArr[n][1] == twoDimArr[n][2] &&
        twoDimArr[n][2] == twoDimArr[n][3] && twoDimArr[n][3] == twoDimArr[n][4]) {
        (*kniffel)++;
        otherFlag = 0; }

    // große Straße (5 ascending)
    if (twoDimArr[n][0]+1 == twoDimArr[n][1] && twoDimArr[n][1]+1 == twoDimArr[n][2] &&
        twoDimArr[n][2]+1 == twoDimArr[n][3] && twoDimArr[n][3]+1 == twoDimArr[n][4]) {
        (*großeStraße)++;
        otherFlag = 0; }

    // kleine Straße (4 ascending)
    if ((twoDimArr[n][0]+1 == twoDimArr[n][1] && twoDimArr[n][1]+1 == twoDimArr[n][2] && twoDimArr[n][2]+1 == twoDimArr[n][3]) ||
        (twoDimArr[n][1]+1 == twoDimArr[n][2] && twoDimArr[n][2]+1 == twoDimArr[n][3] && twoDimArr[n][3]+1 == twoDimArr[n][4])) {
        (*kleineStraße)++;
        otherFlag = 0; }

    // full house (xxyyy or xxxxy)
    if ((twoDimArr[n][0] == twoDimArr[n][1] && twoDimArr[n][1] != twoDimArr[n][2] &&
         twoDimArr[n][2] == twoDimArr[n][3] && twoDimArr[n][3] == twoDimArr[n][4]) ||
        (twoDimArr[n][0] == twoDimArr[n][1] && twoDimArr[n][1] == twoDimArr[n][2] &&
         twoDimArr[n][2] != twoDimArr[n][3] && twoDimArr[n][3] == twoDimArr[n][4])) {
        (*fullHouse)++;
        otherFlag = 0; }

    // 4er Pasch
    if ((twoDimArr[n][0] == twoDimArr[n][1] && twoDimArr[n][1] == twoDimArr[n][2] && twoDimArr[n][2] == twoDimArr[n][3]) ||
        (twoDimArr[n][1] == twoDimArr[n][2] && twoDimArr[n][2] == twoDimArr[n][3] && twoDimArr[n][3] == twoDimArr[n][4])) {
        (*quad)++;
        otherFlag = 0; }

    // 3er Pasch
    if ((twoDimArr[n][0] == twoDimArr[n][1] && twoDimArr[n][1] == twoDimArr[n][2]) ||
        (twoDimArr[n][1] == twoDimArr[n][2] && twoDimArr[n][2] == twoDimArr[n][3]) ||
        (twoDimArr[n][2] == twoDimArr[n][3] && twoDimArr[n][3] == twoDimArr[n][4])) {
        (*triple)++;
        otherFlag = 0; }

    // pair
    if ((twoDimArr[n][0] == twoDimArr[n][1] || twoDimArr[n][1] == twoDimArr[n][2] || twoDimArr[n][2] == twoDimArr[n][3] || twoDimArr[n][3] == twoDimArr[n][4])) {
        (*pair)++;
        otherFlag = 0; }

    // other
    if (otherFlag) {
        (*other)++;
    }   }

    